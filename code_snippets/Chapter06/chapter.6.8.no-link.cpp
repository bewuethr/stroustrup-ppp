
//
// This is example code from Chapter 6.8 "Token streams" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)   // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    // user interface
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token
    void putback(Token t); // put a Token back
private:
    // implementation details
    // (not directly accessible to users of Token_stream)
};

//------------------------------------------------------------------------------

int main()
{
    Token_stream ts;    // a Token_stream called ts
    Token t = ts.get(); // get next Token from ts
    // ...
    ts.putback(t);      // put the Token t back into ts
}

//------------------------------------------------------------------------------
