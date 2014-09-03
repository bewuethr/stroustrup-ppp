
//
// This is example code from Chapter 18.4 "Access to vector elements" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

class vector {
    int sz;          // the size
    double* elem;    // a pointer to the elements
public:
    vector(int s) :sz(s), elem(new double[s]) { } // constructor
    ~vector() { delete[] elem; }                  // destructor
    // ...
    double operator[](int n) { return elem[n]; }  // return element
};

//------------------------------------------------------------------------------

int main()
{
    vector v(10);
    int x = v[2];    // fine
    //v[3] = x;        // error: v[3] is not an lvalue
}

//------------------------------------------------------------------------------
