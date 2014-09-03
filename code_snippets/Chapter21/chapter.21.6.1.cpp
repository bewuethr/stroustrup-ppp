
//
// This is example code from Chapter 21.6.1 "Map" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    map<string,int> words;    // keep (word,frequency) pairs

    string s;
    while (cin>>s) ++words[s];       // note: words is subscripted by a string

    typedef map<string,int>::const_iterator Iter;
    for (Iter  p = words.begin(); p!=words.end(); ++p)
        cout << p->first << ": " << p->second << '\n';
}

//------------------------------------------------------------------------------
