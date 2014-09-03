
//
// This is example code from Chapter 8.5.5 "Call by reference" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void swap(double& d1, double& d2)
{
    double temp = d1; // copy d1's value to temp
    d1 = d2;          // copy d2's value to d2
    d2 = temp;        // copy d1's old value to d2
}

//------------------------------------------------------------------------------

int main()
{
    double x = 1;
    double y = 2; 
    cout << "x == " << x << " y== " << y << '\n';    // write: x==1 y==2
    swap(x,y);
    cout << "x == " << x << " y== " << y << '\n';    // write: x==2 y==1
}

//------------------------------------------------------------------------------
