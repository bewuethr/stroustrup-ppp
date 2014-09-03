
//
// This is example code from Chapter 3.5 "Assignment and initialization" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    {
        int a = 3;           // a starts out with the value 3

        a = 4;               // a gets the value 4 ("becomes 4")

        int b = a;           // b starts out with a copy of a's value (that is, 4)

        b = a+5;             // b gets the value a+5 (that is, 9)
        a = a+7;             // a gets the value a+7 (that is, 11)
    }

    {
        string a = "alpha";  // a starts out with the value "alpha"

        a = "beta";          // a gets the value "beta" ("becomes "beta"")

        string b = a;        // b starts out with a copy of a's value (that is, "beta")

        b = a+"gamma";       // b gets the value a+"gamma" (that is, "betagamma")
        a = a+"delta";       // a gets the value a+"delta" (that is, "betadelta")
    }

    {
        int y = 8;           // initialize y with 8
        int x;

        x = 9;               // assign 9 to x

        string t = "howdy!"; // initialize t with "howdy!"
        string s;

        s = "G'day";         // assign "G'day" to s
    }
}

//------------------------------------------------------------------------------
