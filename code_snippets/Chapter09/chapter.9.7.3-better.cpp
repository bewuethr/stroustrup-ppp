
//
// This is example code from Chapter 9.7.3 "Default constructors" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date();                         // default constructor
    Date(int yy, Month mm, int dd); // constructor
    Month month() const { return m; }
    int   day()   const { return d; }
    int   year()  const { return y; }

private:
    int   y;
    Month m;
    int   d;
};

//------------------------------------------------------------------------------

const Date& default_date()
{
    static const Date dd(2001,Date::jan,1);
    return dd;
}

//------------------------------------------------------------------------------

Date::Date() :
     y(default_date().year()),
     m(default_date().month()),
     d(default_date().day())
{
}

//------------------------------------------------------------------------------

Date::Date(int yy, Month mm, int dd) :
     y(yy), m(mm), d(dd)
{
}

//------------------------------------------------------------------------------

int main()
{
    vector<Date> birthdays(10);

    // Without the default constructor, we would have had to be explicit:
    {
        vector<Date> birthdays(10,default_date());
    }
    return 0;
}

//------------------------------------------------------------------------------
