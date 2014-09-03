
//
// This is example code from Chapter 21.3 "The general search: find_if()" of
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

bool odd(int x) { return x%2; }    // % is the modulo operator

void f(vector<int>& v)
{
    vector<int>::iterator p = find_if(v.begin(), v.end(), odd);
    if (p!=v.end()) { /* we found and odd number */ }
    // ...
}

//------------------------------------------------------------------------------

bool larger_than_42(int x) { return x>42; }

void f(list<double>& v)
{
    list<double>::iterator p = find_if(v.begin(), v.end(), larger_than_42);
    if (p!=v.end()) { /* we found value > 42 */ }
    // ...
}

//------------------------------------------------------------------------------

int v;        // the value to which larger_than_v() compares its argument
bool larger_than_v(int x) { return x>v; }

void f(list<double>& v, int x)
{
    ::v = 31; // set v to 31 for the next call of larger_than_v
    list<double>::iterator p = find_if(v.begin(), v.end(), larger_than_v);
    if (p!=v.end()) { /* we found value > 31 */ }

    ::v = x;  // set v to x for the next call of larger_than_v
    list<double>::iterator q = find_if(v.begin(), v.end(), larger_than_v);
    if (q!=v.end()) { /* we found value > x*/ }

    // ...
}

//------------------------------------------------------------------------------

int main()
{
    // works for vector of int
    {
        int initializer[7] = {1,2,3,4,5,6,7};
        int* first = initializer;
        int* last  = initializer+7;

        vector<int> v(first,last);
        f(v);
    }

    // works for list of double
    {
        double  initializer[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
        double* first = initializer;
        double* last  = initializer+7;

        list<double> l(first,last);
        f(l);
        f(l,4);
    }
}

//------------------------------------------------------------------------------
