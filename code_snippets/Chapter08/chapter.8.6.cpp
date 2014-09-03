
//
// This is example code from Chapter 8.6 "Order of evaluation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

string program_name = "silly";
vector<string> v;                // v is global

void f()
{
    string s;                    // s is local to f
    while (cin>>s && s!="quit") {
        string stripped;         // stripped is local to the loop
        string not_letters;
        for (int i=0; i<s.size(); ++i)    // i has statement scope
            if (isalpha(s[i]))
                stripped += s[i];
            else
                not_letters += s[i];
        v.push_back(stripped);
        // ...
    }
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
