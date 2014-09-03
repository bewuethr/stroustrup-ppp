
//
// This is example code from Chapter 9.5 "Enumerations" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

enum Month {
     // note dec changed to dcm to make it compile,see comment on p. 316
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dcm
};

//------------------------------------------------------------------------------

enum Day {
    monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

//------------------------------------------------------------------------------

void error(const char* errmsg)
{
    cerr << errmsg << endl;
}

//------------------------------------------------------------------------------

Month int_to_month(int x)
{
    if (x<jan || dcm<x) error("bad month");
    return Month(x);
}

//------------------------------------------------------------------------------

void f(int m)
{
    Month mm = int_to_month(m);
    // ...
}

//------------------------------------------------------------------------------

int main()
try
{
    Month m = feb;
    //m = 7;             // error: can't assign int to Month
    int n = m;           // ok: we can get the numeric value of a Month
    Month mm = Month(7); // convert int to Month (unchecked)

    //Month bad = 9999;  // error: can't convert an int to a Month
    f(4);
    f(99);               // run-time error: bad month
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
