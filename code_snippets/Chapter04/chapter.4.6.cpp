
//
// This is example code from Chapter 4.6 "Vector" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    vector<int> v(6); // vector of 6 ints

    v[0] = 5; 
    v[1] = 7;
    v[2] = 9;
    v[3] = 4;
    v[4] = 6;
    v[5] = 8;


    vector<string> philosopher(4); // vector of 4 strings

    philosopher [0] = "Kant"; 
    philosopher [1] = "Plato";
    philosopher [2] = "Hume";
    philosopher [3] = "Kierkegaard";

    //philosopher[2] = 99;    // error: trying to assign an int to a string
    //v[2] = "Hume";          // error: trying to assign a string to an int

    vector<double> vd(1000,-1.2); // vector of 1000 doubles initialized to -1.2

    //vd[20000] = 4.7;        // run-time error
}

//------------------------------------------------------------------------------
