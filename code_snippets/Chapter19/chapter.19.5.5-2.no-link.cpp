
//
// This is example code from Chapter 19.5.5 "RAII for vector" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

template<class T> class allocator {
public:
    // ...
    T* allocate(int n);                 // allocate space for n objects of type T
    void deallocate(T* p, int n);       // deallocate n objects of type T starting at p

    void construct(T* p, const T& v);   // construct a T with the value v in p
    void destroy(T* p);                 // destroy the T in p
};

//------------------------------------------------------------------------------

template<class T, class A>
struct vector_base {
    A alloc;                            // allocator
    T* elem;                            // start of allocation
    int sz;                             // number of elements
    int space;                          // amount of allocated space

    vector_base(const A& a, int n)
        : alloc(a), elem(a.allocate(n)), sz(n), space(n) { }
    ~vector_base() { alloc.deallocate(elem,space); }
};

//------------------------------------------------------------------------------

template<class T, class A>
void swap(vector_base<T,A>& a, vector_base<T,A>& b);

//------------------------------------------------------------------------------

template<class T, class A = allocator<T> >
class vector : private vector_base<T,A> {
public:
    // ...
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

template<class T, class A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=this->space) return;  // never decrease allocation
    vector_base<T,A> b(this->alloc,newalloc); // allocate new space
    for (int i=0; i<this->sz; ++i) this->alloc.construct(&b.elem[i],this->elem[i]); // copy
    for (int i=0; i<this->sz; ++i) this->alloc.destroy(&this->elem[i]); // destroy old 
    swap< vector_base<T,A> >(*this,b);  // swap representations
}

//------------------------------------------------------------------------------
