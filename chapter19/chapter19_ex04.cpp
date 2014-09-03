// Chapter 19, exercise 04: modify Link class from §17.9.3 to be a template with
// the type of value as the template argument, then redo exercise 13 from
// Chapter 17 with Link<God>.

// Chapter 17, exercise 13 was: modify Link class to hold a value of struct God
// with string members name, mythology, vehicle and weapon. Write print_all()
// function that lists gods with attributes one per line. Add member function
// add_ordered() that places its new element at its correct lexicographic
// position. Make list of gods from three mythologies, then move elements to
// three ordered lists, one per mythology.

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

struct God {
    God(const string& n, const string& m, const string& v, const string& w)
        : name(n), mythology(m), vehicle(v), weapon(w) { }
    string name;
    string mythology;
    string vehicle;
    string weapon;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const God& g)
{
    os << g.name << ": " << g.mythology << ", "
        << g.vehicle << ", " << g.weapon;
    return os;
}

//------------------------------------------------------------------------------

bool operator==(const God& g1, const God& g2)
{
    return (g1.name==g2.name && g1.mythology==g2.mythology
        && g1.vehicle==g2.vehicle && g1.weapon==g2.weapon);
}

//------------------------------------------------------------------------------

bool operator!=(const God& g1, const God& g2)
{
    return !(g1==g2);
}

//------------------------------------------------------------------------------

bool operator<(const God& g1, const God& g2)
{
    return g1.name<g2.name;
}

//------------------------------------------------------------------------------

bool operator>(const God& g1, const God& g2)
{
    return g2<g1;
}

//------------------------------------------------------------------------------

bool operator<=(const God& g1, const God& g2)
{
    return !(g1>g2);
}

//------------------------------------------------------------------------------

bool operator>=(const God& g1, const God& g2)
{
    return !(g1<g2);
}

//------------------------------------------------------------------------------

template<class T> struct Link {
    T value;
    Link* prev;
    Link* succ;
    Link(const T& v, Link* p = 0, Link* s = 0)
        : value(v), prev(p), succ(s) { }
};

//------------------------------------------------------------------------------

// insert n before p; return n
template<class T> Link<T>* insert(Link<T>* p, Link<T>* n)
{
    if (n==0) return p;
    if (p==0) return n;
    n->succ = p;
    if (p->prev) p->prev->succ = n;
    n->prev = p->prev;
    p->prev = n;
    return n;
}

//------------------------------------------------------------------------------

// insert n after p; return n
template<class T> Link<T>* add(Link<T>* p, Link<T>* n)
{
    if (n==0) return p;
    if (p==0) return n;
    n->prev = p;
    if (p->succ) p->succ->prev = n;
    n->succ = p->succ;
    p->succ = n;
    return n;
}

//------------------------------------------------------------------------------

// insert element n at lexicographically correct place, return first element of
// list
template<class T> Link<T>* add_ordered(Link<T>* p, Link<T>* n)
{
    if (n==0) return p;
    if (p==0) return n;
    while (n->value > p->value && p->succ) {
        p = p->succ;
    }

    // p points now to first element with value bigger than value of n or the
    // last element of the list
    if (n->value > p->value) p = add(p,n);
    else p = insert(p,n);

    // traverse list to return first element
    while (p->prev) p = p->prev;
    return p;
}

//------------------------------------------------------------------------------

// remove *p from list; return p's successor
template<class T> Link<T>* erase(Link<T>* p)
{
    if (p==0) return 0;
    if (p->succ) p->succ->prev = p->prev;
    if (p->prev) p->prev->succ = p->succ;
    Link<T>* temp = p->succ;
    p->prev = 0;
    p->succ = 0;
    return temp;
}

//------------------------------------------------------------------------------

// find v in list; return 0 for "not found"
template<class T> Link<T>* find(Link<T>* p, const T& v)
{
    while (p) {
        if (p->value==v) return p;
        p = p->succ;
    }
    return 0;
}

//------------------------------------------------------------------------------

