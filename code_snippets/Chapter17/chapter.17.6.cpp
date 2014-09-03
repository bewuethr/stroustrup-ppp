
//
// This is example code from Chapter 17.6 "Access to elements" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// a very simplified vector of doubles:
class vector {
    int sz;            // the size
    double* elem;      // a pointer to the elements
public:
    vector(int s) :sz(s), elem(new double[s]) { } // constructor
    ~vector() { delete[] elem; }                  // destructor

    int size() const { return sz; }               // the current size

    double get(int n) { return elem[n]; }         // access: read
    void set(int n, double v) { elem[n]=v; }      // access: write
};

//------------------------------------------------------------------------------

int main()
{
    vector v(5);
    for (int i=0; i<v.size(); ++i) {
        v.set(i,1.1*i);
        cout << "v[" << i << "]==" << v.get(i) << '\n';
    }
}

//------------------------------------------------------------------------------
