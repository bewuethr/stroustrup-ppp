
//
// This is example code from Chapter 10.7.1 "Breaking the problem into manageable parts" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void skip_to_int()
{
    if (cin.fail()) {          // we found something that wasn't an integer
        cin.clear();           // we'd like to look at the characters
        char ch;
        while (cin>>ch){       // throw away non-digits
            if (isdigit(ch)) {
                cin.unget();   // put the digit back,
                               // so that we can read the number
                return;
            }
        }
    }
    error("no input");         // eof or bad: give up
}

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Please enter an integer in the range 1 to 10 (inclusive):\n";
    int n = 0;
    while (true) {
        if (cin>>n) {          // we got an integer; now check it:
            if (1<=n && n<=10) break;
            cout << "Sorry " << n
                << " is not in the [1:10] range; please try again\n";
        }
        else {
            cout << "Sorry, that was not a number; please try again\n";
            skip_to_int();
        }
    }
    // if we get here n is in [1:10]
    return n;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
