
//
// This is example code from Chapter 18.5.4 "Pointer problems" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

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
    double& operator[](int n) { return elem[n]; } // return reference
    // ...
};

//------------------------------------------------------------------------------

void fct_that_can_receive_a_0(int* p)
{
    if (p == 0) {
        // do something
    }
    else {
        // use p
        *p =7;
    }
}

//------------------------------------------------------------------------------

int* fct_that_can_return_a_0()
{
    return 0;
}

//------------------------------------------------------------------------------

// Don't return a pointer to a local variable:
int* f()
{
    int x = 7;
    // ...
    return &x;
}

//------------------------------------------------------------------------------

vector& ff()
{
    vector x(7);
    // ...
    return x;
}    // the vector x is destroyed here

int main()
{
    // Don't access through the null pointer:
    {
        int* p = 0;
        *p = 7;      // Ouch!
    }

    int* p = fct_that_can_return_a_0();
    if (p == 0) { 
        // do something
    }
    else {
        // use p
        *p = 7;
    }

    // Do initialize your pointers:
    {
        int* p;
        *p = 9;      // Ouch!
    }

    // Don't access non-existing array elements:
    {
        int a[10];
        int* p = &a[10];
        *p = 11;     // Ouch!
        a[10] = 12;  // Ouch!
    }

    // Don't access through a deleted pointer:
    {
        int* p = new int(7);
        // ...
        delete p;
        // ...
        *p = 13;     // Ouch!
    }

    // Don't return a pointer to a local variable:
    {
        int* p = f();
        // ...
        *p = 15;     // Ouch!

    }

    // Consider a logically equivalent example:
    {
        vector& p = ff();
        // ...
        p[4] = 15;     // Ouch!
    }
}

//------------------------------------------------------------------------------
