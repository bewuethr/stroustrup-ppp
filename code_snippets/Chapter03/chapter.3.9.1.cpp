
//
// This is example code from Chapter 3.9.1 "Safe conversions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    char c = 'x';
    int i1 = c;
    int i2 = 'x';
    char c2 = i1;

    cout << c << ' ' << i1 << ' ' << c2 << '\n'; // This will print: x 120 x

    double d1 = 2.3;
    double d2 = d1+2; // 2 is converted to 2.0 before adding

    if (d1 < 0)       // 0 is converted to 0.0 before comparison
        error("d1 is negative");
}

//------------------------------------------------------------------------------
