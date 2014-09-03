
//
// This is example code from Chapter 2.3 "Compilation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

                                // error: no #include here
// #include "std_facilities.h"  // error: unable to locate header file
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

//integer main()                // error: unknown type integer
int main()
{
    //cout << "Hello, World!\n; // error: unterminated string constant
    //cout <  "Hello, World!\n";// error: no operator < defined
    //cout << 'Hello, World!\n';// error: invalid delimiter for strings
    //cout << "Hello, World!\n" // error: no semicolon
    cout << "Hello, World!\n";
    return 0;
}

//------------------------------------------------------------------------------
