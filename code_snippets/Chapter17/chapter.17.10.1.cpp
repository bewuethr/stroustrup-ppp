
//
// This is example code from Chapter 17.10.1 "More link use" of
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

Link* Link::erase()          // remove this object from the list; return this's successor
{
    if (this==0) return 0;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

//------------------------------------------------------------------------------

Link* Link::find(const string& s) // find s in list;
// return 0 for "not found"
{
    Link* p = this;
    while(p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return 0;
}

//------------------------------------------------------------------------------

void print_all(Link* p)
{
    cout << "{ ";
    while (p) {
        cout << p->value;
        if (p=p->next()) cout <<  ", ";
    }
    cout << " }";
}

//------------------------------------------------------------------------------

int main()
{
    Link* norse_gods = new Link("Thor");
    norse_gods = norse_gods->insert(new Link("Odin"));
    norse_gods = norse_gods->insert(new Link("Zeus"));
    norse_gods = norse_gods->insert(new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    greek_gods = greek_gods->insert(new Link("Athena")); 
    greek_gods = greek_gods->insert(new Link("Mars"));
    greek_gods = greek_gods->insert(new Link("Poseidon"));

    Link* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";

    // Move Zeus into his correct Pantheon: 
    {
        Link* p = norse_gods->find("Zeus");
        if (p) {
            if (p==norse_gods) norse_gods = p->next();
            p->erase();
            greek_gods = greek_gods->insert(p);
        }
    }

    // Finally, let's print out those lists:

    print_all(norse_gods);
    cout<<"\n";

    print_all(greek_gods);
    cout<<"\n";
}

//------------------------------------------------------------------------------
