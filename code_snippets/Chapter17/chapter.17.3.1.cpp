
//
// This is example code from Chapter 17.3.1 "The sizeof operator" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    cout << "the size of char is " << sizeof(char) << ' ' << sizeof ('a') << '\n';
    cout << "the size of int is "  << sizeof(int)  << ' ' << sizeof (2+2) << '\n';
    int* p = 0;
    cout << "the size of int is "  << sizeof(int*) << ' ' << sizeof (p) << '\n';

    vector<int> v(1000);
    cout << "the size of vector<int>(1000) is "
         << sizeof(vector<int>) << ' ' << sizeof (v) << '\n';
}

//------------------------------------------------------------------------------
