
//
// This is example code from Chapter 9.7.1 "Argument types" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

class Year {        // year in [min:max) range
    static const int min = 1800;
    static const int max = 2200;
public:
    class Invalid { };
    Year(int x) : y(x) { if (x<min || max<x) throw Invalid(); }
    int year() { return y; }
private:
    int y;
};

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(Year yy, Month mm, int dd) : y(yy), m(mm), d(dd) // check for valid date and initialize
    {
        // ...
    }

    // ...
private:
    Year y;
    Month m;
    int d;   // day
};

//------------------------------------------------------------------------------

int main()
try
{
    //Date dx1(Year(1998), 4, 3);         // error: 2nd argument not a Month
    //Date dx2(Year(1998), 4, Date::mar); // error: 2nd argument not a Month
    //Date dx2(4, Date::mar, Year(1998)); // error: 1st argument not a Year
    //Date dx2(Date::mar, 4, Year(1998)); // error: 2nd argument not a Month
    Date dx3(Year(1998), Date::mar, 30);  // ok

    //This weird and unlikely error would still not be caught until run-time:
    Date dx5(Year(4), Date::mar, 1998);   //  run-time error: Year::Invalid
}
catch (Year::Invalid&) {
    cerr << "error: Invalid year\n"; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
