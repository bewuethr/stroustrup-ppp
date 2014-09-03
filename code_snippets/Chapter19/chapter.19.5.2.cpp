
//
// This is example code from Chapter 19.5.2 "Resource acquisition is initialization" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <vector>

using std::vector;

//------------------------------------------------------------------------------

void f(vector<int>& v, int s)
{
    vector<int> p(s);
    vector<int> q(s);
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    vector<int> v(10);
    f(v,15);
}

//------------------------------------------------------------------------------
