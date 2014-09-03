
//
// This is example code from Chapter 24.8 "The standard Mathematical functions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <limits>
#include <cmath>
#include <cerrno>

using namespace std;

//------------------------------------------------------------------------------

const double very_large = std::numeric_limits<double>::max();

int main()
{
    errno = 0;
    double s2 = sqrt(-1.0);
    if (errno) cerr << "something went wrong with somewhere";
    if (errno == EDOM)    // domain error
        cerr << "sqrt() not defined for negative argument";
    pow(very_large,2);    // not a good idea
    if (errno==ERANGE)    // range error
        cerr << "pow(" << very_large << ",2) too large for a double";

}

//------------------------------------------------------------------------------
