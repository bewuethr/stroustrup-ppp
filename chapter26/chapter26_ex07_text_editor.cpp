// Simple text editor from Seciton 20.6, implementation

#include "chapter26_ex07_text_editor.h"

namespace Text_ed {;

//------------------------------------------------------------------------------

Text_iterator& Text_iterator::operator++()
{
    ++pos;                // proceed to next character
    if (pos==(*ln).end()) {
        ++ln;            // proceed to next line
        pos = (*ln).begin();
    }
    return *this;
}

//------------------------------------------------------------------------------

bool Text_iterator::operator==(const Text_iterator& other) const
{ 
    return ln == other.ln && pos == other.pos;
}

//------------------------------------------------------------------------------

// first character of first line
Text_iterator Document::begin()
{
    return Text_iterator(lines.begin(), lines.begin()->begin());
}

//------------------------------------------------------------------------------

// one beyond the last line
Text_iterator Document::end()
{ 
    list<Line>::iterator last = lines.end(); 
    --last; 
    return Text_iterator(last, last->end()); 
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Document& d)
{
    char ch;
    while (is.get(ch)) {
        d.lines.back().push_back(ch);    // add the character
        if (ch=='\n')
            d.lines.push_back(Line());   // add another line
    }
    if (d.lines.back().size()) d.lines.push_back(Line()); // add final empty line
    return is;
}

//------------------------------------------------------------------------------

void print(Document& d)
{
    for (Text_iterator p = d.begin(); p!=d.end(); ++p)
        cout << *p;
}

//------------------------------------------------------------------------------

void erase_line(Document& d, int n)
{
    if (n<0 || d.lines.size()<=n) return;    // ignore out-of-range lines
    d.lines.erase(advance(d.lines.begin(), n));
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
        first = ++p;
    }
}

//------------------------------------------------------------------------------

} // of namespace Text_ed