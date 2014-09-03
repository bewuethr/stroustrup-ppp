
//
// This is example code from Chapter 8.6.2 "Global initialization" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

struct Date
{
    Date(int y, int m, int d) { /*...*/ }
};

//------------------------------------------------------------------------------

namespace good
{
    const Date default_date(1970,1,1);    // the default date is January 1 1970.
}

//------------------------------------------------------------------------------

namespace better
{
    const Date default_date()             // return the default Date
    {
        return Date(1970,1,1);
    }
}

//------------------------------------------------------------------------------

namespace best
{
    const Date& default_date()
    {
        static const Date dd(1970,1,1);   // initialize dd first time we get here
        return dd;
    }
}

//------------------------------------------------------------------------------

int main()
{
    Date d1 = good::default_date;
    Date d2 = better::default_date();
    Date d3 = best::default_date();
}

//------------------------------------------------------------------------------
