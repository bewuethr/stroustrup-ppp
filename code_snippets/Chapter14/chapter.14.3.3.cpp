
//
// This is example code from Chapter 14.3.3 "Overriding" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

struct B {
    virtual void f() const { cout << "B::f  "; }
    void g() const { cout << "B::g  "; }  // not virtual
};

//------------------------------------------------------------------------------

struct D : B {
    void f() const { cout << "D::f  "; }  // overrides B::f
    void g() { cout << "D::g  "; }
};

//------------------------------------------------------------------------------

struct DD : D {
    void f() { cout << "DD::f  "; }       // doesn't override D::f (not const)
    void g() const { cout << "DD::g  "; }
};

//------------------------------------------------------------------------------

void call(const B& b)
    // a D is a kind of B, so call() can accept a D
    // a DD is a kind of D and a D is a kind of B, so call() can accept a DD
{
    b.f();
    b.g();
}

//------------------------------------------------------------------------------

int main()
try
{
    B b;
    D d;
    DD dd;

    call(b);
    call(d);
    call(dd);

    b.f();
    b.g();

    d.f();
    d.g();

    dd.f();
    dd.g();
}
catch(exception& e) {
    // some error reporting
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}

//------------------------------------------------------------------------------
