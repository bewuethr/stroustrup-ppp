// Chapter 20, Exercise 18: define a range-checked iterator for vector (a
// random-access iterator)

// Adapting vector implementation "vectr" from Chapter 19, exercise 8 and 9

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

template<class T> class allocatr {
public:
    // allocate space for n objects of type T
    T* allocate(int n);

    // deallocate n objects of type T starting at p
    void deallocate(T* p) { free(p); }

    // construct a T with the value v in p
    void construct(T* p, const T& v) { new(p) T(v); }

    // destroy the T in p
    void destroy(T* p) { p->~T(); }
};

//------------------------------------------------------------------------------

// allocate space for n objects of type T
template<class T> T* allocatr<T>::allocate(int n)
{
    T* p = static_cast<T*>(malloc(n*sizeof(T)));
    if (p==0) error("allocate: could not allocate memory");
    return p;
}

//------------------------------------------------------------------------------

template<class T, class A = allocatr<T> > class vectr {
    A alloc;    // used to handle memory for elements
    int sz;     // the size
    T* elem;    // a pointer to the elements
    int space;  // space + free space
public:
    typedef unsigned long size_type;
    typedef T value_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    class iterator_rc;

    vectr() : sz(0), elem(0), space(0) { }
    explicit vectr(size_type s);

    vectr(const vectr&);                        // copy constructor
    vectr& operator=(const vectr&);             // copy assignment

    ~vectr();                                   // destructor

    T& operator[](size_type n) { return elem[n]; }    // access; return reference
    const T& operator[](size_type n) const { return elem[n]; }

    T& at(size_type n);
    const T& at(size_type n) const;                   // checked access

    iterator begin() { return elem; }
    iterator end() { return elem+sz; }

    size_type size() const { return sz; }             // the current size
    size_type capacity() const { return space; }

    void resize(size_type newsize, T val = T());      // growth
    void push_back(const T& d);
    void reserve(size_type newalloc);

};

//------------------------------------------------------------------------------

template<class T, class A>
class vectr<T,A>::iterator_rc {
    iterator curr;
    iterator first;
    iterator last;
public:
    iterator_rc(iterator c , iterator f, iterator l)
        : curr(c), first(f), last(l) { }

    T& operator*() { return *curr; }
    const T& operator*() const { return *curr; }

    iterator_rc& operator++();
    iterator_rc& operator--();
    iterator_rc& operator+=(size_type n);
    friend iterator_rc operator+(iterator_rc it, size_type n)
        { it += n; return it; }
    iterator_rc& operator-=(size_type n);
    friend iterator_rc operator-(iterator_rc it, size_type n)
        { it -= n; return it; }
    friend size_type operator-(const iterator_rc& it1, const iterator_rc& it2)
        { return (it1.curr - it2.curr); }

    bool operator ==(iterator_rc const& other) const { return curr==other.curr; }
    bool operator !=(iterator_rc const& other) const { return !(*this==other); }
};

//------------------------------------------------------------------------------

template<class T, class A>
typename vectr<T,A>::iterator_rc& vectr<T,A>::iterator_rc::operator++()
{
    if (curr==last-1) throw Range_error(last-first);
    ++curr;
    return *this;
}

//------------------------------------------------------------------------------

template<class T, class A>
typename vectr<T,A>::iterator_rc& vectr<T,A>::iterator_rc::operator--()
{
    if (curr==first) throw Range_error(-1);
    --curr;
    return *this;
}

//------------------------------------------------------------------------------

template<class T, class A>
typename vectr<T,A>::iterator_rc& vectr<T,A>::iterator_rc::operator+=(size_type n)
{
    if (n >= (last-curr)) throw Range_error(curr+n-first);
    curr += n;
    return *this;
}

//------------------------------------------------------------------------------

template<class T, class A>
typename vectr<T,A>::iterator_rc& vectr<T,A>::iterator_rc::operator-=(size_type n)
{
    if (n > curr-first) throw Range_error(curr-n-first);
    curr -= n;
}

//------------------------------------------------------------------------------

template<class T, class A> vectr<T,A>::vectr(size_type s)
    : sz(s), elem(alloc.allocate(s)), space(s)
{
    for (int i = 0; i<sz; ++i)
        alloc.construct(&elem[i],T());
}

