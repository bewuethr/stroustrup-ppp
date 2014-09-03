
//
// This is example code from Chapter 9.4.4 "Defining member functions" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

// simple Date (some people prefer implementation details last)
class Date {
public:
    Date(int y, int m, int d); // constructor: check for valid date and initialize
    void add_day(int n);       // increase the Date by n days
    int month() { return m; }
    // ...
private:
    int y, m, d;               // year, month, day
};

//------------------------------------------------------------------------------

Date::Date(int yy, int mm, int dd) // constructor
        :y(yy), m(mm), d(dd)       // note: member initializers
{
}

//------------------------------------------------------------------------------

void Date::add_day(int n)
{ 
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    {
        int x;              // first define the variable x
        // ...
        x = 2;              // later assign to x
    }

    {
        int x = 2;          // define and immediately initialize with 2
    }

    {
        int x(2);           // initialize x with 2
    }

    Date sunday(2004,8,29); // initialize sunday with (2004,8,29)

    sunday.add_day(7);      // skip 7 days
    return sunday.month();  // get sunday's month
}

//------------------------------------------------------------------------------
