
//
// This is example code from Chapter 9.8 "The Date class" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

namespace Chrono {

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    class Invalid { };                 // to throw as exception

    Date(int y, Month m, int d);       // check for valid date and initialize
    Date();                            // default constructor
    // the default copy operations are fine

    // non-modifying operations:
    int   day()   const { return d; }
    Month month() const { return m; }
    int   year()  const { return y; }

    // modifying operations:
    void add_day(int n);        
    void add_month(int n);
    void add_year(int n);
private:
    int   y;
    Month m;
    int   d;
};

//------------------------------------------------------------------------------

bool is_date(int y, Date::Month m, int d); // true for valid date

//------------------------------------------------------------------------------

bool leapyear(int y);                  // true if y is a leap year

//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(istream& is, Date& dd);

//------------------------------------------------------------------------------

} // Chrono
