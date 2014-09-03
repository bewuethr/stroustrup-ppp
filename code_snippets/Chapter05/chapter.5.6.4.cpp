
//
// This is example code from Chapter 5.6.4 "Narrowing errors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    int x = 2.9;
    char c = 2000;

    int x1 = narrow_cast<int>(2.9);       // throws
    int x2 = narrow_cast<int>(2.0);       // ok
    char c1 = narrow_cast<char>(2000);    // throws
    char c2 = narrow_cast<char>(85);      // ok
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
