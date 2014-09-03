
//
// This is example code from Chapter 21.2.1 "Some generic uses" of
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

void f(vector<int>& v, int x)     // works for vector of int
{
    vector<int>::iterator p = find(v.begin(),v.end(),x);
    if (p!=v.end())     { /* we found x */ }
    // ...
}

//------------------------------------------------------------------------------

void f(list<string>& v, string x) // works for list of string
{
    list<string>::iterator p = find(v.begin(),v.end(),x);
    if (p!=v.end()) { /* we found x */ }
    // ...
}

//------------------------------------------------------------------------------

void f(Document& v, char x)       // works for Document of char
{
    Text_iterator p = find(v.begin(),v.end(),x);
    if (p!=v.end())     { /* we found x */ }
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    // works for vector of int
    {
        int initializer[7] = {1,2,3,4,5,6,7};
        int* first = initializer;
        int* last  = initializer+7;

        vector<int> v(first,last);
        f(v,4);
    }

    // works for list of string
    {
        const char*  initializer[7] = {"one","two","three","four","five","six","seven"};
        const char** first = initializer;
        const char** last  = initializer+7;

        list<string> l(first,last);
        f(l,"four");
    }

    // works for Document of char
    {
        Document d;

        f(d,'A');
    }
}

//------------------------------------------------------------------------------
