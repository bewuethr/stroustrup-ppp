
//
// This is example code from Chapter 9.7.1 "Argument types" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

// simple Date (use Month type):
class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) // check for valid date and initialize
    {
        // ...
    }

private:
    int   y; // year
    Month m;
    int   d; // day
};

//------------------------------------------------------------------------------

int main()
{
    //Date d1(4,5,2005);            // oops: Year 4, day 2005
    //Date d2(2005,4,5);            // April 5 or May 4?

    //Date dx1(1998, 4, 3);         // error: 2nd argument not a Month
    //Date dx2(1998, 4, Date::mar); // error: 2nd argument not a Month
    Date dx2(4, Date::mar, 1998);   // oops: run-time error: day 1998
    //Date dx2(Date::mar, 4, 1998); // error: 2nd argument not a Month
    Date dx3(1998, Date::mar, 30);  // ok
    return 0;
}

//------------------------------------------------------------------------------
