
//
// This is example code from Chapter 20.8 "Adapting our vector to the STL" of
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
    int sz;     // the size
    T*  elem;   // a pointer to the elements
    int space;  // number of elements plus number of free space "slots"
    A   alloc;  // use allocate to handle memory for elements
public:
    typedef unsigned long size_type;
    typedef T             value_type;
    typedef T*            iterator;    // Elem* is the simplest possible iterator
    typedef const T*      const_iterator;

    iterator       begin();
    const_iterator begin() const;
    iterator       end();
    const_iterator end() const;

    size_type size();
    int capacity() const { return space; }

    // ... all the other stuff from Chapter 19 and §20.5 ...

    T&       back();
    iterator insert(iterator p, const T& val);
    iterator erase(iterator p);    
};

//------------------------------------------------------------------------------

template<class T, class A> 
typename vector<T,A>::iterator vector<T,A>::erase(iterator p)
{
    if (p==end()) return p;
    for (iterator pos = p+1; pos!=end(); ++pos)
        *(pos-1) = *pos;        // copy element "one position to the left"
    alloc.destroy(&*(end()-1)); // destroy surplus copy of last element
    --sz;
    return p;
}

//------------------------------------------------------------------------------

template<class T, class A>
typename vector<T,A>::iterator vector<T,A>::insert(iterator p, const T& val)
{
    int index = p-begin();
    if (size()==capacity()) reserve(2*size());    // make sure we have space

    // first copy last element into uninitialized space:
    alloc.construct(elem+sz,*back());
    ++sz;
    iterator pp = begin()+index; // the place to put val
    for (iterator pos = end()-1; pos!=pp; --pos)
        *pos = *(pos-1);         // copy elements one position to the right
    *(begin()+index) = val;      // "insert" val
    return pp;
}

//------------------------------------------------------------------------------
