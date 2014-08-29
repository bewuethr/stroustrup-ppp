#include "../lib_files/std_lib_facilities.h"

namespace Chrono {

    //------------------------------------------------------------------------------

    class Date {
    public:
        enum Month {
            jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
        };

        class Invalid { };              // to throw as exception

        Date(int y, Month m, int d);    // check for valid date and initialize
        Date();                         // default constructor
        // the default copy operations are fine

        // non-modifying operations:
        int day() const { return d; }
        Month month() const { return m; }
        int year() const { return y; }

        // modifying operations:
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);
    private:
        int y;
        Month m;
        int d;
    };

    //------------------------------------------------------------------------------

    bool is_date(int y, Date::Month m, int d);  // true for valid date

    //------------------------------------------------------------------------------

    bool leapyear(int y);                       // true if y is a leap year
    int day_in_year(const Date& d);             // number of day in year
    int n_leapyears(int y);                     // number of leap years between Jan 1 of year y and first_date
    long int days_linear(const Date& d);        // days since first_date (day 0: Jan 1, 1970)

    enum Day {
        sunday, monday, tuesday, wednesday, thursday, friday, saturday
    };
    Day day_of_week(const Date& d);             // weekday of d
    ostream& operator<<(ostream& os, Day d);

    //------------------------------------------------------------------------------

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    //------------------------------------------------------------------------------

    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, Date& dd);

    //------------------------------------------------------------------------------

} // Chrono

namespace Chrono974 {
    // simple Date (use Month type)
    class Date {
    public:
        enum Month {
            jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
        };

        // constructors
        Date(int y, Month m, int d);    // check for valid date and initialise
        Date();                         // default constructor

        // const members: can't modify the object
        int year() const;
        Month month() const;
        int day() const;

        // non-const members
        void add_year(int n);
        void add_month(int n);
        void add_day(int n);
    private:
        int y;      // year
        Month m;
        int d;      // day of month
    };

    // operators
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono974

namespace Chrono971 {
    // simple Date (use Month type)
    class Date {
    public:
        enum Month {
            jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
        };

        Date(int y, Month m, int d);    // check for valid date and initialise
        void add_day(int n);            // increase the Date by n days
        int year() { return y; }
        Month month() { return m; }
        int day() { return d; }
    private:
        int y;      // year
        Month m;
        int d;      // day
    };

    // operators
    ostream& operator<<(ostream& os, Date& d);  // Date& d not const on purpose
}   // Chrono971

namespace Chrono943 {
    // simple Date (control access)
    class Date {
        int y, m, d;                // year,month,day
    public:
        Date(int y, int m, int d);  // check for valid date and initialise
        void add_day(int n);        // increase the Date by n days
        int year() { return y; }
        int month() { return m; }
        int day() { return d; }
    };

    // operators
    ostream& operator<<(ostream& os, Date& d);  // Date& d not const on purpose
}   // Chrono943

namespace Chrono942 {
    // simple Date
    // guarantee initialisation with constructor
    // provide some notational convenience
    struct Date {
        int y, m, d;                // year,month,day
        Date(int y, int m, int d);  // check for valid date and initialise
        void add_day(int n);        // increase the Date by n days
    };

    // operators
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono942

namespace Chrono941 {
    // simple Date
    struct Date {
        int y;  // year
        int m;  // month in year
        int d;  // day of month
    };

    // helper functions
    void init_day(Date& dd, int y, int m, int d);
    void add_day(Date& dd, int n);

    // operators
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono941
