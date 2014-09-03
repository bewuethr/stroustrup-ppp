
//
// This is example code from Chapter 6.8.2 "Reading tokens" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;       // what kind of token
    double value;    // for numbers: a value 
    Token(char ch)   // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();  // make a Token_stream that reads from cin
    Token get();     // get a Token (get() is defined elsewhere)
    void putback(Token t); // put a Token back
private:
    bool full;       // is there a Token in the buffer?
    Token buffer;    // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;    // copy t to buffer
    full = true;   // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {    // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;     // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case ';':      // for "print"
    case 'q':      // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);       // put digit back into the input stream
            double val;
            cin >> val;            // read a floating-point number
            return Token('8',val); // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    Token_stream ts;
    Token t(')');
    ts.putback(t);
    Token u = ts.get();

    if (u.kind != t.kind || u.value != t.value)
        error("Error in token stream logic");
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
