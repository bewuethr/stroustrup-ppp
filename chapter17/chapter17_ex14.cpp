// Chapter 17, exercise 14: complete the "list of gods" example from 17.10.1,
// but this time as a sinlgy-linked list

#include "../lib_files/std_lib_facilities.h"

struct List;

class Link {
public:
    string value;

    Link(const string& v, Link* s = 0)
        : value(v), succ(s) { }

    Link* insert(List& l, Link* n);                         // insert n before this object
    Link* add(Link* n);                                     // insert n after this object
    Link* erase(List& l);                                   // remove this object from the list
    Link* find(const List& l, const string& s);             // find s in list
    const Link* find(const List& l, const string& s) const; // find s in const list

    Link* advance(int n) const; // move n positions in list

    Link* next() const { return succ; }
private:
    Link* succ;
};

struct List {
    List() : first_link(0) { }
    List(Link* l) : first_link(l) { }
    Link* first_link;
};

// insert n before this object
Link* Link::insert(List& l, Link* n) {
    if (n==0) return this;
    if (this==0) return n;
    n->succ = this;
    if (l.first_link == this) {
        l.first_link = n;
        return n;
    }
    Link* p = l.first_link;
    while (p->succ != this)
        p = p->succ;
    p->succ = n;
    return n;
}

// insert n after this object
Link* Link::add(Link* n) {
    if (n==0) return this;
    if (this==0) return n;
    n->succ = succ;
    succ = n;
    return n;
}

// erase this object, return successor
Link* Link::erase(List& l) {
    if (this==0) return 0;
    if (l.first_link == this) {
        l.first_link = succ;
    }
    Link* p = l.first_link;
    while (p->succ != this)
        p = p->succ;
    p->succ = succ;
    return succ;
}

// find s in list; return 0 for "not found"
Link* Link::find(const List& l, const string& s) {
    Link* p = l.first_link;
    while (p) {
        if (p->value==s) return p;
        p = p->succ;
    }
    return 0;
}

// find s in const list; return 0 for "not found"
const Link* Link::find(const List& l, const string& s) const {
    const Link* p = l.first_link;
    while (p) {
        if (p->value==s) return p;
        p = p->succ;
    }
    return 0;
}

// move n positions in list, return 0 for "not found"
// positive n moves forward
Link* Link::advance(int n) const {
    if (this==0) return 0;
    Link* p = const_cast<Link*>(this);  // UGLY
    if (0 <= n) {
        while (n--) {
            if (p->succ==0) return 0;
            p = p->succ;
        }
    }
    else error("must advance by a positive number");
    return p;
}

void print_all(const List& l)
{
    cout << "{ ";
    Link* p = l.first_link;
    while (p) {
        cout << p->value;
        if (p=p->next()) cout << ", ";
    }
    cout << " }";
}


int main()
try {
    Link* norse_gods = new Link("Thor");
    List n_gods(norse_gods);
    norse_gods = norse_gods->insert(n_gods, new Link("Odin"));
    norse_gods = norse_gods->insert(n_gods, new Link("Zeus"));
    norse_gods = norse_gods->insert(n_gods, new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    List g_gods(greek_gods);
    greek_gods = greek_gods->insert(g_gods,new Link("Athena"));
    greek_gods = greek_gods->insert(g_gods,new Link("Mars"));
    greek_gods = greek_gods->insert(g_gods,new Link("Poseidon"));

    Link* p = greek_gods->find(g_gods,"Mars");
    if (p) p->value = "Ares";

    Link* p2 = norse_gods->find(n_gods,"Zeus");
    if (p2) {
        if (p2==norse_gods) norse_gods = p2->next();
        p2->erase(n_gods);
        greek_gods->add(p2);
        greek_gods = g_gods.first_link;
    }

    print_all(n_gods);
    cout << "\n";

    print_all(g_gods);
    cout << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
