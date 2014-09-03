
//
// This is example code from Chapter 23.5 "A Problem" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <string>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    string s;
    while (cin>>s) {
        if (s.size()==7
            && isalpha(s[0]) && isalpha(s[1])
            && isdigit(s[2]) && isdigit(s[3]) && isdigit(s[4])
            && isdigit(s[5]) && isdigit(s[6]))
            cout << "found " << s << '\n';
    }
}

//------------------------------------------------------------------------------
