
//
// This is example code from Chapter 8.4 "Scope" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int g(int x)        // g is global; x is local to g
{
    int f = x+2;    // f is local
    return 2*f; 
}

//------------------------------------------------------------------------------

int x;    // global variable - avoid those where you can
int y;

class C {
public:
    struct M { 
        // ...
    }; 
    // ...
};

//------------------------------------------------------------------------------

void f()
{
    class L {
        // ...
    };
    // ...

    //void g()    // illegal
    //{
    //    // ...
    //}
    // ...

}

//------------------------------------------------------------------------------

void f1(int x, int y)
{
    if (x>y) {
        // ...
    }
    else {
        // ...
        {
            // ...
        }
        // ...
    }
}

//------------------------------------------------------------------------------

// dangerously ugly code:
struct X {
void f(int x) {
struct Y {
int f() { return 1; } int m; };
int m;
m=x; Y m2;
return f(m2.f()); }
int m; void g(int m) {
if (m) f(m+2); else {
g(m+2); }}
X() { } void m3() {
}

void main() {
X a; a.f(2);}
};

int main()
{
    g(0);
    f();
    f1(0,1);

    X x;
    x.main();
    x.m3();
}

//------------------------------------------------------------------------------
