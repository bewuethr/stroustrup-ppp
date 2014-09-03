
//
// This is example code from Chapter 8.2.3 "Default initialization" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"     // we find the declaration of cout in here

//------------------------------------------------------------------------------

int main()
{
    vector<string> v; 
    string s;
    while (cin>>s) v.push_back(s);
}

//------------------------------------------------------------------------------
