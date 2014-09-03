
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

    // not good() and not bad() and not eof(), ist must be fail()
    ist.clear();              // clear stream state
    char c;
    ist>>c;                   // read a character, hopefully terminator

    if (c != terminator) {    // ouch: not the terminator, so we must fail
        ist.unget();          // maybe my caller can use that character
        ist.clear(ios_base::failbit); // set the state to fail()
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    // make cin throw if it goes bad:
    cin.exceptions(cin.exceptions()|ios_base::badbit);

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
