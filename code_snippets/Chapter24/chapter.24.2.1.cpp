
//
// This is example code from Chapter 24.2.1 "Numeric limits" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <limits>

using namespace std;

//------------------------------------------------------------------------------

int main()
{

    cout << "number of bytes in an int: " << sizeof(int) << endl;
    cout << "largest int: " << INT_MAX << endl;
    cout << "smallest int value: " << numeric_limits<int>::min() << endl;

    if (numeric_limits<char>::is_signed)
        cout << "char is signed\n";
    else
        cout << "char is unsigned\n";

    cout << "char with min value: " << numeric_limits<char>::min() << endl;
    cout << "min char value: "  << int(numeric_limits<char>::min()) << endl;
}

//------------------------------------------------------------------------------
