
//
// This is example code from Chapter 8.5.8 "Function call implementation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

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

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

double primary(Token_stream& ts);
double term(Token_stream& ts);

double expression(Token_stream& ts)
{
    double left = term(ts);
    Token t = ts.get();
    // ...
    return left;
}

//------------------------------------------------------------------------------

double term(Token_stream& ts)
{
    double left = primary(ts);
    Token t = ts.get();
    switch (t.kind) {
    // ...
        case '/':
        {
            double d = primary(ts);
            // ...
        }
    // ...
    }

    return left;
}

//------------------------------------------------------------------------------

double primary(Token_stream& ts)
{
    Token t = ts.get ();
    switch (t.kind) {
    case ' (':
        {    double d = expression(ts);
            // ...
        }
        // ...
    }

    return 0.0;
}

//------------------------------------------------------------------------------
