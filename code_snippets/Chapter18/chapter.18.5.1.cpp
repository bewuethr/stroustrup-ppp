
//
// This is example code from Chapter 18.5.1 "Pointers to array elements" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    double ad[10];
    double* p = &ad[5]; // point to ad[5]

    *p =7;
    p[2] = 6;
    p[-3] = 9;

    p += 2;             // move p two elements to the right
    p -= 5;             // move p five elements to the left
    p += 1000;          // insane: p points into an array with just 10 elements
    double d = *p;      // illegal: probably a bad value
                        //            (definitely an unpredictable value)
    *p = 12.34;         // illegal: probably scrambles some unknown data

    for (double* p = &ad[0]; p<&ad[10]; ++p) cout << *p << '\n';

    // Or backwards:

    for (double* p = &ad[9]; p>=&ad[0]; --p) cout << *p << '\n';

    double* p1 = &ad[0];
    double* p2 = p1+7;
    double* p3 = &p1[7];
    if (p2 != p3) cout << "impossible!\n";
}

//------------------------------------------------------------------------------
