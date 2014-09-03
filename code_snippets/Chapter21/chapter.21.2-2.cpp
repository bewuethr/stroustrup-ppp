
//
// This is example code from Chapter 21.2 "The simplest algorithm: find()" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class In, class T>
In find(In first, In last, const T& val) 
// Find the first element in [first,last) that equals val
{
    for (In p = first; p!=last; ++p)
        if (*p == val) return p;
    return last;
}

//------------------------------------------------------------------------------

void f(vector<int>& v, int x)
{
    vector<int>::iterator p = find(v.begin(),v.end(),x);
    if (p!=v.end()) {
        // we found x in v
    }
    else {
        // no x in v
    }
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    int initializer[7] = {1,2,3,4,5,6,7};
    int* first = initializer;
    int* last  = initializer+7;

    vector<int> v(first,last);
    f(v,4);
}

//------------------------------------------------------------------------------
