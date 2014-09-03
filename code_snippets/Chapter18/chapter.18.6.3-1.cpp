
//
// This is example code from Chapter 18.6.3 "Palindromes using pointers" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_palindrome(const char* first, const char* last)
// first points to the first letter, last to the last letter
{
    while (first < last) {        // we  haven't reached the middle
        if (*first!=*last) return false;
        ++first;    // move forward
        --last;        // move backwards
    }
    return true;
}

//------------------------------------------------------------------------------

istream& read_word(istream& is, char* buffer, int max)
// read at most max-1 characters from is into buffer
{
    is.width(max);         // read at most max-1 characters in the next >>
    is >> buffer;          // read whitespace terminated word,
    // add zero after the last character read into p
    return is;
}

//------------------------------------------------------------------------------

int main()
{
    const int max = 128;
    char s[max];
    while (read_word(cin,s,max)) { 
        cout << s << " is";
        if (!is_palindrome(&s[0],&s[strlen(s)-1])) cout << " not";
        cout << " a palindrome\n";
    }
}

//------------------------------------------------------------------------------
