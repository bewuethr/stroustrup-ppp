
//
// This is example code from Chapter 27.6.2 "Input" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------------------------

void f()
{
    int i;
    char c;
    double d;
    char* s = (char*)malloc(100);
    /* read into variables passed as pointers: */
    scanf("%i %c %lg %s", &i, &c, &d, s);
    /* %s skips initial whitespace and is terminated by whitespace */
    printf("%i %c %lg %s", i, c, d, s);
}

//------------------------------------------------------------------------------

int main()
{
    f();

    // The simplest way of reading a string of character is using gets(). For example:

    char a[12];
    gets(a);    /* read into char array pointed to by a until a '\n' is input */

    string s;
    cin >> s;    // read a word
    getline(cin,s);    // read a line

    char buf[20];
    scanf("%19s",buf);

    int x;
    while((x=getchar())!=EOF) {
        /* ... */ 
    }
}

//------------------------------------------------------------------------------
