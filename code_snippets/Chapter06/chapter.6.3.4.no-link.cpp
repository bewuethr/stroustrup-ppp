
//
// This is example code from Chapter 6.3.4 "Using tokens" of
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

Token get_token();    // read a token from cin

//------------------------------------------------------------------------------

vector<Token> tok;    // we'll put the tokens here

//------------------------------------------------------------------------------

int main()
{
    while (cin) {
        Token t = get_token();
        tok.push_back(t);
    }
    // ...
    //Now we could find the multiply operation by a simple loop:

    for (int i = 0; i<tok.size(); ++i) {
        if (tok[i].kind=='*') {    // we found a multiply!
            double d = tok[i-1].value*tok[i+1].value;
            // now what?
        }
    }
}

//------------------------------------------------------------------------------
