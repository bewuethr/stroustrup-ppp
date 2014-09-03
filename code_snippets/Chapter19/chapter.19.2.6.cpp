
//
// This is example code from Chapter 19.2.6 "Our vector so far" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

// an almost real vector of doubles:
class vector {
    /*
    invariant:
        for 0<=n<sz elem[n] is element n
        sz<=space;
        if sz<space there is space for (space-sz) doubles after elem[sz-1]
    */
    int sz;           // the size
    double* elem;     // pointer to the elements (or 0)
    int space;        // number of element plus number of free slots
public:
    vector() : sz(0), elem(0), space(0) { }
    vector(int s) :sz(s), elem(new double[s]), space(s)
    {
        for (int i=0; i<sz; ++i) elem[i]=0;    // elements are initialized
    }    

    vector(const vector&);            // copy constructor
    vector& operator=(const vector&); // copy assignment

    ~vector() { delete[ ] elem; }     // destructor

    double& operator[ ](int n) { return elem[n]; } // access
    const double& operator[ ](int n) const { return elem[n]; } 

    int size() const { return sz; }    
    int capacity() const { return space; }

    void resize(int newsize);         // growth
    void push_back(double d);
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

void vector::reserve(int newalloc)
{
    if (newalloc<=space) return;             // never decrease allocation
    double* p = new double[newalloc];        // allocate new space
    for (int i=0; i<sz; ++i) p[i] = elem[i]; // copy old elements
    delete[ ] elem;                          // deallocate old space
    elem = p;
    space = newalloc;        
}

//------------------------------------------------------------------------------

void vector::resize(int newsize)
// make the vector have newsize elements
// initialize each new elements with the default value 0.0
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) elem[i] = 0;    // initialize new elements 
    sz = newsize;    
}

//------------------------------------------------------------------------------

void vector::push_back(double d)
// increase vector size by one; initialize the new element with d
{
    // no more free space: get more
    if (space==0)
        reserve(8);
    else 
    if (space==sz)
        reserve(2*space);

    elem[sz] = d;    // add d at end
    ++sz;            // increase the size (sz is the number of elements)
}

//------------------------------------------------------------------------------

vector& vector::operator=(const vector& a)
{
    if (this==&a) return *this;    // self-assignment, no work needed

    if (a.sz<=space) {             // enough space, no need for new allocation
        for (int i = 0; i<a.sz; ++i) elem[i] = a.elem[i]; // copy elements
        sz = a.sz;
        return *this;
    }

    double* p = new double[a.sz];  // allocate new space
    for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i];    // copy elements
    delete[ ] elem;                // deallocate old space
    space = sz = a.sz;             // set new size
    elem = p;                      // set new elements
    return *this;                  //  return a self-reference
}

//------------------------------------------------------------------------------

int main()
{
    vector v;
    v.reserve(10);
    v.resize(4);
    v.push_back(7);

    vector a;
    a = v;
    return a.capacity();
}

//------------------------------------------------------------------------------
