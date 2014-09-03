
//
// This is example code from Chapter 20.9 "Adapting built-in arrays to the STL" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

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

    const T& at(int n) const;    // range-checked access
    T& at(int n);             // range-checked access

    T * data() { return elems; }
    const T * data() const { return elems; }
};

//------------------------------------------------------------------------------

template<class Iterator >
Iterator high(Iterator first, Iterator last)
// return an iterator to the element in [first,last) that has the highest value
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

//------------------------------------------------------------------------------

void f()
{
    array<double,6> a = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5 };
    array<double,6>::iterator p = high(a.begin(), a.end());
    cout << "the highest value was " << *p << endl;
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
