
//
// This is example code from Chapter 10.7 "Reading a single value" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

//------------------------------------------------------------------------------

using namespace std;

int main()
{
    cout << "Please enter an integer in the range 1 to 10 (inclusive):\n";
    int n = 0;
    while (cin>>n && !(1<=n && n<=10))    // read and check range
        cout << "Sorry "
             << n << " is not in the [1:10] range; please try again\n";
}

//------------------------------------------------------------------------------
