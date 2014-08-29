#include "Chrono.h"

namespace Chrono {

    // member function definitions:

    //------------------------------------------------------------------------------

    Date::Date(int yy, Month mm, int dd)
        : y(yy), m(mm), d(dd)
    {
        if (!is_date(yy,mm,dd)) throw Invalid();
    }

    //------------------------------------------------------------------------------

    const Date& default_date()
    {
        static const Date dd(2001,Date::jan,1); // start of 21st century
        return dd;
    }

    //------------------------------------------------------------------------------

    Date::Date()
        :y(default_date().year()),
        m(default_date().month()),
        d(default_date().day())
    {
    }

    //------------------------------------------------------------------------------

    void Date::add_day(int n)
    {
        // ...
    }

    //------------------------------------------------------------------------------

    void Date::add_month(int n)
    {
        // ...
    }

    //------------------------------------------------------------------------------

    void Date::add_year(int n)
    {
        if (m==feb && d==29 && !leapyear(y+n)) {    // beware of leap years!
            m = mar;                                // use March 1 instead of February 29
            d = 1;
        }
        y+=n;
    }

    //------------------------------------------------------------------------------

    // helper functions:

    bool is_date(int y, Date::Month m, int d)
    {
        // assume that y is valid

        if (d<=0) return false;     // d must be positive

        int days_in_month = 31;     // most months have 31 days

        switch (m) {
        case Date::feb:             // the length of February varies
            days_in_month = (leapyear(y)) ? 29 : 28;
            break;
        case Date::apr: case Date::jun: case Date::sep: case Date::nov:
            days_in_month = 30;     // the rest have 30 days
            break;
        }

        if (days_in_month<d) return false;

        return true;
    }

    //------------------------------------------------------------------------------

    // a leap year is disivible by 4, but not by 100, except if it is divisible by 400
    bool leapyear(int y)
    {
        return (y%4==0 && y%100!=0) || y%400==0;
    }

    //------------------------------------------------------------------------------

    bool operator==(const Date& a, const Date& b)
    {
        return a.year()==b.year()
            && a.month()==b.month()
            && a.day()==b.day();
    }

    //------------------------------------------------------------------------------

    bool operator!=(const Date& a,const Date& b)
    {
        return !(a==b);
    }

    //------------------------------------------------------------------------------

    ostream& operator<<(ostream& os, const Date& d)
    {
        return os << '(' << d.year()
            << ',' << d.month()
            << ',' << d.day()
            << ')';
    }

    //------------------------------------------------------------------------------

    istream& operator>>(istream& is, Date& dd)
    {
        int y ,m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if (!is) return is;
        if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') { // oops: format error
            is.clear(ios_base::failbit);                    // set the fail bit
            return is;
        }
        dd = Date(y,Date::Month(m),d);     // update dd
        return is;
    }

    //------------------------------------------------------------------------------

    ostream& operator<<(ostream& os, Day d)
    {
        switch (d) {
        case sunday:
            os << "Sunday";
            break;
        case monday:
            os << "Monday";
            break;
        case tuesday:
            os << "Tuesday";
            break;
        case wednesday:
            os << "Wednesday";
            break;
        case thursday:
            os << "Thursday";
            break;
        case friday:
            os << "Friday";
            break;
        case saturday:
            os << "Saturday";
            break;
        }
        return os;
    }

    //------------------------------------------------------------------------------
    const Date first_date = Date(1970,Date::jan,1); // day 0 for linear representation of Date
    const Day first_day = thursday;            // Jan 1, 1970 was a Thursday

    Day day_of_week(const Date& d)
    {
        if (d.year() < first_date.year()) error("day_of_week: works only for 1970 and later");
        int dlin = days_linear(d);
        return Day((first_day + dlin) % 7);
    }

    //------------------------------------------------------------------------------

    Date next_Sunday(const Date& d)
    {
        Date nsd = d;
        Day day = day_of_week(d);
        nsd.add_day(7-day);
        return nsd;
    }

    // number of days in the year before Month m, ignoring leap years
    int nmonth(Date::Month m)
    {
        switch (m) {
        case Date::jan: return 0;
        case Date::feb: return 31;
        case Date::mar: return 31+28;
        case Date::apr: return 31+28+31;
        case Date::may: return 31+28+31+30;
        case Date::jun: return 31+28+31+30+31;
        case Date::jul: return 31+28+31+30+31+30;
        case Date::aug: return 31+28+31+30+31+30+31;
        case Date::sep: return 31+28+31+30+31+30+31+31;
        case Date::oct: return 31+28+31+30+31+30+31+31+30;
        case Date::nov: return 31+28+31+30+31+30+31+31+30+31;
        case Date::dec: return 31+28+31+30+31+30+31+31+30+31+30;
        }
    }

    // number of day in year
    int day_in_year(const Date& d)
    {
        int diy = nmonth(d.month());                        // days in months before d
        diy += d.day();                                     // days in month of d
        if (leapyear(d.year()) && d.month()>Date::feb) ++diy; // add day if leap year and later than February
        return diy;
    }

    // number of leap years between 1970 and Jan 1, year y
    int n_leapyears(int y)
    {
        // go through every year since 1970, check if it is a leap year
        int nl = 0;
        for (int i = 1970; i<y; ++i) {
            if (leapyear(i)) ++nl;
        }
        return nl;
    }

    // number of days since Jan 1, 1970 (day 0)
    long int days_linear(const Date& d)
    {
        if (d.year() < first_date.year()) error("days_linear: year must be 1970 or later");
        int y = d.year() - first_date.year();
        return y*365 + n_leapyears(d.year()) + day_in_year(d) - 1;
    }

    //------------------------------------------------------------------------------

    Date next_weekday(const Date& d)
    {
        Date nwd = d;
        Day day = day_of_week(d);
        switch (day) {
        case sunday:
        case monday:
        case tuesday:
        case wednesday:
        case thursday:
            nwd.add_day(1);
            break;
        case saturday:
            nwd.add_day(2);
            break;
        case friday:
            nwd.add_day(3);
            break;
        }
        return nwd;
    }

    //------------------------------------------------------------------------------

} // Chrono

