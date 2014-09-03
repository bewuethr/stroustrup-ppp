
//
// This is example code from Chapter 11.6 "Character classification" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <cctype>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    char ch;
    while (cin.get(ch)) {
        if (isspace(ch)) {    // if ch is whitespace
            // do nothing (i.e. skip whitespace)
        }
        if (isdigit(ch)) {
            // read a number
        }
        else if (isalpha(ch)) {
            // read an identifier
        }
        else {
            // deal with operators
        }
    }
}

//------------------------------------------------------------------------------

void test(char c)
{
    isspace(c);    // is c whitespace? (' ', '\t', '\n', etc.)
    isalpha(c);    // is c a letter? ('a'..'z', 'A'..'Z') note: not '_'
    isdigit(c);    // is c a decimal digit? ('0'..'9')
    isxdigit(c);   // is c hexadecimal digit: decimal digit or 'a'..'f' or 'A'..'F'
    isupper(c);    // is c an upper-case letter?
    islower(c);    // is c a lower-case letter?
    isalnum(c);    // is c a letter or a decimal digit?
    iscntrl(c);    // is c a control character (ACSII 0..31 and 127)
    ispunct(c);    // is c not a letter, digit, whitespace, or invisible control character
    isprint(c);    // is c printable (ASCIII ' '..'~')
    isgraph(c);    // is c isalpha()|isdigit()|ispunct() (note, not space)

    toupper(c);    // c or c's upper case equivalent
    tolower(c);    // c or c's lower case equivalent
}

//------------------------------------------------------------------------------

void tolower(string& s)    // put s into lower case
{
    for (int i=0; i<s.length(); ++i) s[i] = tolower(s[i]);
}

//------------------------------------------------------------------------------
