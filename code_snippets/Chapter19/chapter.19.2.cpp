
//
// This is example code from Chapter 19.2 "Changing size" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    int n = 100;
    vector<double> v(n); // v.size()==n
    
    // we can change its size in three ways:
    
    v.resize(10);        // v now has 10 elements
    
    v.push_back(7);      // add an element with the value 7 to the end of v
                         // v.size() increases by 1

    vector<double> v2(7);// v.size()==7
    v = v2;              // assign another vector; v is now a copy of v2
                         // v.size() now equals v2.size()
}

//------------------------------------------------------------------------------