// move n positions in list, return 0 for "not found"
// positive n moves forward, negative backward
template<class T> Link<T>* advance(Link<T>* p, int n)
{
    if (p==0) return 0;
    if (0<n) {
        while (n--) {
            if (p->succ==0) return 0;
            p = p->succ;
        }
    }
    else if (n<0) {
        while (n++) {
            if (p->prev==0) return 0;
            p = p->prev;
        }
    }
    return p;
}

//------------------------------------------------------------------------------

template<class T> void print_all(Link<T>* p)
{
    while (p) {
        cout << p->value << "\n";
        p = p->succ;
    }
}

//------------------------------------------------------------------------------

// find given link in list, erase it and add it lexicographically into another
// list, return pointer to first element of new list
template<class T> Link<T>* move(Link<T>* from, Link<T>* to, const T& d)
{
    Link<T>* temp = find(from,d);
    erase(temp);
    return add_ordered(to,temp);
}

//------------------------------------------------------------------------------

int main()
try {
    Link<God>* all_gods = new Link<God>(God("Thor","Norse",
        "Pinzgauer","Hammer"));
    all_gods = insert(all_gods,new Link<God>(God("Odin","Norse",
        "Eight-legged horse","")));
    all_gods = insert(all_gods,new Link<God>(God("Zeus","Greek",
        "","Lightning")));
    all_gods = insert(all_gods,new Link<God>(God("Freia","Norse",
        "F-transport","F-weapon")));
    all_gods = insert(all_gods,new Link<God>(God("Hera","Greek",
        "H-transport","Spear")));
    all_gods = insert(all_gods,new Link<God>(God("Athena","Greek",
        "A-transport","A-weapon")));
    all_gods = insert(all_gods,new Link<God>(God("Mars","Roman",
        "M-transport","M-weapon")));
    all_gods = insert(all_gods,new Link<God>(God("Poseidon","Greek",
        "Seahorse","Trident")));
    all_gods = insert(all_gods,new Link<God>(God("Ares","Greek",
        "A-transport","A-weapon")));
    all_gods = insert(all_gods,new Link<God>(God("Vesuvius","Roman",
        "V-transport","Volcano")));
    all_gods = insert(all_gods,new Link<God>(God("Bacchus","Roman",
        "Stretcher","Wine goblet")));

    print_all(all_gods);

    Link<God>* norse_gods = 0;
    norse_gods = move(all_gods,norse_gods,God("Odin","Norse",
        "Eight-legged horse",""));
    norse_gods = move(all_gods,norse_gods,God("Thor","Norse",
        "Pinzgauer","Hammer"));
    norse_gods = move(all_gods,norse_gods,God("Freia","Norse",
        "F-transport","F-weapon"));

    Link<God>* greek_gods = 0;
    greek_gods = move(all_gods,greek_gods,God("Hera","Greek",
        "H-transport","Spear"));
    greek_gods = move(all_gods,greek_gods,God("Athena","Greek",
        "A-transport","A-weapon"));
    greek_gods = move(all_gods,greek_gods,God("Poseidon","Greek",
        "Seahorse","Trident"));
    greek_gods = move(all_gods,greek_gods,God("Zeus","Greek",
        "","Lightning"));
    greek_gods = move(all_gods,greek_gods,God("Ares","Greek",
        "A-transport","A-weapon"));

    Link<God>* roman_gods = 0;
    roman_gods = move(all_gods,roman_gods,God("Mars","Roman",
        "M-transport","M-weapon"));
    roman_gods = move(all_gods,roman_gods,God("Vesuvius","Roman",
        "V-transport","Volcano"));
    roman_gods = move(all_gods,roman_gods,God("Bacchus","Roman",
        "Stretcher","Wine goblet"));

    // all_gods is now empty - this should probably be part of the erase
    // function
    all_gods = 0;

    cout << "\nAll gods:\n";
    print_all(all_gods);
    cout << "\nNorse gods:\n";
    print_all(norse_gods);
    cout << "\nGreek gods:\n";
    print_all(greek_gods);
    cout << "\nRoman gods:\n";
    print_all(roman_gods);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
