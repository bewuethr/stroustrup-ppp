
//
// This is example code from Chapter 3.4 "Operations and operators" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// read and compare names:
int main()
{
    cout << "please enter two names\n";
    string first;
    string second;
    cin >> first >> second; // read two strings
    if (first == second) cout << "that's the same name twice\n";
    if (first < second)
        cout << first << " is alphabetically before " << second <<'\n';
    if (first > second)
        cout << first << " is alphabetically after " << second <<'\n';
}

//------------------------------------------------------------------------------
