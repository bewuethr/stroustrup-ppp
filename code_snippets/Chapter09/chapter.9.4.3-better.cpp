
//
// This is example code from Chapter 9.4.3 "Keep details private" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// simple Date (control access):
class Date {
    int y, m, d;                      // year, month, day
public:
    Date(int y, int m, int d);        // check for valid date and initialize
    void add_day(int n);              // increase the Date by n days
    int month() { return m; }
    int day()   { return d; }
    int year()  { return y; }
};

//------------------------------------------------------------------------------

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {}

//------------------------------------------------------------------------------

int main()
{
    Date birthday(1970, 12, 30);      // ok
    //birthday.m = 14;                // error: Date::m is private
    cout << birthday.month() << endl; // we  provided a way to read m
}

//------------------------------------------------------------------------------
