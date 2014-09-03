
//
// This is example code from Chapter 18.2.1 "Copy constructors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using std::cout;

//------------------------------------------------------------------------------

class vector {
    int sz;
    double* elem;
    void copy(const vector& arg);                 // copy elements from arg into *elem
public:
    vector(int s) :sz(s), elem(new double[s]) { } // constructor
    vector(const vector&) ;                       // copy constructor: define copy
    ~vector() { delete[] elem; }                  // destructor

    int size() const { return sz; }               // the current size

    double get(int n) { return elem[n]; }         // access: read
    void set(int n, double v) { elem[n]=v; }      // access: write
    // ...
};

//------------------------------------------------------------------------------

void vector::copy(const vector& arg)
// copy elements [0:arg.sz-1]
{
    for (int i = 0; i<arg.sz; ++i) elem[i] = arg.elem[i];
}

//------------------------------------------------------------------------------

vector:: vector(const vector& arg)
// allocate elements, then initialize them by copying
    :sz(arg.sz), elem(new double[arg.sz])
{
    copy(arg);
}

//------------------------------------------------------------------------------

int main()
{
    vector v(3);
    vector v2 = v;

    v.set(1,99);         // set v[1] to 99
    v2.set(0,88);        // set v2[0] to 88
    cout << v.get(0) << ' ' << v2.get(1); 
}

//------------------------------------------------------------------------------
