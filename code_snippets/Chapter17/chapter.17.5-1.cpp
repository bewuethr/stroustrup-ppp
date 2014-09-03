
//
// This is example code from Chapter 17.5 "Destructors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------
// a very simplified vector of doubles:
class vector {
    int sz;              // the size
    double* elem;        // a pointer to the elements
public:
    vector(int s)        // constructor
        :sz(s),          // initialize sz
        elem(new double[s]) // initialize elem
    {
        for (int i=0; i<s; ++i) elem[i]=0; // initialize elements
    }
    int size() const { return sz; }        // the current size
    // ...
    void clean_up() { delete[] elem; elem = 0; } // free memory
};

//------------------------------------------------------------------------------

void f(int n)
{
    vector v(n);    // allocate n doubles
    // ... 
}

//------------------------------------------------------------------------------

void f2(int n)
{
    vector v(n);         // define a vector (which allocates another n ints)
    // ... v ...
    v.clean_up();        // clean_up() deletes elem
}

//------------------------------------------------------------------------------

int main()
{
    f(5);
    f2(7);
}

//------------------------------------------------------------------------------
