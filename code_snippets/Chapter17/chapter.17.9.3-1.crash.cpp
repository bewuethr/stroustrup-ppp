
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

Link* insert(Link* p, Link* n)    // insert n before p (incomplete)
{
    n->succ = p;        // p comes after n
    p->prev->succ = n;  // n comes after what used to be p's predecessor
    n->prev = p->prev;  // p's predecessor becomes n's predecessor
    p->prev = n;        // n becomes p's predecessor
    return n;
}

//------------------------------------------------------------------------------

int main()
{
    Link* norse_gods = new Link("Thor",0,0);
    norse_gods = new Link("Odin",norse_gods,0);
    norse_gods->succ->prev = norse_gods; 
    norse_gods = new Link("Freia",norse_gods,0);
    norse_gods->succ->prev = norse_gods;
}

//------------------------------------------------------------------------------
