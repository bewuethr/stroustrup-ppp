
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

int get_int();                 // read an int from cin
int get_int(int low, int high);// read an int in [low:high] from cin

//------------------------------------------------------------------------------

int get_int()
{
    int n = 0;
    while (true) {
        if (cin >> n) return n;
        cout << "Sorry, that was not a number; please try again\n";
        skip_to_int();
    }
}

//------------------------------------------------------------------------------

int get_int(int low, int high)
{
    cout << "Please enter an integer in the range "
         << low << " to " << high << " (inclusive):\n";

    while (true) {
        int n = get_int();
        if (low<=n && n<=high) return n;
        cout << "Sorry "
             << n << " is not in the [" << low << ':' << high
             << "] range; please try again\n";
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    int n = get_int(1,10);
    cout << "n: " << n << endl;

    int m = get_int(2,300);
    cout << "m: " << m << endl;
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
