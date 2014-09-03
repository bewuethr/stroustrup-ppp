
//
// This is example code from Chapter 27.4 "Free store" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//------------------------------------------------------------------------------

struct Pair {
    const char* p;
    int val;
};

//------------------------------------------------------------------------------

struct X { int x; };

//------------------------------------------------------------------------------

void quit() { exit(0); }

//------------------------------------------------------------------------------

int main()
{
    struct Pair p2 = {"apple",78};
    struct Pair* pp = (struct Pair*) malloc(sizeof(Pair));    /* allocate */
    pp->p = "pear";    /* initialize */
    pp->val = 42;

    // Note that we cannot write
    // *pp = {"pear", 42};
    // in either C or C++. However, in C++, we would define a constructor for Pair and write
    // Pair* pp = new Pair("pear", 42);

    int  n = 10;
    int  m = 20;

#ifndef __cplusplus
    int* p = malloc(sizeof(int)*n); /* avoid this */

    p = malloc(sizeof(char)*m);     /* probably a bug  - not room for m ints */
#endif

    {
        int* p = new int[200];
        // ...
        free(p);    // error

        X* q = (X*)malloc(n*sizeof(X));
        // ...
        delete q;   // error
    }

    int max = 1000; 
    int count = 0;
    int c;
    char* p = (char*)malloc(max);
    while ((c=getchar())!=EOF) {  /* read: ignore chars on eof line */
        if (count==max-1) {       /* need to expand buffer */
            max += max;           /* double the buffer size */
            p = (char*)realloc(p,max);
            if (p==0) quit();
        }
        p[count++] = c;
    }

    // Using the C++ standard library, the equivalent code is:
    {
        vector<char> buf;
        char c;
        while (cin.get(c)) buf.push_back(c);
    }
}

//------------------------------------------------------------------------------
