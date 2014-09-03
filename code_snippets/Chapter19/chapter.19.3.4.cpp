
//
// This is example code from Chapter 19.3.4 "Integers as template parameters" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

//------------------------------------------------------------------------------

template<class T, int N> struct array {
    T elem[N];                  // hold elements in member array

    // rely on the default constructors, destructor, and assignment

    T& operator[ ] (int n) { return elem[n]; } // access: return reference
    const T& operator[ ] (int n) const { return elem[n]; }

    T* data() { return elem; }  // conversion to T*
    const T* data() const { return elem; }

    int size() const  { return N; }    
};

//------------------------------------------------------------------------------

array<int,256> gb;          // 256 integers
array<double,6> ad = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5 };    // note the initializer!
const int max = 1024;

void some_fct(int n)
{
    array<char,max> loc;
    //array<char,n> oops;         // error: the value of n not known to compiler
    // ...
    array<char,max> loc2 = loc; // take backup copy
    // ...
    loc = loc2;                 // restore
    // ...
}

//------------------------------------------------------------------------------

template<class C> void printout(const C& c)
{
    for(int i = 0; i<c.size(); ++i) cout << c[i] <<'\n';
}

//------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    //double* p = ad;             // error: no implicit conversion to pointer
    double* q = ad.data();      // ok: explicit conversion

    printout(ad);               // call with array
    vector<int> vi;
    // ...
    printout(vi);               // call with vector
}

//------------------------------------------------------------------------------
