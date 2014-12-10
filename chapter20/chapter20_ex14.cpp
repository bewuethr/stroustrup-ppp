// Chapter 20, Exercise 14: define a singly-linked list, slist, in the style of
// std::list; determine operations that can be eliminated because there are no
// back pointers.

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

template<class Elem> struct Link {
    Link(const Elem& v = Elem(), Link* s = 0) : val(v), succ(s) { }
    Elem val;
    Link* succ;
};

//------------------------------------------------------------------------------

template<class Elem> class slist {
public:
    slist() : first(0) { }

    class iterator;

    iterator begin() { return iterator(first); }
    iterator end() { return iterator(0); }

    iterator insert(iterator p, const Elem& v); // insert v into list after p
    iterator erase(iterator p);                 // remove element AFTER p from the list

    void push_back(const Elem& v);
    void push_front(const Elem& v);
    void pop_front();
    void pop_back();

    Elem& front() { return *first; }
    Elem& back();

    Link<Elem>* first;
};

//------------------------------------------------------------------------------

template<class Elem> class slist<Elem>::iterator {
    Link<Elem>* curr;
public:
    friend class slist;

    iterator(Link<Elem>* p) :curr(p) { }

//    Link<Elem>* get_link() { return curr; }

    iterator& operator++() { curr = curr->succ; return *this; } // forward
    Elem& operator*() { return curr->val; }    // get value (dereference)

    bool operator==(const iterator& b) const { return curr==b.curr; }
    bool operator!=(const iterator& b) const { return curr!=b.curr; }
};

//------------------------------------------------------------------------------

// insert v into list after p, return iterator to newly inserted element
template<class Elem>
typename slist<Elem>::iterator slist<Elem>::insert(slist<Elem>::iterator p, const Elem& v)
{
    Link<Elem>* tmp = p.curr->succ;
    Link<Elem>* new_elem = new Link<Elem>(v,tmp);
    p.curr->succ = new_elem;
    return iterator(new_elem);
}

//------------------------------------------------------------------------------

// remove Link from list, return p's successor
template<class Elem>
typename slist<Elem>::iterator slist<Elem>::erase(slist<Elem>::iterator p)
{
    Link<Elem>* tmp = p.curr->succ;
    if (tmp) p.curr->succ = p.curr->succ->succ;
    delete tmp;
    return p;
}

//------------------------------------------------------------------------------

template<class Elem>
void slist<Elem>::push_back(const Elem& v)
{
    iterator p1 = begin();
    while (true) {
        iterator p2 = p1;
        ++p2;
        if (!p2.curr) {
            insert(p1,v);
            return;
        }
        ++p1;
    }
}

//------------------------------------------------------------------------------

template<class Elem>
void slist<Elem>::push_front(const Elem& v)
{
    first = new Link<Elem>(v,first);
}

//------------------------------------------------------------------------------

template<class Elem>
void slist<Elem>::pop_front()
{
    Link<Elem>* tmp = first->succ;
    delete first;
    first = tmp;
}

//------------------------------------------------------------------------------

template<class Elem>
void slist<Elem>::pop_back()
{
    if (begin()==end()) return; // empty list
    if (!begin().curr->succ) {  // just one element in list
        pop_front();
        return;
    }
    iterator p1 = begin();
    while (true) {
        iterator p2 = p1;
        ++p2;
        if (!p2.curr->succ) {
            erase(p1);
            return;
        }
        ++p1;
    }
}

//------------------------------------------------------------------------------

template<class Elem>
Elem& slist<Elem>::back()
{
    iterator p1 = begin();
    while (true) {
        iterator p2 = p1;
        ++p2;
        if (!p2.curr) return *p1;
        ++p1;
    }
}

//------------------------------------------------------------------------------

template<class Iterator>
Iterator high(Iterator first, Iterator last)
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

//------------------------------------------------------------------------------

template<class Elem>
void print(slist<Elem>& lst)
{
    typename slist<Elem>::iterator p = lst.begin();
    while (p != lst.end()) {
        cout << *p << ' ';
        ++p;
    }
    cout << "\n";
}

//------------------------------------------------------------------------------

int main()
try {
    slist<int> lst;
    int x;
    while (cin >> x) lst.push_front(x);
    slist<int>::iterator p = high(lst.begin(),lst.end());
    cout << "The highest value was " << *p << "\n";

    print(lst);

    p = lst.begin();
    for (int i = 0; i<2; ++i)
        ++p;
    cout << "\np points at " << *p << "\n";
    p = lst.insert(p,99);
    p = lst.insert(p,100);
    cout << "List after inserting two elements: ";
    print(lst);

    p = lst.erase(p);
    cout << "List after erasing element after p: ";
    print(lst);

    cout << "Last element: " << lst.back() << "\n";

    cout << "Popping the two first elements: ";
    lst.pop_front();
    lst.pop_front();
    print(lst);

    cout << "Adding 33 and 44 to end: ";
    lst.push_back(33);
    lst.push_back(44);
    print(lst);

    cout << "Popping back twice: ";
    lst.pop_back();
    lst.pop_back();
    print(lst);

    cout << "Popping until nothing left: ";
    while (lst.begin()!=lst.end()) {
        lst.pop_back();
        print(lst);
    }
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
