
//
// This is example code from Chapter 10.11.3 "Changing representations" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

vector<string> month_input_tbl;    // month_input_tbl[0]=="jan"

//------------------------------------------------------------------------------

void init_input_tbl(vector<string>& tbl)
// initialize vector of input representations
{
    tbl.push_back("jan");
    tbl.push_back("feb");
    tbl.push_back("mar");
    tbl.push_back("apr");
    tbl.push_back("may");
    tbl.push_back("jun");
    tbl.push_back("jul");
    tbl.push_back("aug");
    tbl.push_back("sep");
    tbl.push_back("oct");
    tbl.push_back("nov");
    tbl.push_back("dec");
}

//------------------------------------------------------------------------------

int month_to_int(string s)
// is s the name of a month? If so return its index [0:11] otherwise -1
{
    for (int i=0; i<12; ++i) if (month_input_tbl[i]==s) return i;
    return -1;
}

//------------------------------------------------------------------------------

vector<string> month_print_tbl;    // month_print_tbl[0]=="January"

//------------------------------------------------------------------------------

void init_print_tbl(vector<string>& tbl)
// initialize vector of output representations
{
    tbl.push_back("January");
    tbl.push_back("February");
    tbl.push_back("March");
    tbl.push_back("April");
    tbl.push_back("May");
    tbl.push_back("June");
    tbl.push_back("July");
    tbl.push_back("August");
    tbl.push_back("September");
    tbl.push_back("October");
    tbl.push_back("November");
    tbl.push_back("December");
}

//------------------------------------------------------------------------------

string int_to_month(int i)
// months [0:11]
{
    if (i<0 || 12<=i) error("bad month index");
    return month_print_tbl[i];
}

//------------------------------------------------------------------------------

int main()
try
{
    // first initialize representation tables:
    init_print_tbl(month_print_tbl);
    init_input_tbl(month_input_tbl);
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
