
//
// This is example code from Chapter 9.4.2 "Member functions and constructors" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// simple Date (too simple?):
struct Date {
    int y; // year
    int m; // month in year
    int d; // day of month
};

//------------------------------------------------------------------------------

// helper functions:

void init_day(Date& dd, int y, int m, int d)
{
    // check that (y,m,d) is a valid date
    // if it is, use it to initialize dd
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

//------------------------------------------------------------------------------

void f()
{
    Date today;
    // ...
    cout << today << '\n';         // use today
    // ...
    init_day(today, 12, 24, 2005); // oops! (no day 2005 in year 12) 
    // ...
    Date tomorrow;
    tomorrow.y = today.y;
    tomorrow.m = today.m;
    tomorrow.d = today.d+1;        // add 1 to today
    cout << tomorrow << '\n';      // use tomorrow
}

//------------------------------------------------------------------------------

int main()
{
    f();
    return 0;
}

//------------------------------------------------------------------------------
