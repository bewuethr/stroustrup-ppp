
//
// This is example code from Chapter 8.5.1 "Declaring arguments and return type" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double fct(int a, double d);            // declaration of fct (no body)
double fct(int a, double d) { return a*d; }    // definition of fct

int current_power();        // current_power doesn't take an argument

void increase_power(int level);    // increase_power doesn't return a value

// search for s in vs;
// vs[hint] might be a good place to start the search
// return the index of a match; -1 indicates "not found":
int my_find(vector<string> vs, string s, int hint); // naming arguments

int my_find(vector<string>, string, int);           // not naming arguments

int my_find(vector<string> vs, string s, int hint)
// search for s in vs starting at hint
{
    if (hint<0 || vs.size()<=hint) hint = 0;
    for (int i = hint; i<vs.size(); ++i)            // search starting from hint
        if (vs[i]==s) return i;
    if (0<hint) {    // if we didn't find s search before hint
        for (int i = 0; i<hint; ++i)
            if (vs[i]==s) return i;
    }
    return -1;    
}

//------------------------------------------------------------------------------

namespace different
{

    int my_find(vector<string> vs, string s, int)   // 3rd argument unused
    {
        for (int i = 0; i<vs.size(); ++i)
            if (vs[i]==s) return i;
        return -1;    
    }    

}

//------------------------------------------------------------------------------

int main()
{
    const int   N = 4;
    const char* cities[N] = {"Aarhus", "Brussels", "Cincinnati", "Dublin"};
    vector<string> v(cities, cities+N);
    return my_find(v, "Dublin", 2) == different::my_find(v, "Dublin", 2);
}

//------------------------------------------------------------------------------
