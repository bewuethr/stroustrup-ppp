
//
// This is example code from Chapter 19.3.6 "Generalizing vector" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

template<class T> class allocator {
public:
    // ...
    T* allocate(int n);            // allocate space for n objects of type T
    void deallocate(T* p, int n);  // deallocate n objects of type T starting at p

    void construct(T* p, const T& v); // construct a T with the value v in p
    void destroy(T* p);            // destroy the T in p
};

//------------------------------------------------------------------------------

template<class T, class A = allocator<T> > class vector {
    A alloc;    // use allocate to handle memory for elements
    int sz;     // the size
    T* elem;    // a pointer to the elements
    int space;  // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }    
    vector(int s);
    vector(const vector&);            // copy constructor
    vector& operator=(const vector&); // copy assignment
    ~vector() { delete[ ] elem; }     // destructor

    void resize(int newsize, T def = T()); // growth
    void push_back(const T& d);
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

template<class T, class A> 
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;     // never decrease allocation
    T* p = alloc.allocate(newalloc); // allocate new space
    for (int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]); // copy
    for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);        // destroy
    alloc.deallocate(elem,space);    // deallocate old space
    elem = p;
    space = newalloc;    
}

//------------------------------------------------------------------------------

template<class T, class A>
void vector<T,A>::push_back(const T& val)
{
    // no more free space: get more
    if (space==0)
        reserve(8);
    else 
    if (space==sz)
        reserve(2*space);

    alloc.construct(&elem[sz],val);  // add val at end
    ++sz;                            // increase the size
}

//------------------------------------------------------------------------------

template<class T, class A>
void vector<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val); // construct
    for (int i = newsize; i<sz; ++i) alloc.destroy(&elem[i]); // destroy
    sz = newsize;        
}

//------------------------------------------------------------------------------

struct No_default {
    No_default(int);               // the only constructor for No_default
    // ...
};

//------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    vector<double> v1;
    v1.resize(100);                // add 100 copies of double(), that is 0.0
    v1.resize(200, 0.0);           // add 100 copies of 0.0 - mentioning 0.0 is redundant
    v1.resize(300, 1.0);           // add 100 copies of 1.0

    //vector<No_default> v2(10);   // error: tries to make 10 No_default()s

    vector<No_default> v3;
    v3.resize(100, No_default(2)); // add 100 copies of No_default(2)
    //v3.resize(200);              // error: tries to make 100 No_default()s
}

//------------------------------------------------------------------------------
