
//
// This is example code from Chapter 19.3.5 "Template argument deduction" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

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

array<char,1024> buf;    // for buf, T is char and N is 1024
array<double, 10> b2;    // for b2, T is double and N is 10

template<class T, int N> void fill(array<T,N>& b, const T& val)
{
    for (int i = 0; i<N; ++i) b[i] = val;
}

//------------------------------------------------------------------------------

void f()
{
    fill(buf, 'x');      // for fill(), T is char and N is 1024
                         // because that's what buf has
    fill(b2,0.0);        // for fill(), T is double and N is 10
                         // because that's what b2 has
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
