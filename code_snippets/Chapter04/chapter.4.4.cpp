
//
// This is example code from Chapter 4.4 "Statements" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int a = 7;
    int b = 4;

    a = b;
    ++b;
    //a = b ++ b;    // syntax error: missing semicolons
    cout << a << '\n';
    1+2;    // do an addition, but don't use the sum
    a*b;    // do a multiplication, but don't use the product

    int x = 1;
    int y = 5;

    if (x == 5);
    { y = 3; }

    cout << y << '\n';
}

//------------------------------------------------------------------------------
