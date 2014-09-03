
//
// This is example code from Chapter 20.6.2 "Iteration" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

typedef vector<char> Line;    // a line is a vector of characters

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

Text_iterator& Text_iterator::operator++()
{
    if (pos==(*ln).end()) {
        ++ln;            // proceed to next line
        pos = (*ln).begin();
    }
    ++pos;                // proceed to next character
    return *this;
}

//------------------------------------------------------------------------------

bool Text_iterator::operator==(const Text_iterator& other) const
{ 
    return ln == other.ln && pos == other.pos;
}

//------------------------------------------------------------------------------

struct Document {
    list<Line> line; 
    Document() { line.push_back(Line()); }
    Text_iterator begin()      // first character of first line
    { return Text_iterator(line.begin(), line.begin()->begin()); }    
    Text_iterator end()        // one beyond the last line
    { 
        list<Line>::iterator last = line.end(); 
        --last; 
        return Text_iterator(last, last->end()); 
    }
};

//------------------------------------------------------------------------------

void print(Document& d)
{
    for (Text_iterator p = d.begin(); p!=d.end(); ++p) cout << *p;
}

//------------------------------------------------------------------------------

template<class Iter> Iter advance(Iter p, int n)
{
    while (n>0) { ++p; --n; }    // go forwards
    return p;
}

//------------------------------------------------------------------------------

void erase_line(Document& d, int n)
{
    if (n<0 || d.line.size()<=n) return;    // ignore out-of-range lines
    d.line.erase(advance(d.line.begin(), n));
}

//------------------------------------------------------------------------------

bool match(Text_iterator first, Text_iterator last, const string& s)
{
    string::const_iterator p;

    for(p = s.begin(); 
        p != s.end() && first != last && *p == *first; 
        ++p, ++first)
    {}

    return p == s.end(); // if we reached end of string, we matched it all
}

//------------------------------------------------------------------------------

Text_iterator find_text(Text_iterator first, Text_iterator last, const string& s)
{
    if (s.size()==0) return last;    // can't find an empty string
    char first_char = s[0];
    while (true) {
        Text_iterator p = find(first,last,first_char);
        if (p==last || match(p,last,s)) return p;
    }
}

//------------------------------------------------------------------------------

int main()
{
    Document my_doc;

    Text_iterator p =
        find_text(my_doc.begin(), my_doc.end(),"secret\nhomestead");
    if (p==my_doc.end())
        cout << "not found";
    else {
        // do something
    }

    print(my_doc);
}

//------------------------------------------------------------------------------
