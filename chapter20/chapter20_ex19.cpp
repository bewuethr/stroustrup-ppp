// Chapter 20, Exercise 19: define a range-checked iterator for list (a bidirec-
// tional iterator)

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

template<class T>
class l_iterator_rc {
    typename list<T>::iterator curr;
    typename list<T>::iterator first;
    typename list<T>::iterator last;
public:
    l_iterator_rc(typename list<T>::iterator c, typename list<T>::iterator f, typename list<T>::iterator l)
        : curr(c), first(f), last(l) { }

    T& operator*() { return *curr; }
    const T& operator*() const { return *curr; }
    T* operator->() { return &(*curr); }

    l_iterator_rc& operator++();
    l_iterator_rc& operator--();

    bool operator==(const l_iterator_rc& other) { return curr==other.curr; }
    bool operator!=(const l_iterator_rc& other) { return !(*this==other); }
};

//------------------------------------------------------------------------------

template<class T>
l_iterator_rc<T>& l_iterator_rc<T>::operator++()
{
    ++curr;
    if (curr==last) error("iterator past end of list");
    return *this;
}

//------------------------------------------------------------------------------

template<class T>
l_iterator_rc<T>& l_iterator_rc<T>::operator--()
{
    if (curr==first) error("iterator before begin of list");
    --curr;
    return *this;
}

//------------------------------------------------------------------------------

struct A {
    A(int i1, int i2) : a(i1), b(i2) { }
    int a;
    int b;
};

int main()
try {
    // test for list of integers
    list<int> li;
    for (int i = 0; i<10; ++i)
        li.push_back(i);

    for (typename list<int>::iterator it = li.begin(); it!=li.end(); ++it)
        cout << *it << ' ';
    cout << "\n";

    l_iterator_rc<int> it_rc(li.begin(),li.begin(),li.end());
    cout << *it_rc << "\n";
//    --it_rc;    // throws exception
    ++it_rc;
    cout << *it_rc << "\n";
    --it_rc;
    cout << *it_rc << "\n";
    for (int i = 0; i<9; ++i) {
        ++it_rc;
        cout << *it_rc << "\n";
    }

    // test for list of user defined type A
    A a1(0,1);
    A a2(1,2);
    A a3(2,3);
    list<A> la;
    la.push_back(a1);
    la.push_back(a2);
    la.push_back(a3);

    for (typename list<A>::iterator it = la.begin(); it!=la.end(); ++it)
        cout << it->a << ' ' << (*it).b << "  ";
    cout << "\n";

    l_iterator_rc<A> ita_rc(la.begin(),la.begin(),la.end());
    cout << (*ita_rc).a << ' ' << (*ita_rc).b << "\n";
//    --ita_rc;    // throws exception
    ++ita_rc;
    cout << ita_rc->a << ' ' << ita_rc->b << "\n";
    --ita_rc;
    cout << ita_rc->a << ' ' << ita_rc->b << "\n";
    for (int i = 0; i<2; ++i) {
        ++ita_rc;
        cout << ita_rc->a << ' ' << ita_rc->b << "\n";
    }
//    ++ita_rc;   // throws exception
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

