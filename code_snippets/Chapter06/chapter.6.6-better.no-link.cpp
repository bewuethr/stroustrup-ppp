
//
// This is example code from Chapter 6.6 "Trying the first version" of
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

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token
    void putback(Token t); // put a Token back
private:
    // implementation details
};

//------------------------------------------------------------------------------

Token_stream ts;      // global token stream

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary();     // read and evaluate a Primary

//------------------------------------------------------------------------------

int main()
try {
    while (cin)
        cout << expression() << '\n';
    keep_window_open();
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open ();
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open ();
    return 2;
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term(); // read and evaluate a Term
    Token t = ts.get();   // get the next token from token stream

    while(true) {    
        switch(t.kind) {
    case '+':
        left += term();   // evaluate Term and add
        t = ts.get();
        break;
    case '-':
        left -= term();   // evaluate Term and subtract
        t = ts.get();
        break;
    default: 
        ts.putback(t);    // put t back into the token stream
        return left;      // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();   // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t); // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------
