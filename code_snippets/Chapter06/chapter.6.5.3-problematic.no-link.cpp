
//
// This is example code from Chapter 6.5.3 "Terms" of
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

double primary();     // read and evaluate a Primary

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = get_token();
    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
            left /= primary();
            t = get_token();
            break;
        default:
            return left;
        }
    }
}

//------------------------------------------------------------------------------
