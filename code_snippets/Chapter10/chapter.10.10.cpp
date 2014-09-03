
//
// This is example code from Chapter 10.10 "A standard input loop" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

typedef int My_type;

//------------------------------------------------------------------------------

void input_loop_1(istream& ist)
{  
    My_type var;
    while (ist>>var) {    // read until end of file
        // maybe check that var is valid
        // do something with var
    }
    // we can rarely recover from bad; don't try unless you really have to:
    if (ist.bad()) error("bad input stream");
    if (ist.fail()) {
        // was it an acceptable terminator?
    }
    // carry on: we found end of file
}

//------------------------------------------------------------------------------

void input_loop_2(istream& ist)
{  
    My_type var;
    while (ist>>var) {    // read until end of file
        // maybe check that var is valid
        // do something with var
    }
    if (ist.fail()) { // use '|' as terminator and/or separator
        ist.clear();
        char ch;
        if (!(ist>>ch && ch=='|')) error("bad termination of input");
    }
    // carry on: we found end of file or a terminator
}

//------------------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail()) { // use term as terminator and/or separator
        ist.clear();
        char ch;
        if (ist>>ch && ch==term) return;    // all is fine
        error(message);
    }
}

//------------------------------------------------------------------------------

void input_loop_3(istream& ist)
{  
    My_type var;
    while (ist>>var) {    // read until end of file
        // maybe check that var is valid
        // do something with var
    }
    end_of_loop(ist,'|',"bad termination of file");    // test if we can continue
    // carry on: we found end of file or a terminator
}

//------------------------------------------------------------------------------

int main()
try
{
    input_loop_3(cin);
    input_loop_2(cin);
    input_loop_1(cin);
    // Somewhere: make ist throw an exception if it goes bad:
    cin.exceptions(cin.exceptions()|ios_base::badbit);
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
