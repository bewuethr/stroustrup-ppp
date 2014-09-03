
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
    vector(int s)                   // constructor
        :sz(s), elem(new double[s]) // allocate memory
    {
        for (int i=0; i<s; ++i) elem[i]=0;    // initialize elements
    }

    ~vector()            // destructor
    { delete[] elem; }   // free memory
    // ...
};

//------------------------------------------------------------------------------

void f3(int n)
{
    int* p = new int[n]; // allocate n ints
    vector v(n);         // define a vector (which allocates another n ints)
                         // ... use p and v ...
    delete[] p;          // deallocate the ints
}                        // vector automatically cleans up after v

int main()
{
    f3(42);
}

//------------------------------------------------------------------------------
