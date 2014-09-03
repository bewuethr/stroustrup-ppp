
//
// This is example code from Chapter 6.3.3 "Implementing tokens" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

int main()
{
    Token t1('+');     // initialize t1 so that t1.kind = '+'
    Token t2('8',11.5);// initialize t2 so that t2.kind = '8' and t2.value = 11.5
}

//------------------------------------------------------------------------------
