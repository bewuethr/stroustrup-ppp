
//
// This is example code from Chapter 4.4.1.3 "Switch technicalities" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()    // you can label a statement with several case labels
{ 
    cout << "Please enter a digit\n";
    char a;
    cin >> a;

    switch (a) {
    case '0': case '2': case '4': case '6': case '8':
        cout << "is even\n";
        break;
    case '1': case '3': case '5': case '7': case '9':
        cout << "is odd\n";
        break;
    default:
        cout << "is not a digit\n";
        break;
    }
}

//------------------------------------------------------------------------------
