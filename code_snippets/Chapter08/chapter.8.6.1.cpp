
//
// This is example code from Chapter 8.6.1 "Expression evaluation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

vector<int> v(10);                   // v is global

void f(int i, int j)
{
    cout << i << ' ' << j << '\n';
}

//------------------------------------------------------------------------------

int main()
{
    int i = 4;
    v[i] = ++i;                      // don't: undefined order of evaluation
    v[++i] = i;                      // don't: undefined order of evaluation
    int x = ++i + ++i;               // don't: undefined order of evaluation
    cout << ++i << ' ' << i << '\n'; // don't: undefined order of evaluation
    f(++i,++i);                      // don't: undefined order of evaluation
}

//------------------------------------------------------------------------------
