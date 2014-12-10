// Chapter 20, Exercise 13: modify exercise 12 to use 0 to represent the one
// past the last element (end()) instead of allocating a real Link

#include "../lib_files/std_lib_facilities.h"

template<class Elem> struct Link {
    Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0)
        :prev(p), succ(s), val(v) { }
    Link* prev;
    Link* succ;
    Elem val;
};

template<class Elem> class my_list {
public:
    my_list() :first(0) { }

    class iterator;

    iterator begin() { return iterator(first); }
    iterator end() { return iterator(0); }

    iterator insert(iterator p, const Elem& v); // insert v into list before p
    iterator erase(iterator p);          // remove p from the list

    void push_back(const Elem& v);
    void push_front(const Elem& v);
    void pop_front();
    void pop_back();

    Elem& front() { return *first; }
    Elem& back();

    Link<Elem>* first;
};

template<class Elem> class my_list<Elem>::iterator {
    Link<Elem>* curr;
public:
    iterator(Link<Elem>* p) :curr(p) { }

//    Link<Elem>* get_link() { return curr; }

    iterator& operator++() { curr = curr->succ; return *this; } // forward
    iterator& operator--() { curr = curr->prev; return *this; } // backward
    Elem& operator*() { return curr->val; }    // get value (dereference)

    bool operator==(const iterator& b) const { return curr==b.curr; }
    bool operator!=(const iterator& b) const { return curr!=b.curr; }
};

template<class Elem>
void my_list<Elem>::push_front(const Elem& v)
{
    first = new Link<Elem>(v,0,first);
}

template<class Iterator>
Iterator high(Iterator first, Iterator last)
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

int main()
try {
    my_list<int> lst;
    int x;
    while (cin >> x) lst.push_front(x);
    my_list<int>::iterator p = high(lst.begin(),lst.end());
    cout << "The highest value was " << *p << "\n";
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








