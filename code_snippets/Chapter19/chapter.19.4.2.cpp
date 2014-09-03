
//
// This is example code from Chapter 19.4.2 "A confession: Macros" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

//------------------------------------------------------------------------------

// class used to report range access errors
struct out_of_range 
{
    out_of_range(const std::string& error_message) {}
};

//------------------------------------------------------------------------------

struct Range_error : out_of_range { // enhanced vector range error reporting
    int index;
    Range_error(int i) :out_of_range("Range error"), index(i) { }
};

//------------------------------------------------------------------------------

template<class T> struct Vector : public std::vector<T> {
    typedef typename std::vector<T>::size_type size_type;

    Vector() { }
    Vector(size_type n) :std::vector<T>(n) {}
    Vector(size_type n, const T& v) :std::vector<T>(n,v) {}

    T& operator[](unsigned int i) // rather than return at(i);
    {
        if (i<0||this->size()<=i) throw Range_error(i);
        return std::vector<T>::operator[](i);
    }

    const T& operator[](unsigned int i) const
    {
        if (i<0||this->size()<=i) throw Range_error(i);
        return std::vector<T>::operator[](i);
    }
};

//------------------------------------------------------------------------------

// disgusting macro hack to get a range checked vector:
#define vector Vector

int main()
try
{
    vector<int> v(10);
    v[20] = 5; // trying to access invalid index
}
catch (std::exception& e) {
    std::cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    std::cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
