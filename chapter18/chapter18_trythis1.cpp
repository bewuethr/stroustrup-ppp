// Chapter 18, Try This 1

//
// This is example code from Chapter 18.3.1 "Debugging constructors and destructors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

struct X {    // simple test class
    int val;

    void out(const string& s)
    { cerr << this <<  "->" << s << ": " << val << "\n"; }

    X(){ out("X()"); val=0; }
    X(int v) { out( "X(int)"); val=v; }
    X(const X& x){ out("X(X&)"); val=x.val; }
    X& operator=(const X& a) { out("X::operator=()"); val=a.val; return *this; }
    ~X() { out("~X()"); }
};

//------------------------------------------------------------------------------

X glob(2);                                  // glob->X(int): 0

X copy(X a) { return a; }

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

//------------------------------------------------------------------------------

int main()
{
    cout << "\n";

    X x;                    // x->X(): ?
    cout << "\n";

    X loc(4);               // loc->X(int): ?
    cout << "\n";

    X loc2 = loc;           // loc2->X(X&): ?
    cout << "\n";

    loc = X(5);             // X(int): ?, loc->X::operator=(): 4, ~X(): 5
    cout << "\n";

    loc2 = copy(loc);       // a->X(X&): ?, a->X(X&): ?, a->~X(): 5, loc2->X::operator=(): 4, a->~X(): 5
    cout << "\n";

    loc2 = copy2(loc);      // a->X(X&): ?, aa->X(X&): ?, aa->X(X&): ?, a->~X(): 5, a->~X(): 5, loc2->X::operator=(): 5, aa->~X(): 5
    cout << "\n";

    X loc3(6);              // loc3->X(int): ?
    cout << "\n";

    X& r = ref_to(loc3);    // nothing at all, only references created
    cout << "\n";

    delete make(7);         // a->X(int): ?, new->X(X&): ?, a->~X(): 7, new->~X(): 7
    cout << "\n";

    delete make(8);         // a->X(int): ?, new->X(X&): ?, a->~X(): 8, new->~X(): 8
    cout << "\n";

    vector<X> v(4);         // v[0]->X(): ?, v[1]->X(): ?, v[2]->X(): ?, v[3]->X(): ?
    cout << "\n";

    XX loc4;                // loc4.a->X(): ?, loc4.b->X(): ?
    cout << "\n";

    X* p = new X(9);        // p->X(int): ?
    cout << "\n";

    delete p;               // p->~X(): 9
    cout << "\n";

    X* pp = new X[5];       // pp[0]->X(): ?, ..., pp[4]->X(): ?
    cout << "\n";

    delete[] pp;            // pp[4]->~X(): 0, ..., pp[0]->~X(): 0
}

//------------------------------------------------------------------------------
