
//
// This is example code from Chapter 6.5.2.1 "Expressions: First try" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

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

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double expression()
{
    double left = expression();      // read and evaluate an Expression
    Token t = get_token();           // get the next token
    switch (t.kind) {                // see which kind of token it is
    case '+':
        return left + term();        // read and evaluate a Term,
                                     // then do an add
    case '-':
        return left - term();        // read and evaluate a Term,
                                     // then do a subtraction
    default:
        return left;                 // return the value of the Expression
    }
}

//------------------------------------------------------------------------------
