
//
// This is example code from Chapter 5.6.3 "Bad input " of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double some_function()
{
    double d = 0;
    cin >> d;
    if (!cin) error("couldn't read a double in 'some_function()'");
    // do something useful
}

//------------------------------------------------------------------------------

int main()
try {
    // our program
    some_function();
    return 0;    // 0 indicates success
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;    // 1 indicates failure
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;    // 2 indicates failure
}

//------------------------------------------------------------------------------
