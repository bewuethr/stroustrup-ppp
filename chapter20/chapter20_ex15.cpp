// Chapter 20, Exercise 15: define a pvector to be like a vector of pointers
// except that it contains pointer to objects and its destructor deletes each
// object

// Exercise 16: define an ovector that is like pvector except that the [] and *
// operators return a reference to the object pointed to by an element rather
// than the pointer

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

int main()
try {
    f1();
    cout << "\n\n";
    f2();
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

