
//
// This is example code from Chapter 21.4.2 "Predicates on class members" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Record {
    string name;        // standard string for ease of use
    char addr[24];    // old style to match database layout
    // ...
};

//------------------------------------------------------------------------------

// Different comparisons for Rec objects:

struct  Cmp_by_name {
    bool operator()(const Record& a, const Record& b) const
    { return a.name < b.name; }
};

//------------------------------------------------------------------------------

struct  Cmp_by_addr {
    bool operator()(const Record& a, const Record& b) const
    { return strncmp(a.addr, b.addr, 24) < 0; }    // !!!
};

//------------------------------------------------------------------------------

int main()
{
    vector<Record> vr;

    // ...
    sort(vr.begin(), vr.end(), Cmp_by_name());    // sort by name
    // ...
    sort(vr.begin(), vr.end(), Cmp_by_addr());    // sort by addr
    // ...
}

//------------------------------------------------------------------------------
