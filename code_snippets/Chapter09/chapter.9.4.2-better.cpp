
//
// This is example code from Chapter 9.4.2 "Member functions and constructors" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

// simple Date:
// guarantee initialization with constructor
// provide some notational convenience
struct Date {
    int y, m, d;                        // year, month, day 
    Date(int y, int m, int d);          // check for valid date and initialize
    void add_day(int n);                // increase the Date by n days
};

//------------------------------------------------------------------------------

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {}
void Date::add_day(int n) {}

//------------------------------------------------------------------------------

int main()
{
    //Date my_birthday;                 // error: my_birthday not initialized
    Date today(12,24,2007);             // oops! run-time error 
    Date last(2000, 12, 31);            // ok (colloquial style)
    Date christmas = Date(1976,12,24);  // also ok (verbose style)

    //We can now try to use our newly defined variables:

    last.add_day(1);
    //add_day(2);                       // error: what day?
}

//------------------------------------------------------------------------------
