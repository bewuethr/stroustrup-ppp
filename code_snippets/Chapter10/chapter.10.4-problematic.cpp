
//
// This is example code from Chapter 10.4 "Opening a file" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <fstream>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

int main()
try
{
    ifstream ifs;
    const char* name = "chapter.10.4-problematic.cpp";
    // ...
    string   foo;
    ifs >> foo;                    // won't succeed: no file opened for ifs
    // ...
    ifs.open(name,ios_base::in);   // open file named name for reading
    // ...
    ifs.close();                   // close file
    // ...
    string   bar;
    ifs >> bar;                    // won't succeed: ifs' file was closed
    // ...

    ifs.open("foo", ios_base::in); // open for input
    // close() missing
    ifs.open("foo", ios_base::in); // won't succeed: ifs is already open
    if (ifs) error("impossible");
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
