
//
// This is example code from Chapter 8.5.5 "Call by reference" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int g(int& x);
int f(int& x);

void h(int x, int y)
{
    int i = 7; 
    int& r = i;    // r is a reference to i
    r = 9;         // i becomes 9
    i = 10;
    cout << r << ' ' << i << '\n'; // write: 10 10

    vector< vector<double> > v;    // vector of vector of double

    double val = v[f(x)][g(y)];    // val is the value of v[f(x)][g(y)]
    double& var = v[f(x)][g(y)];   // var is a reference to v[f(x)][g(y)]

    var = var/2+sqrt(var);
}

//------------------------------------------------------------------------------

// call-by-reference (let the function refer back to the variable passed)
int f(int& x)
{
    x = x+1;
    return x;
}

//------------------------------------------------------------------------------

int main()
{
    int xx = 0;
    cout << f(xx) << endl;         // write: 1
    cout << xx << endl;            // write: 1;  f() changes the value of xx

    int yy = 7;
    cout << f(yy) << endl;         // write: 8
    cout << yy << endl;            // write: 8; f() changes the value of yy
}

//------------------------------------------------------------------------------

int g(int& x)
{
    x = x+1;
    return x;
}

//------------------------------------------------------------------------------
