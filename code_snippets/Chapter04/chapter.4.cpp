//
// This is example code from Chapter 4 "Computation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int square(int x) // return the square of x
{
    return x*x;
}

//------------------------------------------------------------------------------

// calculate and print a table of squares 0-99
int main()
{
    int i = 0;    // start from 0
    while (i<100) {
        cout << i << '\t' << square(i) << '\n';
        ++i ;     // increment i (that is, i becomes i+1)
    }
}

//------------------------------------------------------------------------------
