
//
// This is example code from Chapter 10.6 "I/O error handling" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

int main()
try
{
    int i = 0;
    cin >> i;
    if (!cin) {    // we get here (only) if an input operation failed
        if (cin.bad()) error("cin is bad"); // stream corrupted: let's get out of here!
        if (cin.eof()) {
            // no more input 
            // this is often how we want a sequence of input operations to end
        }
        if (cin.fail()) {   // stream encountered something unexpected
            cin.clear();    // make ready for more input
            // somehow recover 
        }
    }
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
