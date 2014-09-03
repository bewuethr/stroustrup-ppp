
//
// This is example code from Chapter 18.3.1 "Debugging constructors and destructors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct X {    // simple test class
    int val;

    void out(const string& s)
    { cerr << this <<  "->" << s << ": " << val << "\n"; }

    X(){ out("X()"); val=0; }
    X(int v) { out( "X(int)"); val=v; }
    X(const X& x){ out("X(X&) "); val=x.val; }
    X& operator=(const X& a) { out("X::operator=()"); val=a.val; return *this; }
    ~X() { out("~X()"); }
};

//------------------------------------------------------------------------------

X glob(2);            // a global variable

X copy(X a) { return a; }

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

//------------------------------------------------------------------------------

int main()
{
    X loc(4);        // local variable
    X loc2 = loc;
    loc = X(5);
    loc2 = copy(loc); 
    loc2 = copy2(loc);
    X loc3(6);
    X& r = ref_to(loc3);
    delete make(7); 
    delete make(8);
    vector<X> v(4); 
    XX loc4;
    X* p = new X(9);    // an X on the free store
    delete p;
    X* pp = new X[5];    // an array of Xs on the free store
    delete[] pp;
}

//------------------------------------------------------------------------------
