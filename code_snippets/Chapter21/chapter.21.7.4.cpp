
//
// This is example code from Chapter 21.7.4 "Copy_if" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class In, class Out, class Pred>
Out copy_if(In first, In last, Out res, Pred p)
// copy elements that fulfills the predicate
{
    while (first!=last) {
        if (p(*first)) *res++ = *first;
        ++first;
    }
    return res;
}

//------------------------------------------------------------------------------

class Larger_than {
    int v;
public:
    Larger_than(int vv) : v(vv) { }               // store the argument
    bool operator()(int x) const { return x>v; }  // compare
};

//------------------------------------------------------------------------------

void f(const vector<int>& v)
// copy all elements with a value larger than 6
{
    vector<int> v2(v.size());
    copy_if(v.begin(), v.end(), v2.begin(), Larger_than(6));
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    vector<int> v(10);
    f(v);
}

//------------------------------------------------------------------------------
