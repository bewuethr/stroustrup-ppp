
//
// This is a standard library support code to the chapters of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef STD_LIB_FACILITIES_GUARD
#define STD_LIB_FACILITIES_GUARD 1

#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

//------------------------------------------------------------------------------

// Helper function to show an error message
inline void error(const string& errormessage)
{
    cerr << errormessage << endl;
    throw runtime_error(errormessage);
}

//------------------------------------------------------------------------------

inline void error(string s1, string s2)
{
    error(s1+s2);
}

//------------------------------------------------------------------------------

inline void error(string s1, int n)
{
    ostringstream os;
    os << n;
    error(s1, os.str());
}

//------------------------------------------------------------------------------

#endif // STD_LIB_FACILITIES_GUARD
