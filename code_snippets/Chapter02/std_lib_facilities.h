
//
// This is a standard library support code to the chapters of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef STD_LIB_FACILITIES_GUARD
#define STD_LIB_FACILITIES_GUARD 1

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// The call to keep_window_open() is needed on some Windows machines to prevent
// them from closing the window before you have a chance to read the output. 
inline void keep_window_open()
{
    cin.get();
}

//------------------------------------------------------------------------------

#endif // STD_LIB_FACILITIES_GUARD
