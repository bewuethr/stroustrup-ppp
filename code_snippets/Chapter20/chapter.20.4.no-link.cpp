
//
// This is example code from Chapter 20.4 "Linked lists" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

template<class Elem> struct Link {
    Link* prev;    // previous link
    Link* succ;    // successor (next) link
    Elem  val;     // the value
};

//------------------------------------------------------------------------------

template<class Elem> struct list {
    Link<Elem>* first;
    Link<Elem>* last; // one-beyond-the-last link
};

//------------------------------------------------------------------------------
