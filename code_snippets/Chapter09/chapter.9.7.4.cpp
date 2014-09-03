
//
// This is example code from Chapter 9.7.4 "Const member functions" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) {}

    int   day()   const;         // const member: can't modify
    Month month() const;         // const member: can't modify
    int   year()  const;         // const member: can't modify

    void add_day(int n);         // non-const member: can modify
    void add_month(int n);       // non-const member: can modify
    void add_year(int n);        // non-const member: can modify
private:
    int   y;                     // year
    Month m;
    int   d;                     // day of month
};

//------------------------------------------------------------------------------

int Date::day() const
{
    //++d;        // error: attempt to change object from const member function
    return d;
}

//------------------------------------------------------------------------------

void Date::add_day(int n) {}

//------------------------------------------------------------------------------

void some_function(Date& d, const Date& start_of_term)
{
    int a = d.day();             // ok
    int b = start_of_term.day(); // should be ok (why?)
    d.add_day(3);                // fine
    //start_of_term.add_day(3);  // error
}

//------------------------------------------------------------------------------

int main()
{
    Date d(2000, Date::jan, 20);
    const Date cd(2001, Date::feb, 21);

    cout << d.day() << " - " << cd.day() << endl;        // ok
    d.add_day(1);                // ok
    //cd.add_day(1);             // error: cd is a const
    some_function(d,cd);
    //some_function(cd,d);       // error: cd is a const
    return 0;
}

//------------------------------------------------------------------------------
