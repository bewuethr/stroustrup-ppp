
//
// This is example code from Chapter 21.4.1 "An abstract view of function objects" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

typedef int S;
typedef double T;

//------------------------------------------------------------------------------

class F { // abstract example of a function object
    S s;  // state
public:
    F(const S& ss) :s(ss) { /* establish initial state */ }
    T operator() (const S& ss) const
    {
        // do something with ss to s
        // return a value of type T (T is often void, bool or S)
        return ss*ss;
    }

    const S& state() const { return s; } // reveal state
    void reset(const S& ss) { s = ss; }  // reset state
};

//------------------------------------------------------------------------------

int main()
{
    S s = 0;
    F f(s); // create F
    f(s);   // apply  f
}

//------------------------------------------------------------------------------
