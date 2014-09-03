
//
// This is example code from Chapter 19.2.2 "Reserve and capacity" of
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

int main()
{
    vector v;
    v.reserve(10);
    return v.capacity();
}

//------------------------------------------------------------------------------
