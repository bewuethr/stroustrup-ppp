
//
// This is example code from Chapter 6.3.1 "First attempt" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    cout << "Please enter expression (we can handle + and -): ";
    int lval = 0;
    int rval;
    char op;
    int res;
    cin>>lval>>op>>rval;      // read something like  1 + 3

    if (op=='+')
        res = lval + rval;    // addition
    else if (op=='-')
        res = lval - rval;    // subtraction

    cout << "Result: " << res << '\n';
    keep_window_open();
    return 0;
}

//------------------------------------------------------------------------------
