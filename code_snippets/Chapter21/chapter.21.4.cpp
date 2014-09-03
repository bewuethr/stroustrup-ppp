
//
// This is example code from Chapter 21.4 "Function objects" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <list>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class In, class Pred>
In find_if(In first, In last, Pred pred)
{
    while (first!=last && !pred(*first)) ++first;
    return first;
}

//------------------------------------------------------------------------------

class Larger_than {
    int v;
public:
    Larger_than(int vv) : v(vv) { }            // store the argument
    bool operator()(int x) const { return x>v; }        // compare
};

//------------------------------------------------------------------------------

void f(list<double>& v, int x)
{
    list<double>::iterator p = find_if(v.begin(), v.end(), Larger_than(31));
    if (p!=v.end()) { /* we found value > 31 */ }

    list<double>::iterator q = find_if(v.begin(), v.end(), Larger_than(x));
    if (q!=v.end()) { /* we found value > x */ }

    // ...
}

//------------------------------------------------------------------------------

int main()
{
    double  initializer[7] = {11.1, 22.2, 33.3, 44.4, 55.5, 66.6, 77.7};
    double* first = initializer;
    double* last  = initializer+7;

    list<double> v(first,last);

    find_if(v.begin(),v.end(),Larger_than(31));
}

//------------------------------------------------------------------------------
