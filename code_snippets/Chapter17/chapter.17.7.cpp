
//
// This is example code from Chapter 17.7 "Pointers to class objects" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <vector>

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

vector* f(int s)
{
    vector v(s);
    vector* p = new vector(s); // allocate a vector on free store
    // ...
    *p = v;                    // copy into vector through pointer
    return p;
}

//------------------------------------------------------------------------------

void ff()
{
    vector* q = f(4);
    vector vv = *q;            // copy from vector through pointer
    // ...
    delete q;                  // free vector on free store
}

//------------------------------------------------------------------------------

int main()
{
    int     s = 100;
    vector* p = new vector(s); // allocate a vector on free store
    delete p;                  // deallocate

    // An example with standard STL vector:
    {
        using std::vector;

        vector< vector<double> >* p
            = new vector<vector<double> > (10);
        delete p;

        vector< vector< vector<double> > >* q
            = new vector<vector<vector<double> > > (20);
        delete q;
    }

    // all classes support the operator . (dot) for accessing members
    {
        vector v(4);
        int x = v.size();
        double d = v.get(3);
    }

    // all classes support the operator -> (arrow) for accessing members
    {
        vector* p = new vector(4);
        int x = p->size();
        double d = p->get(3);
    }
}

//------------------------------------------------------------------------------
