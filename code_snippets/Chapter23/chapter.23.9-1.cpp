
//
// This is example code from Chapter 23.9 "Matching with regular expression" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    ifstream in("table.txt");    // input file
    if (!in) error("no input file\n");

    string line;    // input buffer
    int lineno = 0;

    regex header( "^[\\w ]+(	[\\w ]+)*$"); // header line
    regex row( "^[\\w ]+(	\\d+)(	\\d+)(	\\d+)$"); // data line

    if (getline(in,line)) {       // check header line
        smatch matches;
        if (!regex_search(line, matches, header))
            error("no header");
    }
    while (getline(in,line)) {    // check data line
        ++lineno;
        smatch matches;
        if (!regex_search(line, matches, row)) 
            error("bad line", lineno);
    }
}
catch (std::exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
