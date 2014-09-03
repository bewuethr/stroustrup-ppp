
//
// This is example code from Chapter 19.3.1 "Types as template parameters" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <string>

using std::string;

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

    void resize(int newsize);         // growth
    void push_back(const T& d);
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------


int main()
{
    vector<double> vd;                // T is double
    vector<int> vi;                   // T is int 
    vector<double*> vpd;              // T is double*
    vector< vector<int> > vvi;        // T is vector<int>, in which T is int
}

//------------------------------------------------------------------------------

class vector_char {
    int sz;        // the size
    char* elem;    // a pointer to the elements
    int space;     // size+free_space
public:
    vector_char();
    vector_char(int s);

    vector_char(const vector_char&);             // copy constructor
    vector_char& operator=(const vector_char &); // copy assignment

    ~vector_char ();                             // destructor

    char& operator[ ] (int n);                   // access: return reference
    const char& operator[ ] (int n) const;  

    int size() const ;                           // the current size
    int capacity() const;

    void resize(int newsize);                    // growth
    void push_back(const char& d);
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

void fct(vector<string>& v)
{
    int n = v.size();
    v.push_back("Norah");
    // ...
}

//------------------------------------------------------------------------------

template<class T> void vector<T>::push_back(const T& d) { /* ... */ };

//------------------------------------------------------------------------------
