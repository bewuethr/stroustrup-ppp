
//
// This is example code from Chapter 18.4 "Access to vector elements" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using std::cout;

//------------------------------------------------------------------------------

class vector {
    int sz;          // the size
    double* elem;    // a pointer to the elements
public:
    vector(int s) :sz(s), elem(new double[s]) { }  // constructor
    ~vector() { delete[] elem; }                   // destructor
    int size() const { return sz; }                // the current size
    double* operator[](int n) { return &elem[n]; } // return pointer
};

//------------------------------------------------------------------------------

int main()
{
    vector v(10);
    for (int i=0; i<v.size(); ++i) {    // works, but still too ugly:
        *v[i] = i;    
        cout << *v[i];
    }
}

//------------------------------------------------------------------------------
