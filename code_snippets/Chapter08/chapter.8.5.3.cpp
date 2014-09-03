
//
// This is example code from Chapter 8.5.3 "Call by value" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------


// call-by-value (give the function a copy of the value passed)
int f(int x)
{
    x = x+1;                    // give the local x a new value
    return x;
}

//------------------------------------------------------------------------------

int main()
{
    int xx = 0;
    cout << f(xx) << endl;      // write: 1
    cout << xx << endl;         // write: 0; f() doesn't change xx

    int yy = 7;
    cout << f(yy) << endl;      // write: 8
    cout << yy << endl;         // write: 7; f() doesn't change yy
}

//------------------------------------------------------------------------------
