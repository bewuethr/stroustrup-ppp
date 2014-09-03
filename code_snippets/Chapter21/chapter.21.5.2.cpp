
//
// This is example code from Chapter 21.5.2 "Generalizing accumulate()" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template <class T, int N>    // not quite the standard array
struct array {
    typedef unsigned long size_type;
    typedef T value_type;
    typedef T* iterator;
    typedef T* const_iterator;

    T elems[N];
    // No explicit construct/copy/destroy needed

    iterator begin() { return elems; }
    const_iterator begin() const { return elems; }
    iterator end() { return elems+N; }
    const_iterator end() const { return elems+N; }

    size_type size() const;

    T& operator[](int n) { return elems[n]; }
    const T& operator[](int n) const { return elems[n]; }

    const T& at(int n) const; // range-checked access
    T& at(int n);             // range-checked access

    T * data() { return elems; }
    const T * data() const { return elems; }
};

//------------------------------------------------------------------------------


template<class In, class T, class BinOp>
T accumulate(In first, In last, T init, BinOp op)
{
    while (first!=last) {
        init = op(init, *first);
        ++first;
    }
    return init;
}

//------------------------------------------------------------------------------

int main()
{
    array<double,4> a = { 1.1, 2.2, 3.3, 4.4 };    // See §20.9
    cout << accumulate(a.begin(),a.end(), 1.0, multiplies<double>());
}

//------------------------------------------------------------------------------

struct Record {
    double unit_price;
    int units;        // number of units sold
    // ...
};

//------------------------------------------------------------------------------

double price(double v, const Record& r)
{
    return v + r.unit_price * r.units;
}

//------------------------------------------------------------------------------

void f(const vector<Record>& vr, map<string,Record*>& m)
{
    double total = accumulate(vr.begin(), vr.end(), 0.0, price);
    // ...
}

//------------------------------------------------------------------------------
