
//
// This is example code from Chapter 19.3.6 "Generalizing vector" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------
// an almost real vector of Ts:
template<class T> class vector {      // read "for all types T" (just like in math)
    int sz;                           // the size
    T* elem;                          // a pointer to the elements
    int space;                        // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }    
    vector(int s);

    vector(const vector&);            // copy constructor
    vector& operator=(const vector&); // copy assignment

    ~vector() { delete[ ] elem; }     // destructor

    T& operator[ ] (int n) { return elem[n]; } // access: return reference
    const T& operator[ ] (int n) const { return elem[n]; }  

    int size() const { return sz; }   // the current size
    int capacity() const { return space; }

    void resize(int newsize, T def = T()); // growth
    void push_back(const T& d);
    void reserve(int newalloc);
};

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
