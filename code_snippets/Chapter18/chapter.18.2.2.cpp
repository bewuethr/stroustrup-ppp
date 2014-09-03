
//
// This is example code from Chapter 18.2.2 "Copy assignments" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

class vector {
    int sz;
    double* elem;
    void copy(const vector& arg);     // copy elements from arg into *elem
public:
    vector(int s) :sz(s), elem(new double[s]) { } // constructor
    ~vector() { delete[] elem; }                  // destructor

    int size() const { return sz; }               // the current size

    double get(int n) { return elem[n]; }         // access: read
    void set(int n, double v) { elem[n]=v; }      // access: write
    vector& operator=(const vector&);             // copy assignment
};

//------------------------------------------------------------------------------

void vector::copy(const vector& arg)
// copy elements [0:arg.sz-1]
{
    for (int i = 0; i<arg.sz; ++i) elem[i] = arg.elem[i];
}

//------------------------------------------------------------------------------

vector& vector::operator=(const vector& a)
// make this vector a copy of a
{
    double* p = new double[a.sz];     // allocate new space
    copy(a);                          // copy elements
    delete[ ] elem;                   // deallocate old space
    elem = p;                         // now we can re-set elem
    sz = a.sz;
    return *this;                     //  return a self-reference (see §17.10)
}

//------------------------------------------------------------------------------

void f2(int n)
{
    vector v(3);                      // define a vector 
    v.set(2,2.2);
    vector v2(4);
    v2 = v;                           // assignment: what happens here?
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    vector v(10);
    v=v;    // self assignment
}

//------------------------------------------------------------------------------
