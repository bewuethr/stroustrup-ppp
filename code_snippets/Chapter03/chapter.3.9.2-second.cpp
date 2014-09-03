
//
// This is example code from Chapter 3.9.2 "Unsafe conversions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    double d =0;
    while (cin>>d) {   // repeat the statements below
                       // as long as we type in numbers
        int i = d;     // try to squeeze a double into an int
        char c = i;    // try to squeeze an int into a char
        int i2 = c;    // get the integer value of the character
        cout << "d==" << d              // the original double
             << " i=="<< i              // converted to int
             << " i2==" << i2           // int value of char 
             << " char(" << c << ")\n"; // the char
    }

    double x = 2.7;
    // lots of code
    int y = x;         // y becomes 2
    int a = 1000;
    char b = a;        // b becomes -24 (on some machines)
}

//------------------------------------------------------------------------------
