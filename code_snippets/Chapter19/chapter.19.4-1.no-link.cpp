
//
// This is example code from Chapter 19.4 "Range checking and exceptions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using std::cin;

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

    T& operator[ ] (int n);           // access: return reference
    const T& operator[ ] (int n) const;

    int size() const { return sz; }   // the current size
    int capacity() const { return space; }
};

//------------------------------------------------------------------------------

template<class T, class A> T& vector<T,A>::operator[ ](int n)
{
    return elem[n];
}

//------------------------------------------------------------------------------

int main()
{
    vector<int> v(100);
    v[-200] = v[200];         // oops!
    int i;
    cin>>i;
    v[i] = 999;               // maul an arbitrary memory location
}

//------------------------------------------------------------------------------
