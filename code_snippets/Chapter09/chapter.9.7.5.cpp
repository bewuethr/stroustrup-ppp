
//
// This is example code from Chapter 9.7.5 "Members and "helper functions"" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) {}

    int day() const { return d; }
    Month month() const { return m; }
    int year() const { return y; }

private:
    int   y;                // year
    Month m;
    int   d;                // day of month
};

//------------------------------------------------------------------------------

//Here are some examples of helper functions:

Date next_Sunday(const Date& d)
{
    // access d using d.day(), d.month(), and d.year()
    // make new Date to return
    return d;
}

//------------------------------------------------------------------------------

Date next_weekday(const Date& d) { /* ... */ return d; }

//------------------------------------------------------------------------------

bool leapyear(int d, int m, int y) { /* ... */ return false; }

//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b)
{
    return a.year()==b.year()
        && a.month()==b.month()
        && a.day()==b.day();
}

//------------------------------------------------------------------------------

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}

//------------------------------------------------------------------------------

namespace Chrono {
    class Date { /* ... */ };
    Date next_Sunday(const Date& d) { /* ... */ return d; }
    Date next_weekday(const Date& d) { /* ... */ return d; }
    bool leapyear(int d, int m, int y) { /* ... */ return false; }        // See exercise ???
    bool operator==(const Date& a, const Date& b) { /* ... */ return false; }
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    Date d(2008,Date::feb,23);
    bool b = next_Sunday(d) != next_weekday(d);
    Chrono::Date dd;
    return 0;
}

//------------------------------------------------------------------------------
