
//
// This is example code from Chapter 20.4.1 "List operations" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

template<class Elem> class list {
    // representation and implementation details
public:
    class iterator;     // member type: iterator

    iterator begin();   // iterator to first element
    iterator end( );    // iterator to one beyond last element

    iterator  insert(iterator p, const Elem& v); // insert v into list after p
    iterator erase(iterator p);     // remove p from the list

    void push_back(const Elem& v);  // insert v at end
    void push_front(const Elem& v); // insert v at front
    void pop_front();   // remove the first element
    void pop_back();    // remove the last element

    Elem& front();      // the first element
    Elem& back();       // the last element

    // ...
};

//------------------------------------------------------------------------------
