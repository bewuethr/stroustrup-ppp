
//
// This is example code from Chapter 4.4.1.1 "If-statements" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// convert from inches to cm or cm to inches.
// a suffix 'i' or 'c' indicates the unit of the input

int main()
{
    const double cm_per_inch = 2.54;    // number of centimeters in an inch
    int length = 1;                // length in inches or centimeters
    char unit = 0;
    cout<< "Please enter a length followed by a unit (c or i):\n";
    cin >> length >> unit;

    if (unit == 'i')
        cout << length << "in == " << cm_per_inch*length << "cm\n";
    else 
        cout << length << "cm == " << length/cm_per_inch << "in\n";
}

//------------------------------------------------------------------------------
