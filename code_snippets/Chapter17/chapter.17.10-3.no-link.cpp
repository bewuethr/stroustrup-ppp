
//
// This is example code from Chapter 17.10 "The this pointer" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Link {
public:
    string value; 

    Link(const string& v, Link* p = 0, Link* s = 0)
        : value(v), prev(p), succ(s) { }

    Link* insert(Link* n) ;   // insert n before this object
    Link* add(Link* n) ;      // insert n after this object
    Link* erase() ;           // remove this object from list
    Link* find(const string& s);    // find s in list
    const Link* find(const string& s) const; // find s in list

    Link* advance(int n) const;     // move n positions in list

    Link* next() const { return succ; }
    Link* previous() const { return prev; }
private:
    Link* prev;
    Link* succ;
};

//------------------------------------------------------------------------------

Link* Link::insert(Link* n)   // insert n before this object; return n
{
    if (n==0) return this;
    if (this==0) return n;
    n->succ = this;           // this object comes after n
    if (prev) prev->succ = n;
    n->prev = prev;           // this object's predecessor becomes n's predecessor
    prev = n;                 // n becomes this object's predecessor
    return n;
}

//------------------------------------------------------------------------------
