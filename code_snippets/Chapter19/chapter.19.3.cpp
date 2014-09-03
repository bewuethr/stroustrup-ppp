
//
// This is example code from Chapter 19.3 "Templates" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

enum Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

//------------------------------------------------------------------------------

class Window;

struct Record
{
    int  a;
    char b;
};

//------------------------------------------------------------------------------

int main()
{
    vector<double>           v1;
    vector<int>              v2;
    vector<Month>            v3;
    vector<Window*>          v4;  // vector of pointers to Windows
    vector< vector<Record> > v5;  // vector of vectors of Records
    vector<char>             v6;
}

//------------------------------------------------------------------------------
