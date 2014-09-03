
//
// This is example code from Chapter 20.6.1 "Lines" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

typedef vector<char> Line;    // a line is a vector of characters

//------------------------------------------------------------------------------

struct Document {
    list<Line> line;    // a document is a list of lines 
    Document() { line.push_back(Line()); }
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Document& d)
{
    char ch;
    while (is>>ch) {
        d.line.back().push_back(ch);    // add the character
        if (ch=='\n') {
            d.line.push_back(Line());   // add another line
        }
    }
    return is;
}

//------------------------------------------------------------------------------

int main()
{
    Document d;
    cin >> d;
}

//------------------------------------------------------------------------------
