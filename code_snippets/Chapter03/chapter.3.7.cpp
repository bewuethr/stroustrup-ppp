
//
// This is example code from Chapter 3.7 "Names" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

//int Main() // error: no main function in the program
int main()
{
    //String s = "Goodby cruel world! "; // error: type String is unknown
    string s = "Goodby cruel world! ";

    //cOut << S << '\n';                 // error: cOut and S are unknown
    cout << s << '\n';

    //int if = 7;                        // error: "if" is a keyword 
    //int string = 7;                    // this will lead to trouble
}

//------------------------------------------------------------------------------
