/*
    Simple calculator

    This program implements a basic expression calculator.
    Input from cin; output to cout.

    The grammar for input is:

    Calculation:
        Statement
        Print
        Quit
        Help
        Calculation Statement

    Statement:
        Declaration
        Expression

    Declaration:
        "let" Name "=" Expression
        "const" name "=" Expression

    Name:
        letter
        letter Sequence
        Sequence:
        letter
        digit
        "_"
        letter Sequence
        digit Sequence
        "_" Sequence

    Print:
        ";"

    Quit:
        "quit"

    Help
        "help"

    Expression:
        Term
        Expression "+" Term
        Expression "-" Term

    Term:
        Primary
        Term "*" Primary
        Term "/" Primary
        Term "%" Primary

    Primary:
        Number
        "(" Expression ")"
        "-" Primary
        "+" Primary
        "sqrt(" Expression ")"
        "pow(" Expression "," Integer ")"
        Name
        Name "=" Expression

    Number:
        floating-point-literal

    Input comes from cin through the Token_stream called ts.
*/

#ifndef CALC_GUARD
#define CALC_GUARD

#include "../lib_files/std_lib_facilities.h"

namespace Calc_lib {;

// -----------------------------------------------------------------------

// a very simple user-defined type
class Token {
public:
    char kind;      // what kind of token
    double value;   // for numbers: a value
    string name;    // for variables and functions: a name
    Token(char ch) :kind(ch), value(0) { }                  // make a Token from a char
    Token(char ch, double val) :kind(ch), value(val) { }    // make a Token from a char and an double
    Token(char ch, string n) :kind(ch), name(n) { }         // make a Token from a char and a string
};

// -----------------------------------------------------------------------

// stream of tokens
class Token_stream {
public:
    Token_stream();             // make a Token_stream that reads from cin
    Token_stream(string s);     // make a Token_stream that reads from string
    Token get();                // get a Token
    void putback(Token t);      // put a Token back
    void ignore(char c);        // discard characters up to and including a c
private:
    bool full;                  // is there a Token in the buffer?
    Token buffer;               // here is where we keep a Token put back using putback()
    istringstream iss;          // read from here when not using cin
};

// -----------------------------------------------------------------------

const char let = 'L';           // declaration token
const char con = 'C';           // constant token
//const char quit = 'q';          // t.kind==quit means that t is a quit Token
//const char help = 'h';          // help token
const char print = ';';         // t.kind==print means that t is a print Token
const char number = '8';        // t.kind==number means that t is a number Token
const char name = 'a';          // name token
const char square_root = 's';   // square root token
const char power = 'p';         // power function token
const string declkey = "let";   // declaration keyword
const string conkey = "const";  // constant keyword
const string sqrtkey = "sqrt";  // keyword for square root
const string powkey = "pow";    // keyword for power function
//const string quitkey = "quit";  // keyword to quit
//const string helpkey = "help";  // keyword for help
//const string prompt = "> ";
//const string result = "= ";     // used to indicate that what follows is a result

// -----------------------------------------------------------------------

// type for (name,value) pairs
class Variable {
public:
    string name;
    double value;
    bool is_const;
    Variable(string n, double v, bool b) :name(n), value(v), is_const(b) { }
};

// -----------------------------------------------------------------------

// type for var_table and associated functions
class Symbol_table {
public:
    double get(string s);                           // return the value of the Variable named s
    void set(string s, double d);                   // set the Variable named s to d
    bool is_declared(string var);                   // is var already in var_table?
    double declare(string var, double val, bool b); // add (var,val) to var_table
private:
    vector<Variable> var_table; // vector of Variables
};

// -----------------------------------------------------------------------

// simple power function
// handles only integers >= 0 as exponents
double my_pow(double base, int expo);

// -----------------------------------------------------------------------

// handles parsing and evaluation
class Calculator {
public:
    Calculator();
    string calculate(string input); // expression evaluation loop
    string print_help();            // return help instructions
private:
    double primary(Token_stream& ts);               // deal with numbers, unary +/-, (), sqrt, pow, names and assignments
    double term(Token_stream& ts);                  // deal with *, / and %
    double expression(Token_stream& ts);            // deal with + and -
    double declaration(bool b, Token_stream& ts);   // handle 'name = expression'
    double statement(Token_stream& ts);             // handle declarations and expressions
    //void clean_up_mess(Token_stream& ts);           // clean up after error

    Symbol_table st;                                // provides get(), set(), is_declared() and declare()
};

} // of namespace Calc_lib

#endif // CALC_GUARD
