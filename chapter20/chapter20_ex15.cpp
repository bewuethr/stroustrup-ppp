// Chapter 20, Exercise 15: define a pvector to be like a vector of pointers
// except that it contains pointer to objects and its destructor deletes each
// object

// Exercise 16: define an ovector that is like pvector except that the [] and *
// operators return a reference to the object pointed to by an element rather
// than the pointer

// Exercise 17: define an ownership_vector that holds pointers to objects like
// pvector, but provides a mechanism for the user to decide which objects are
// owned by the vector, i.e., which objects are deleted by the destructor. Hint:
// Chapter 13

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

// composition with a vector<Elem*> - only behaviour that differs is dtor
template<class Elem>
class pvector {
    vector<Elem*> elems;
public:
    typedef unsigned long size_type;
    typedef typename vector<Elem*>::iterator iterator;
    typedef typename vector<Elem*>::const_iterator const_iterator;

    iterator begin() { return elems.begin(); }
    const_iterator begin() const { return elems.begin(); }
    iterator end() { return elems.end(); }
    const_iterator end() const { return elems.end(); }

    pvector() : elems() { }
    explicit pvector(size_type n) : elems(vector<Elem*>(n)) { }

    pvector(const pvector& pv) : elems(pv.elems) { }
    pvector& operator=(const pvector& pv) { elems = pv.elems; }

    ~pvector();

    Elem* operator[](size_type n) { return elems[n]; }
    const Elem* const operator[](size_type n) const { return elems[n]; }

    size_type size() const { return elems.size(); }
    size_type capacity() const { return elems.capacity(); }

    void push_back(Elem* d) { elems.push_back(d); }
};

//------------------------------------------------------------------------------

template<class Elem>
pvector<Elem>::~pvector()
{
    for (iterator it = begin(); it!=end(); ++it) {
        cout << "Deleting " << **it << "\n";
        delete *it;
    }
}

//------------------------------------------------------------------------------

// inherits from pvector, overrides []
template<class Elem>
class ovector : public pvector<Elem> {
public:
    class iterator;

    typedef typename pvector<Elem>::size_type size_type;

    iterator begin() { return typename ovector::iterator(pvector<Elem>::begin()); }
    iterator end() { return typename ovector::iterator(pvector<Elem>::end()); }

    Elem& operator[](size_type i) { return *pvector<Elem>::operator[](i); }
    const Elem& operator[](size_type i) const { return *pvector<Elem>::operator[](i); }
};

//------------------------------------------------------------------------------

// composition with an ovector<Elem>::iterator, which is the same as a
// vector<Elem*>::iterator. Behaves the same except that * return a reference
// to the object instead of the pointer. Incomplete, only minimal parts imple-
// mented.
template<class Elem>
class ovector<Elem>::iterator {
    typename vector<Elem*>::iterator it;
public:
    iterator(const iterator& iter) : it(iter.it) { }
    iterator(const typename vector<Elem*>::iterator& iter) : it(iter) { }

    iterator& operator++() { ++it; return *this; }
    iterator& operator--() { --it; return *this; }

    bool operator==(const iterator& other) const { return it==other.it; }
    bool operator!=(const iterator& other) const { return !(*this==other); }

    Elem& operator*() { return **it; }
};

//------------------------------------------------------------------------------

// holds pointers to objects; if the object is a pointer, it will be deleted
// when the dtor is invoked; if it is a reference, it won't
template<class Elem>
class ownership_vector {
    vector<Elem*> elems;
    vector<Elem*> owned;
    ownership_vector(const ownership_vector&);              // prevent copying
    ownership_vector& operator=(const ownership_vector&);
public:
    typedef unsigned long size_type;

    ownership_vector() : owned() { }
    ownership_vector(Elem* d) { push_back(d); }
    ownership_vector(Elem& d) { push_back(d); }

    ~ownership_vector();

    Elem* operator[](size_type n) { return elems[n]; }
    const Elem* const operator[](size_type n) const { return elems[n]; }

    void push_back(Elem* d) { elems.push_back(d); owned.push_back(d); }
    void push_back(Elem& d) { elems.push_back(&d); }

    size_type size() const { return elems.size(); }
};

//------------------------------------------------------------------------------

template<class Elem>
ownership_vector<Elem>::~ownership_vector()
{
    for (int i = 0; i<owned.size(); ++i) {
        cout << "Deleting " << *owned[i] << "\n";
        delete owned[i];
    }
}

//------------------------------------------------------------------------------

// test pvector
void f1()
{
    pvector<int> pv;
    for (int i = 0; i<10; ++i) {
        pv.push_back(new int(i));
    }
    for (pvector<int>::size_type i = 0; i<pv.size(); ++i)
        cout << *pv[i] << "\n"; // test [] - requires dereference
}

//------------------------------------------------------------------------------

// test ovector
void f2()
{
    ovector<double> ov;
    for (int i = 0; i<10; ++i)
        ov.push_back(new double(i*1.1));
    for (ovector<double>::size_type i = 0; i<ov.size(); ++i)
        cout << ov[i] << "\n";  // test [] - no dereference required

    ovector<double>::iterator it = ov.begin();
    while (it!=ov.end()) {
        cout << *it << ' '; // test * - no second dereference required
        ++it;
    }
    cout << "\n";
}

//------------------------------------------------------------------------------

// test ownership_vector
void f3(int i1, int i2, int i3)
{
    ownership_vector<int> osv(i1);
    // fill with pointers and references in turn
    osv.push_back(new int(2));
    osv.push_back(i2);
    osv.push_back(new int(4));
    osv.push_back(i3);
    osv.push_back(new int(6));

    for (int i = 0; i<osv.size(); ++i)
        cout << *osv[i] << "\n";
    // dtor called here: should destroy 2, 4 and 6
}

//------------------------------------------------------------------------------

int main()
try {
    f1();
    cout << "\n\n";
    f2();
    cout << "\n\n";
    f3(1,3,5);
}
catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

//------------------------------------------------------------------------------

