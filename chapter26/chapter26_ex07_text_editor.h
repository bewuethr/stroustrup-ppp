// Simple text editor from Section 20.6

#ifndef TEXTED_GUARD
#define TEXTED_GUARD

#include<vector>
#include<list>
#include<iterator>
#include<iostream>

//------------------------------------------------------------------------------

namespace Text_ed {;

//------------------------------------------------------------------------------

using namespace std;

typedef vector<char> Line;  // a line is a vector of characters

//------------------------------------------------------------------------------

class Text_iterator { // keep track of line and character position within a line
    list<Line>::iterator ln;
    Line::iterator pos;
public:
    typedef forward_iterator_tag iterator_category;
    typedef char value_type;
    typedef size_t difference_type;
    typedef char* pointer;
    typedef char& reference;

    // start the iterator at line ll's character position pp:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
        :ln(ll), pos(pp) { }

    char& operator*() { return *pos; }
    Text_iterator& operator++();
    bool operator==(const Text_iterator& other) const;
    bool operator!=(const Text_iterator& other) const { return !(*this==other); }
};

//------------------------------------------------------------------------------

struct Document {
    list<Line> lines; 
    Document() { lines.push_back(Line()); }
    Text_iterator begin();  // first character of first line
    Text_iterator end();    // one beyond the last line
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Document& d);

//------------------------------------------------------------------------------

void print(Document& d);

//------------------------------------------------------------------------------

template<class Iter>
Iter advance(Iter p, int n)
{
    while (n>0) { ++p; --n; }    // go forwards
    return p;
}

//------------------------------------------------------------------------------

void erase_line(Document& d, int n);

//------------------------------------------------------------------------------

bool match(Text_iterator first, Text_iterator last, const string& s);

//------------------------------------------------------------------------------

Text_iterator find_text(Text_iterator first, Text_iterator last, const string& s);

//------------------------------------------------------------------------------

} // of namespace Text_ed

#endif
