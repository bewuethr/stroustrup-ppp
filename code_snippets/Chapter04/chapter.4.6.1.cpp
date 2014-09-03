
//
// This is example code from Chapter 4.6.1 "Growing a vector" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    vector<double> v;    // start off empty; that is, v has no elements

    v.push_back(2.7);    // add an element with the value 2.7 at end ("the back") of v
                         // v now has one element and v[0]==2.7

    v.push_back(5.6);    // add an element with the value 5.6 at end of v
                         // v now has two elements and v[1]==5.6

    v.push_back(7.9);    // add an element with the value 7.9 at end of v
                         // v now has three elements and v[2]==7.9

    for(int i=0; i<v.size(); ++i)
        cout << "v[" << i << "]==" <<v[i] << '\n'; 
}

//------------------------------------------------------------------------------
