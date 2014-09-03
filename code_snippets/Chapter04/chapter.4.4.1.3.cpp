
//
// This is example code from Chapter 4.4.1.3 "Switch technicalities" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()        // case labels must be constants
{
    // define alternatives:
    int y = 'y';             // this is going to cause trouble
    const char n = 'n';
    const char m = '?'; 
    cout << "Do you like fish?\n";
    char a;
    cin >> a;
    switch (a) {
        case n:
            // ...
            //case y:        // error: variable in case label
            // ...
        case m:
            // ...
            //case 'n':      // error: duplicate case label (n's value is  'n')
            // ...
        default:
            // ...
            ;
    }
}

//------------------------------------------------------------------------------
