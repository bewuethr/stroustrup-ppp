
//
// This is example code from Chapter 19.4 "Range checking and exceptions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;

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

struct out_of_range { /* ... */ }; // class used to report range access errors

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

    T& at(int n);                     // checked access    
    const T& at(int n) const;         // checked access

    T& operator[ ](int n);            // unchecked access
    const T& operator[ ](int n) const;// unchecked access

    int size() const { return sz; }   // the current size
    int capacity() const { return space; }
};

//------------------------------------------------------------------------------

template<class T, class A >  T& vector<T,A>::at(int n)
{
    if (n<0 || sz<=n) throw out_of_range();
    return elem[n];
}

//------------------------------------------------------------------------------

template<class T, class A >  T& vector<T,A>::operator[ ](int n) // as before
{
    return elem[n];
}

//------------------------------------------------------------------------------

void print_some(vector<int>& v)
{
    int i = -1;
    cin >> i;
    while(i!= -1) try {
        cout << "v[" << i << "]==" << v.at(i) << "\n";
    }
    catch(out_of_range) {
        cout << "bad index: " << i << "\n";
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    vector<int> v(10);
    print_some(v);
}
catch (std::exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
