// Chapter 23, exercise 13: test if the reuglar expression '.' matches the
// newline character '\n'

#include<iostream>
//#include<string>
#include<regex>

using namespace std;

int main()
{
    string s = "\n";
    regex pat(".");
    smatch matches;
    if (regex_match(s,matches,pat))
        cout << "'.' matches '\\n'\n";
    else
        cout << "'.' does not match '\\n'\n";
}