namespace Chrono974 {
    // helper functions

    // check for valid date and initialise
    Date::Date(int yy, Month mm, int dd)
        :y(yy), m(mm), d(dd)
    {
        if (m<Date::jan || m>Date::dec || d<1 || d>31) error("invalid date");
    }

    const Date& default_date()
    {
        static Date dd(2001,Date::jan,1);   // start of 21st century
        return dd;
    }

    Date::Date()
        :y(default_date().year()),
        m(default_date().month()),
        d(default_date().day())
    {
    }

    // return year
    int Date::year() const
    {
        return y;
    }

    // return month
    Date::Month Date::month() const
    {
        return m;
    }

    // return day of month
    int Date::day() const
    {
        return d;
    }

    // increase the date by n years
    void Date::add_year(int n)
    {
        y += n;
    }

    // increase the date by n months
    void Date::add_month(int n)
    {
        // too complicated
    }

    // increase the Date by n days
    void Date::add_day(int n)
    {
        d += n;
        if (d > 31) error("add_day() results in invalid date");
    }

    // operators
    ostream& operator<<(ostream& os, const Date& d)
    {
        return os << '(' << d.year()
            << ',' << d.month()
            << ',' << d.day() << ')';
    }
}   // Chrono974

namespace Chrono971 {
    // helper functions

    // check for valid date and initialise
    Date::Date(int yy, Month mm, int dd)
        :y(yy), m(mm), d(dd)
    {
        if (m<Date::jan || m>Date::dec || d<1 || d>31) error("invalid date");
    }

    // increase the Date by n days
    void Date::add_day(int n)
    {
        d += n;
        if (d > 31) error("add_day() results in invalid date");
    }

    // operators
    // Date& d not const because Date::year() etc. are not declared const yet
    // (I don't "know" about that yet)
    ostream& operator<<(ostream& os, Date& d)
    {
        return os << '(' << d.year()
            << ',' << d.month()
            << ',' << d.day() << ')';
    }
}   // Chrono971

namespace Chrono943 {
    // helper functions
    Date::Date(int yy, int mm, int dd)
        :y(yy), m(mm), d(dd)
    {
        if (m<1 || m>12 || d<1 || d>31) error("invalid date");
    }

    void Date::add_day(int n)
    {
        d += n;
        if (d > 31) error("add_day() results in invalid date");
    }

    // operators
    // Date& d not const because Date::year() etc. are not declared const yet
    // (I don't "know" about that yet)
    ostream& operator<<(ostream& os, Date& d)
    {
        return os << '(' << d.year()
            << ',' << d.month()
            << ',' << d.day() << ')';
    }
}   // Chrono943

namespace Chrono942 {
    // helper functions
    Date::Date(int y, int m, int d)
        :y(y), m(m), d(d)
    {
        if (m<1 || m>12 || d<1 || d>31) error("invalid date");
    }

    void Date::add_day(int n)
    {
        d += n;
        if (d > 31) error("add_day() results in invalid date");
    }

    // operators
    ostream& operator<<(ostream& os, const Date& d)
    {
        return os << '(' << d.y
            << ',' << d.m
            << ',' << d.d << ')';
    }
}   // Chrono942

namespace Chrono941 {
    // helper functions
    void init_day(Date& dd, int y, int m, int d)
    {
        if (m<1 || m>12 || d<1 || d>31) error("invalid date");
        dd.y = y;
        dd.m = m;
        dd.d = d;
    }

    void add_day(Date& dd, int n)
    {
        init_day(dd,dd.y,dd.m,dd.d+n);
    }

    // operators
    ostream& operator<<(ostream& os, const Date& d)
    {
        return os << '(' << d.y
            << ',' << d.m
            << ',' << d.d << ')';
    }
}   // Chrono941
