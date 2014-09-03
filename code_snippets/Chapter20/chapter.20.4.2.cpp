
//
// This is example code from Chapter 20.4.2 "Iteration" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

template<class Elem> struct Link {
    Link* prev;    // previous link
    Link* succ;    // successor (next) link
    Elem  val;     // the value
    Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0) : val(v), prev(p), succ(s) {}
};

//------------------------------------------------------------------------------

template<class Elem> class list {
    // representation and implementation details
public:
    class iterator;     // member type: iterator

    list() : first(new Link<Elem>()), last(first) {}

    iterator begin();   // iterator to first element
    iterator end();     // iterator to one beyond last element

    iterator insert(iterator p, const Elem& v); // insert v into list after p
    iterator erase(iterator p);                 // remove p from the list

    void push_back(const Elem& v);  // insert v at end
    void push_front(const Elem& v); // insert v at front
    void pop_front();   // remove the first element
    void pop_back();    // remove the last element

    Elem& front();      // the first element
    Elem& back();       // the last element

    Link<Elem>* first;
    Link<Elem>* last;   // one-beyond-the-last link
};

//------------------------------------------------------------------------------

template<class Elem> class list<Elem>::iterator {
    Link<Elem>* curr;   // current node
public:
    iterator(Link<Elem>* p) :curr(p) { }
    iterator& operator++() {curr = curr->succ; return *this; } // forward
    iterator& operator--() {curr = curr->prev; return *this; } // backwards
    Elem& operator*() { return curr->val; } // get value (dereference)

    friend bool operator==(const iterator& a, const iterator& b)
    {
        return a.curr==b.curr;
    }

    friend bool operator!=(const iterator& a, const iterator& b)
    {
        return a.curr!=b.curr;
    }
};

//------------------------------------------------------------------------------

template<class Elem> 
typename list<Elem>::iterator list<Elem>::begin()  // iterator to first element
{ 
    return iterator(first); 
}

//------------------------------------------------------------------------------

template<class Elem> 
typename list<Elem>::iterator list<Elem>::end() // iterator to one beyond last element
{ 
    return iterator(last); 
}

//------------------------------------------------------------------------------

template<class Elem> 
void list<Elem>::push_front(const Elem& v) // insert v at front
{
    first = new Link<Elem>(v,0,first);
}

//------------------------------------------------------------------------------

template<class Iterator >
Iterator high(Iterator first, Iterator last)
// return an iterator to the element in [first,last) that has the highest value
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

//------------------------------------------------------------------------------

void f()
{
    list<int> lst;
    int x;
    while (cin >> x) lst.push_front(x);

    list<int>::iterator q = high(lst.begin(), lst.end());
    cout << "the highest value was " << *q << endl;

    list<int>::iterator p = high(lst.begin(), lst.end());
    if (p==lst.end())    // did we reach the end?
        cout << "The list is empty";
    else
        cout << "the highest value is " << *p << endl;
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
