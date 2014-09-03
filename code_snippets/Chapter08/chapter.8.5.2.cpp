
//
// This is example code from Chapter 8.5.2 "Returning a value" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

typedef int T;
typedef double V;

T f()                  // f() returns a T
{
    V v;
    // ...
    return v;
}

//------------------------------------------------------------------------------

int main()
{
    T x = f();
    V v;
    // ...
    T t(v);             // initialize t with v

}

//------------------------------------------------------------------------------

double my_abs(int x)    // warning: buggy code
{
    if (x < 0)
        return -x;
    else if (x> 0)
        return x;
}    // error: no value returned if x is 0

void print_until_s(const vector<string> v, const string quit)
{
    for(int i=0; i<v.size(); ++i) {
        if (v[i]==quit) return;
        cout << v[i] << '\n';
    }
}

//------------------------------------------------------------------------------
