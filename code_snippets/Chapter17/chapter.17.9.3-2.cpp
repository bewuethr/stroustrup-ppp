
//
// This is example code from Chapter 17.9.3 "An example: Lists" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Link {
    string value;
    Link* prev;
    Link* succ;
    Link(const string& v, Link* p = 0, Link* s = 0)
        : value(v), prev(p), succ(s) { }
};

//------------------------------------------------------------------------------

Link* insert(Link* p, Link* n)    // insert n before p; return n
{
    if (n==0) return p;
    if (p==0) return n;
    n->succ = p;        // p comes after n
    if (p->prev) p->prev->succ = n;
    n->prev = p->prev;    // p's predecessor becomes n's predecessor
    p->prev = n;        // n becomes p's predecessor
    return n;
}

//------------------------------------------------------------------------------

int main()
{
    Link* norse_gods = new Link("Thor");
    norse_gods = insert(norse_gods,new Link("Odin"));
    norse_gods = insert(norse_gods,new Link("Freia"));
}

//------------------------------------------------------------------------------