//------------------------------------------------------------------------------

template<class T, class A> vectr<T,A>::vectr(const vectr& a)
    : sz(a.sz), elem(alloc.allocate(a.sz)), space(a.sz)
{
    for (int i = 0; i<sz; ++i)
        alloc.construct(&elem[i],a.elem[i]);
}

//------------------------------------------------------------------------------

template<class T, class A>
vectr<T,A>& vectr<T,A>::operator=(const vectr<T,A>& a)
{
    if (this==&a) return *this; // self-assignment, no work needed

    if (a.sz<=space) {          // enough space, no need for new allocation
        for (int i = 0; i<a.sz; ++i)
            alloc.construct(&elem[i],a.elem[i]);
        sz = a.sz;
        return *this;
    }

    T* p = alloc.allocate(a.sz);            // allocate new space
    for (int i = 0; i<a.sz; ++i)            // copy elements
        alloc.construct(&p[i],a.elem[i]);
    for (int i = 0; i<sz; ++i)              // destroy old objects
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem);                 // deallocate old space
    space = sz = a.sz;                      // set new size
    elem = p;                               // set new elements
    return *this;
}

//------------------------------------------------------------------------------

template<class T, class A> vectr<T,A>::~vectr()
{
    for (int i = 0; i<sz; ++i)
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem);
}

//------------------------------------------------------------------------------

template<class T, class A> T& vectr<T,A>::at(size_type n)
{
    if (n<0 || sz<=n) throw Range_error(n);
    return elem[n];
}

//------------------------------------------------------------------------------

template<class T, class A> void vectr<T,A>::resize(size_type newsize, T val)
{
    reserve(newsize);
    for (int i = sz; i<newsize; ++i)    // construct
        alloc.construct(&elem[i],val);
    for (int i = newsize; i<sz; ++i)    // destroy
        alloc.destroy(&elem[i]);
    sz = newsize;
}

//------------------------------------------------------------------------------

template<class T, class A> void vectr<T,A>::push_back(const T& val)
{
    if (space==0) reserve(8);               // start with space for 8 elements
    else if (sz==space) reserve(2*space);   // get more space
    alloc.construct(&elem[sz],val);         // add val at end
    ++sz;                                   // increase the size
}

//------------------------------------------------------------------------------

template<class T, class A> void vectr<T,A>::reserve(size_type newalloc)
{
    if (newalloc<=space) return;        // never decrease allocation
    T* p = alloc.allocate(newalloc);    // allocate new space
    for (int i = 0; i<sz; ++i)          // copy
        alloc.construct(&p[i],elem[i]);
    for (int i = 0; i<sz; ++i)          // destroy
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem);             // deallocate old space
    elem = p;
    space = newalloc;
}

//------------------------------------------------------------------------------

int main()
try {
    vectr<int> vi;
    for (int i = 0; i<5; ++i)
        vi.push_back(i);

    cout << "Size of vector: " << vi.size() << "\n";

    for (int i = 0; i<vi.size(); ++i)
        cout << vi[i] << ' ';
    cout << "\n";

    vectr<int>::iterator_rc it(vi.begin(),vi.begin(),vi.end());
    cout << *it << "\n";
    ++it;
    cout << *it << "\n";
    --it;
    cout << *it << "\n";
//    --it;   // throws error
    it += 4;
    cout << *it << "\n";
//    ++it;   // throws error
//    it += 1;    // throws error
//    it = it + 1;    // throws error
//    it -= 5;    // throws error
//    it = it - 5;    // throws error
    vectr<int>::iterator_rc it2(vi.begin(),vi.begin(),vi.end());
    int dist = it - it2;
    cout << "Distance to begin(): " << dist << "\n";
    cout << "it==it2 is " << (it==it2 ? "true" : "false") << "\n";
    cout << "it!=it2 is " << (it!=it2 ? "true" : "false") << "\n";
    it -= 4;
    cout << "it==it2 is " << (it==it2 ? "true" : "false") << "\n";
    cout << "it!=it2 is " << (it!=it2 ? "true" : "false") << "\n";

}
catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

//------------------------------------------------------------------------------
