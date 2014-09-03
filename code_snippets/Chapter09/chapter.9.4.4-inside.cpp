
//
// This is example code from Chapter 9.4.4 "Defining member functions" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

// simple Date (some people prefer implementation details last):
class Date {
public:
    Date(int yy, int mm, int dd) 
        :y(yy), m(mm), d(dd)        
    {
        // ...
    }

    void add_day(int n)
    {
        // ...
    }

    int month() { return m; }

    // ...
private:
    int y, m, d;            // year, month, day
};

//------------------------------------------------------------------------------

int main()
{
    Date sunday(2004,8,29); // initialize sunday with (2004,8,29)
    sunday.add_day(7);      // skip 7 days
    return sunday.month();  // get sunday's month
}

//------------------------------------------------------------------------------
