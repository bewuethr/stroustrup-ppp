
//
// This is example code from Chapter 19.5.5 "RAII for vector" of
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
    A alloc;                       // use allocate to handle memory for elements
    int sz;                        // the size
    T* elem;                       // a pointer to the elements
    int space;                     // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }    
    vector(int s);

    vector(const vector&);            // copy constructor
    vector& operator=(const vector&); // copy assignment

    ~vector() { delete[ ] elem; }     // destructor

    // ...
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

template<class T, class A> 
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;        // never decrease allocation
    T* p = alloc.allocate(newalloc);    // allocate new space
    for (int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]); // copy
    for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);        // destroy
    alloc.deallocate(elem,space);       // deallocate old space
    elem = p;
    space = newalloc;    
}

//------------------------------------------------------------------------------

int main()
{
    vector<int> v;
    v.reserve(10);
}

//------------------------------------------------------------------------------
