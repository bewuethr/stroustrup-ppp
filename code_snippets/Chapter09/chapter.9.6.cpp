
//
// This is example code from Chapter 9.6 "Operator overloading" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

enum Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dcm
};

//------------------------------------------------------------------------------

Month operator++(Month& m)                       // prefix increment operator
{
    m = (m==dcm) ? jan : Month(m+1);             // "wrap around"
    return m;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, Month m)
{
    static const char* month_tbl[12] = {
        "January","February","March","April","May","June","July",
        "August","September","October","November","December"
    };
    return os << month_tbl[m-1];
}

//------------------------------------------------------------------------------

class Vector {};

//int operator+(int,int);        // error: you can't overload built-in +
Vector operator+(const Vector&, const Vector &); // ok 
Vector operator+=(const Vector&, int);           // ok

//------------------------------------------------------------------------------

int main()
{
    Month m = sep;
    ++m;                // m becomes oct
    ++m;                // m becomes nov
    ++m;                // m becomes dec
    ++m;                // m becomes jan ("wrap around")
    cout << m << endl;
    return 0;
}

//------------------------------------------------------------------------------
