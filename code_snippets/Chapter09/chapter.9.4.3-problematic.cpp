
//
// This is example code from Chapter 9.4.3 "Keep details private" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

// simple Date:
// guarantee initialization with constructor
// provide some notational convenience
struct Date {
    int y, m, d;                // year, month, day 
    Date(int y, int m, int d);  // check for valid date and initialize
    void add_day(int n);        // increase the Date by n days
};

//------------------------------------------------------------------------------

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {}

int main()
{
    Date birthday(1960,12,31);  // December 31, 1960
    ++birthday.d;               // ouch! invalid date

    Date today(1970,2,3);
    today.m = 14;               // ouch! invalid date
}

//------------------------------------------------------------------------------
