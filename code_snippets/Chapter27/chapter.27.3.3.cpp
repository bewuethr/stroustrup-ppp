
//
// This is example code from Chapter 27.3.3 "Definitions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

struct S {};

//------------------------------------------------------------------------------

struct S* next(struct S* p) { return p; }

//------------------------------------------------------------------------------

int main()
{
    const int max = 10;
    int x[max];
    int y[max];
    struct S* q = 0;

    // C++ allows definitions in more places than C. For example:
    for (int i = 0; i<max; ++i) x[i] = y[i];    // definition of i not allowed in C

    while (struct S* p = next(q)) {        // definition of p not allowed in C
        /* ... */
    }

    int i;
    for (i = 0; i<max; ++i) x[i] = y[i];

    struct S* p;
    while (p = next(q)) {
        /* ... */
    }
}

//------------------------------------------------------------------------------

extern void error(const char*) {}
const int max = 10;

//------------------------------------------------------------------------------

#ifdef __cplusplus

void f(int i)
{
    if (i< 0 || max<=i) error("range error");
    int a[max];    // declaration after statement not allowed in C
    /* ... */
}

#else

void f(int i)
{
    if (i< 0 || max<=i) error("range error");
    {
        int a[max];
        /* ... */
    }
}

int x;
int x;  /* defines or declares a single integer called x in C; error in C++ */

#endif

//------------------------------------------------------------------------------
