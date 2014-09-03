
//
// This is example code from Chapter 19.2.4 "Push_back" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

class vector {
    int sz;       // number of elements
    double* elem; // address of first element
    int space;    // number of elements plus "free space"/"slots"
                  // for new elements ("the current allocation")
public:
    vector();
    void reserve(int newalloc);
    int  capacity() const;
    void resize(int newsize);
    void push_back(double d);
    // ...
};

//------------------------------------------------------------------------------

vector::vector() :sz(0), elem(0), space(0) {}

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

int vector::capacity() const { return space; }

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

int main()
{
    vector v;
    v.reserve(10);
    v.resize(4);
    v.push_back(7);
    return v.capacity();
}

//------------------------------------------------------------------------------
