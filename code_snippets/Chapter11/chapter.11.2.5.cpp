
//
// This is example code from Chapter 11.2.5 "Fields" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <iomanip>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    cout << 123456                        // no field used
         <<'|'<< setw(4) << 123456 << '|' // 123456 doesn't fit in a 4 char field
         << setw(8) << 123456 << '|'      // set field width to 8
         << 123456 << "|\n";              // field sizes don't stick

    cout << 12345 <<'|'<< setw(4) << 12345 << '|'
         << setw(8) << 12345 << '|' << 12345 << "|\n";
    cout << 1234.5 <<'|'<< setw(4) << 1234.5 << '|'
         << setw(8) << 1234.5 << '|' << 1234.5 << "|\n";
    cout << "asdfg" <<'|'<< setw(4) << "asdfg" << '|'
         << setw(8) << "asdfg" << '|' << "asdfg" << "|\n";
}

//------------------------------------------------------------------------------
