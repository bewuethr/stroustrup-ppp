
//
// This is example code from Chapter 18.2 "Copying" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using std::cout;

//------------------------------------------------------------------------------

class vector {
    int sz;                             // the size
    double* elem;                       // a pointer to the elements
public:
    vector(int s)                       // constructor
        :sz(s), elem(new double[s]) { } // allocates memory
    ~vector()                           // destructor
    { delete[ ] elem; }                 // deallocates memory

    int size() const { return sz; }               // the current size

    double get(int n) { return elem[n]; }         // access: read
    void set(int n, double v) { elem[n]=v; }      // access: write
};

//------------------------------------------------------------------------------

void f(int n)
{
    vector v(3);                        // define a vector of 3 elements
    v.set(2,2.2);                       // set v[2] to 2.2
    vector v2 = v;                      // what happens here?
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    vector v(3);
    vector v2(3);
    v.set(1,99);                        // set v[1] to 99
    v2.set(0,88);                       // set v2[0] to 88
    cout << v.get(0) << ' ' << v2.get(1); 
}

//------------------------------------------------------------------------------
