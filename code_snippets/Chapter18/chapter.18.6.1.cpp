
//
// This is example code from Chapter 18.6.1 "Palindromes using string" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_palindrome(const string& s)
{
    int first = 0;            // index of first letter
    int last = s.length()-1;  // index of last letter
    while (first < last) {    // we haven't reached the middle
        if (s[first]!=s[last]) return false;
        ++first;              // move forward
        --last;               // move backwards
    }
    return true;
}

//------------------------------------------------------------------------------

int main()
{
    string s;
    while (cin>>s) {
        cout << s << " is";
        if (!is_palindrome(s)) cout << " not";
        cout << " a palindrome\n";
    }
}

//------------------------------------------------------------------------------
