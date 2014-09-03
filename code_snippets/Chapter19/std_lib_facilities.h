
//
// This is a standard library support code to the chapters of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef STD_LIB_FACILITIES_GUARD
#define STD_LIB_FACILITIES_GUARD 1

#include <cmath>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

//------------------------------------------------------------------------------

// Helper function to show an error message
inline void error(const string& errormessage)
{
    throw runtime_error(errormessage);
}

//------------------------------------------------------------------------------

#endif // STD_LIB_FACILITIES_GUARD
