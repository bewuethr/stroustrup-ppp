
//
// This is example code from Chapter 8.4 "Scope" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void f(int x)       // f is global; x is local to f
{
    int z = x+7;    // z is local
}

//------------------------------------------------------------------------------

int g(int x)        // g is global; x is local to g
{
    int f = x+2;    // f is local
    return 2*f; 
}

//------------------------------------------------------------------------------

int max(int a, int b) // max is global; a and b are local
{
    return (a>=b) ? a : b;
}

//------------------------------------------------------------------------------

int my_abs(int a)     // not max()'s a
{
    return (a<0) ? -a : a;
}

//------------------------------------------------------------------------------

int max2(int a, int b) // max2 is global; a and b are local
{
    int m;            // m is local
    if (a>=b) 
        m = a;
    else
        m = b;
    return m;
}

//------------------------------------------------------------------------------

// no r, i, or v here
class My_vector {
    vector<int> v;    // v is in class scope
public:
    int largest()
    {
        int r = 0;    // r is local (smallest non-negative int)
        for (int i = 0; i<v.size(); ++i)
            r = max(r,my_abs(v[i]));    // i is in the  for's statement scope
        // no i here
        return r;
    }
    // no r here
};

//------------------------------------------------------------------------------
// no v here

int x;                // global variable - avoid those where you can
int y;

int f()
{
    int x;            // local variable
    x = 7;            // the local x
    {
        int x = y;    // local x initialized by global y
        ++x;          // the x from the previous line
    }
    ++x;              // the x from the first line of f()
    return x;
}

//------------------------------------------------------------------------------

class C {
public:
    void f();
    void g()          // a member function can be defined within its class
    { 
        // ...
    } 
    // ...
};

//------------------------------------------------------------------------------

void C::f()           // a member definition can be outside its class
{
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    f();
    return my_abs(max(f(),g(0)) - max2(f(),g(1)));
}

//------------------------------------------------------------------------------
