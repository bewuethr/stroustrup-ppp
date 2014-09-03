
//
// This is example code from Chapter 8.2.2 "Variable and constant declarations" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"     // we find the declaration of cout in here

//------------------------------------------------------------------------------

int main()
{
    int a;               // no initializer
    double d = 7;        // initializer using the = syntax
    vector<int> vi(10);  // initializer using the () syntax

    const int x = 7;     // initializer using the = syntax
    const int x2(9);     // initializer using the () syntax
    //const int y;       // error: no initializer
}

//------------------------------------------------------------------------------

namespace innocent
{
    void f(int z)
    {
        int x;           // uninitialized
        // ... no assignment to x here ...
        x = 7;           // give x a value
        // ...
    }
}

//------------------------------------------------------------------------------

namespace dangerous
{
    void f(int z)
    {
        int x;           // uninitialized
        // ... no assignment to x here ...
        if (z>x) {    
            // ...
        }
        // ...
        x = 7;           // give x a value
        // ...
    }
}

//------------------------------------------------------------------------------
