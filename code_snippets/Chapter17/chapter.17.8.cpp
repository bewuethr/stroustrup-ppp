
//
// This is example code from Chapter 17.8 "Messing with types: void* and casts" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------
//void v;      // error: there are no objects of type void
void f();    // f() returns nothing - f() does not return an object of type void

//------------------------------------------------------------------------------

int main()
{
    void* pv1 = new int;        // ok: int* converts to void*
    void* pv2 = new double[10]; // ok: double* converts to void*
}

//------------------------------------------------------------------------------

void f(void* pv)
{
    void* pv2 = pv;   // copying is ok (copying is what void*s are for)
    //double* pd = pv;  // error: cannot convert void* to double*
    //*pv = 7;          // error: cannot dereference a void*
                      // (we don't know what type of  object it points to)
    //pv[2] = 9;        // error: cannot subscript a void*
    int* pi = static_cast<int*>(pv);    // ok: explicit conversion
                      // ...
}

//------------------------------------------------------------------------------

struct Register;
struct Buffer;

Register* in = reinterpret_cast<Register*>(0xff);

//------------------------------------------------------------------------------

void f(const Buffer* p)
{
    Buffer* b = const_cast<Buffer*>(p);
    // ...
}

//------------------------------------------------------------------------------
