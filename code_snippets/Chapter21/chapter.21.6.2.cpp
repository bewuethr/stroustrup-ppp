
//
// This is example code from Chapter 21.6.2 "Map overview" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <functional>
#include <string>

using std::string;
using std::less;

//------------------------------------------------------------------------------

template<class T1, class T2> struct pair {
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    pair() :first(T1()), second(T2()) { }
    pair(const T1& x, const T2& y) :first(x), second(y) { }
    template<class U, class V>
    pair(const pair<U,V>& p) :first(p.first), second(p.second) { }
};

//------------------------------------------------------------------------------

template<class T1, class T2>
pair<T1,T2> make_pair(T1 x, T2 y)
{
    return pair<T1,T2>(x,y);
}

//------------------------------------------------------------------------------

template<class Key, class Value, class Cmp = less<Key> > class map {
private:
    class tree_node;
    typedef       tree_node* sometype1;
    typedef const tree_node* sometype2;
public:
    // ...
    typedef pair<Key,Value> value_type;    // a map deals in (Key,Value) pairs

    typedef sometype1 iterator;            // probably a pointer to a tree node
    typedef sometype2 const_iterator;

    iterator begin();                      // points to first element
    iterator end();                        // points one beyond the last element

    Value& operator[ ](const Key& k);      // subscript with k

    iterator find(const Key& k);           // is there and entry for k?

    void erase(iterator p);                // remove element pointed to by p
    pair<iterator, bool> insert(const value_type&); // insert a (key,value) pair
    // ...
};

//------------------------------------------------------------------------------

struct No_case {/*...*/};

int main()
{
    map<string, double, No_case> m;
}

//------------------------------------------------------------------------------

