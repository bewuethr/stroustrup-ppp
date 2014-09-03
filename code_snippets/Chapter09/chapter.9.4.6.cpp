
//
// This is example code from Chapter 9.4.6 "Reporting errors" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// simple Date (prevent invalid dates):
class Date {
public:
    class Invalid { };         // to be used as exception
    Date(int y, int m, int d); // check for valid date and initialize
    int month() { return m; }
    int day()   { return d; }
    int year()  { return y; }
    void add_day(int n) { /*...*/ }

private:
    int y, m, d;               // year, month, day
    bool check();              // return true if date is valid
};

//------------------------------------------------------------------------------

Date::Date(int yy, int mm, int dd)
: y(yy), m(mm), d(dd)              // initialize data members
{
    if (!check()) throw Invalid(); // check for validity
}

//------------------------------------------------------------------------------

bool Date::check()  // return true if date is valid
{
    if (m<1 || 12<m) return false;
    // ...
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, Date& d)
{
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

//------------------------------------------------------------------------------

void error(const char* errmsg)
{
    cerr << errmsg << endl;
}

//------------------------------------------------------------------------------

void f(int x, int y)
try {
    Date dxy(2004,x,y);
    cout << dxy << '\n';       // see §9.2 for a declaration of <<
    dxy.add_day(2);
}
catch(Date::Invalid) {
    error("invalid date");
}

//------------------------------------------------------------------------------

int main()
try
{
    f(8,29);
    f(15,29);                  // run-time error: invalid date
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
