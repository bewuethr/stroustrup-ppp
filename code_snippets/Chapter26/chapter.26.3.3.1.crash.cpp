
//
// This is example code from Chapter 26.3.3.1 "Dependencies" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

vector<int> vec(10);

//------------------------------------------------------------------------------

int do_dependent(int a, int& b) // messy function
      // undisciplined dependencies
{
    int val ;
    cin>>val;
    vec[val] += 10;
    cout << a;
    b++;
    return b;
}

//------------------------------------------------------------------------------

int main()
{
    int b = 0;
    return do_dependent(b,b);
}

//------------------------------------------------------------------------------
