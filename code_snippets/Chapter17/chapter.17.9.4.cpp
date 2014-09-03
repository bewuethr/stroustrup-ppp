
//
// This is example code from Chapter 17.9.4 "List operations" of
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

Link* add(Link* p, Link* n)   // insert n after p; return n
{
    // much like insert (see exercise 11)
    return insert(p,n);
}

//------------------------------------------------------------------------------

Link* erase(Link* p)          // remove *p from list; return p's successor
{
    if (p==0) return 0;
    if (p->succ) p->succ->prev = p->prev;
    if (p->prev) p->prev->succ = p->succ;
    return p->succ;
}

//------------------------------------------------------------------------------

Link* find(Link* p, const string& s) // find s in list;
                                     // return 0 for "not found"
{
    while(p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return 0;
}

//------------------------------------------------------------------------------

Link* advance(Link* p, int n) // move n positions in list
                              // return 0 for "not found"
                              // positive n moves forward; negative backwards
{
    if (p==0) return 0;
    if (0<n) {
        while (n--) {
            if (p->succ == 0) return 0;
            p = p->succ;
        }
    }
    if (n<0) {
        while (n++) {
            if (p->prev == 0) return 0;
            p = p->prev;
        }
    }
    return p;
}

//------------------------------------------------------------------------------

int main()
{
    Link* norse_gods = new Link("Thor");
    norse_gods = insert(norse_gods,new Link("Odin"));
    norse_gods = insert(norse_gods,new Link("Zeus"));
    norse_gods = insert(norse_gods,new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    greek_gods = insert(greek_gods,new Link("Athena")); 
    greek_gods = insert(greek_gods,new Link("Mars"));
    greek_gods = insert(greek_gods,new Link("Poseidon"));

    Link* p = find(greek_gods, "Mars");
    if (p) p->value = "Ares";

    // Similarly, we can move Zeus into his correct Pantheon:
    {
        Link* p = find(norse_gods,"Zeus");
        if (p) {
            erase(p);
            insert(greek_gods,p);
        }
    }

    // Without subtle bug above
    {
        Link* p = find(norse_gods, "Zeus");
        if (p) {
            if (p==norse_gods) norse_gods = p->succ;
            erase(p);
            greek_gods = insert(greek_gods,p);
        }
    }
}

//------------------------------------------------------------------------------
