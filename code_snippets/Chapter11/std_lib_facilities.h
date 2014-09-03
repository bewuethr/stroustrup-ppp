
//
// This is a standard library support code to the chapters of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef STD_LIB_FACILITIES_GUARD
#define STD_LIB_FACILITIES_GUARD 1

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

// The call to keep_window_open() is needed on some Windows machines to prevent
// them from closing the window before you have a chance to read the output. 
inline void keep_window_open()
{
    cin.get();
}

//------------------------------------------------------------------------------

inline void keep_window_open(const string& str)
{
    static int attempts = 10; // Maximum number of attempts before forceful exit

    while (--attempts)
    {
        cout << "Please enter " << str << " to exit" << endl;

        bool exit = true;

        for(string::const_iterator p = str.begin(); p != str.end(); ++p)
            if (*p != cin.get())
            {
                exit = false;
                break;
            }

         if (exit)
             break;
    }
}

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

template <typename Target, typename Source>
Target narrow_cast(Source src)
{
    Target tgt = src;

    if ((Source)tgt != src)
        error("Invalid narrowing conversion");

    return tgt;
}

//------------------------------------------------------------------------------

inline ios_base& general(ios_base& b)    // to complement fixed and scientific
{
    b.setf(ios_base::fmtflags(0), ios_base::floatfield);
    return b;
}

//------------------------------------------------------------------------------

#endif // STD_LIB_FACILITIES_GUARD

