
//
// This is example code from Chapter 11.2.3 "Floating-point output" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    cout << 1234.56789 << "\t\t(general)\n"  //  \t\t  to line up columns 
         << fixed << 1234.56789 << "\t(fixed)\n"
         << scientific << 1234.56789 << "\t(scientific)\n";

    cout << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
    cout << 1234.56789 << '\n';              // floating-format "sticks"
    cout << general << 1234.56789 << '\t'    // warning: general isn't standard
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
}

//------------------------------------------------------------------------------
