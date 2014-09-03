
//
// This is example code from Chapter 10.6 "I/O error handling" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void fill_vector(istream& ist, vector<int>& v, char terminator)
// read integers from ist into v until we reach eof() or terminator
{
    int i = 0;
    while (ist >> i) v.push_back(i);
    if (ist.eof()) return;    // fine: we found the end of file

    if (ist.bad()) error("ist is bad"); // stream corrupted; let's get out of here!

    if (ist.fail()) {   // clean up the mess as best we can and report the problem
        ist.clear();    // clear stream state,
                        // so that we can look for terminator
        char c;
        ist>>c;         // read a character, hopefully terminator
        if (c != terminator) { // unexpected character
            ist.unget();       // put that character back
            ist.clear(ios_base::failbit); // set the state to fail()
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    vector<int> v;
    fill_vector(cin, v, '*');
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
