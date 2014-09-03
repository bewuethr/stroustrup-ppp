
//
// This is example code from Chapter 8.4 "Scope" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void f()
{
    //g();       // error: g() isn't (yet) in scope
}

//------------------------------------------------------------------------------

void g()
{
    f();         // ok: f() is in scope
}

//------------------------------------------------------------------------------

void h()
{
    //int x = y; // error: y isn't (yet) in scope
    int x = 0;
    int y = x;   // ok: x is in scope
    g();         // ok: g() is in scope
}

//------------------------------------------------------------------------------

int main()
{
    h();
}

//------------------------------------------------------------------------------
