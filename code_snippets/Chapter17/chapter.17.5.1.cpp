
//
// This is example code from Chapter 17.5.1 "Generated destructors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Customer {
    string name;
    vector<string> addresses;
    // ...
};

//------------------------------------------------------------------------------

void some_fct()
{
    Customer fred;
    // initialize fred
    // use fred
}

//------------------------------------------------------------------------------

int main()
{
    some_fct();
}

//------------------------------------------------------------------------------
