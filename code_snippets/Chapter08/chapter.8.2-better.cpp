
//
// This is example code from Chapter 8.2 "Declarations and definitions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"     // we find the declaration of cout in here

//------------------------------------------------------------------------------

int f(int);              // declaration of f

int main()
{
    int i = 7;           // declaration of i
    cout << f(i) << '\n';
}

//------------------------------------------------------------------------------

double my_sqrt(double);  // no function body here
extern int a;            // "extern plus no initializer" means "not definition"

int a;                   // definition
//int a;                 // error: double definition

int x = 7;               // definition
extern int x;            // declaration 
extern int x;            // another declaration

double my_sqrt(double);  // declaration
double my_sqrt(double d) { return 0.0; }    // definition
//double my_sqrt(double d) { return 1.0; }    // error: double definition
double my_sqrt(double);  // another declaration of my_sqrt
double my_sqrt(double);  // yet another declaration of my_sqrt

//int my_sqrt(double);   // error: inconsistent declarations of my_sqrt

double expression();     // just a declaration; not a definition

double primary()
{
    // ...
    return expression();
    // ...
}

//------------------------------------------------------------------------------

double term()
{
    // ...
    return primary();
    // ...
}

//------------------------------------------------------------------------------

double expression()
{
    // ...
    return term();
    // ...
}

//------------------------------------------------------------------------------

int f(int n) { return n; }
