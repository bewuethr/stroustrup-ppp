
//
// This is example code from Chapter 6.3.1 "First attempt" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Please enter expression (we can handle +, -, *, and /): ";
    int lval = 0;
    int rval;
    char op;
    cin>>lval;               // read leftmost operand
    if (!cin) error("no first operand");
    while (cin>>op) {        // read operator and right-hand operand repeatedly
        cin>>rval;
        if (!cin) error("no second operand");
        switch(op) {
        case '+':
            lval += rval;    // add: lval = lval + rval
            break;
        case '-':
            lval -= rval;    // subtract: lval = lval - rval
            break;
        case '*':
            lval *= rval;    // multiply: lval = lval * rval
            break;
        case '/':
            lval /= rval;    // divide: lval = lval / rval
            break;
        default:             // not another operator: print result
            cout << "Result: " << lval << '\n';
            keep_window_open();
            return 0;
        }
    }
    error("bad expression");
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
