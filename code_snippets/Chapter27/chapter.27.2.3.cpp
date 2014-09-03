
//
// This is example code from Chapter 27.2.3 "Calling C from C++ and C++ from C" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

// calling C function from C++:

extern "C" double sqrt(double);    // link as a C function

//------------------------------------------------------------------------------

void my_c_plus_plus_fct()
{
    double sr = sqrt(2);
}

//------------------------------------------------------------------------------

struct S
{
    int f(int n) const { return n*n; }
};

//------------------------------------------------------------------------------

// C++ function callable from C:

extern "C" int call_f(S* p, int i)
{
    return p->f(i);
}

//------------------------------------------------------------------------------

/* call C++ function from C: */

int call_f(S* p, int i);
struct S* make_S(int,const char*); 

void my_c_fct(int i)
{
    /* ... */
    struct S* p = make_S(i, "foo");
    int x = call_f(p,i);
    /* ... */
}

//------------------------------------------------------------------------------

#ifdef __cplusplus

// in C++:
class complex {
    double re, im;
public:
    // all the usual operations
};

#else

/* in C: */
struct complex {
    double re, im;
    /* no operations */
};

#endif 

//------------------------------------------------------------------------------

int main()
{
    my_c_fct(42);
}

//------------------------------------------------------------------------------

struct S* make_S(int,const char*)
{
    return new S;
}

//------------------------------------------------------------------------------
