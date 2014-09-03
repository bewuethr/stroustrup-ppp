
//
// This is example code from Chapter 11.2.1 "Integer output" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    cout << 1234 << "\t(decimal)\n"
         << hex << 1234 << "\t(hexadecimal)\n"
         << oct << 1234 << "\t(octal)\n";

    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
    cout << 1234 << '\n';    // the octal base is still in effect

    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
    cout << showbase << dec; // show bases
    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';

    cout << 1234 << '\t' << 0x4d2 << '\t' << 02322 << '\n';
}

//------------------------------------------------------------------------------
