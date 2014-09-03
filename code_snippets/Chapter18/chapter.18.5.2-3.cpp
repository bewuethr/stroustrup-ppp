
//
// This is example code from Chapter 18.5.2 "Pointers and arrays" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// The name of an array refers to all the elements of the array. Consider:
char ch[100];
char* p = ch; // Here p is initialized to &ch[0].

//------------------------------------------------------------------------------

int main()
{
    //ch = new char [20];        // error: no assignment to array name
    //&ch[0] = new char [20];    // error: no assignment to pointer value

    int x[100];
    int y[100];
    // ...
    //x = y;          // error
    //int z[100] = y; // error

    for (int i=0; i<100; ++i) x[i]=y[i]; // copy 100 ints
    memcpy(x,y,100*sizeof(int));         // copy 100*sizeof(int) bytes
    copy(y,y+100, x);                    // copy 100 ints

    // If we want assignment, we have to use something like vector
    {
        vector<int> x(100);
        vector<int> y(100);
        // ...
        x = y;                           // copy 100 ints
    }
}

//------------------------------------------------------------------------------
