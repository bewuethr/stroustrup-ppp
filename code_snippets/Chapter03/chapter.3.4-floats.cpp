
//
// This is example code from Chapter 3.4 "Operations and operators" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// simple program to exercise operators
int main()
{
    cout << "please enter a floating-point value: ";
    double n;
    cin >> n;    
    cout << "n == " << n
         << "\nn+1 == " << n+1
         << "\nthree times n == " << 3*n
         << "\ntwice n == " << n+n
         << "\nn squared == " << n*n
         << "\nhalf of n == " << n/2
         << "\nsquare root of n == " << sqrt(n)
         << endl; // another name for newline ("end of line")
}

//------------------------------------------------------------------------------
