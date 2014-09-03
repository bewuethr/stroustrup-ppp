
//
// This is example code from Chapter 18.6.2 "Palindromes using arrays" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_palindrome(const char s[], int n)
// s points to the first character of an array of n characters
{
    int first = 0;         // index of first letter
    int last = n-1;        // index of last letter
    while (first < last) { // we haven't reached the middle
        if (s[first]!=s[last]) return false;
        ++first;           // move forward
        --last;            // move backwards
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
        if (!is_palindrome(s,strlen(s))) cout << " not";
        cout << " a palindrome\n";
    }
}

//------------------------------------------------------------------------------
