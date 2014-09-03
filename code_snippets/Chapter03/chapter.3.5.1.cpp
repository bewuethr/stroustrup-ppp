
//
// This is example code from Chapter 3.5.1 "An example: delete repeated words" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    string previous = " ";       // not a word
    string current;
    while (cin>>current) {       // read a stream of words
        if (previous == current) // check if the word is the same as last
            cout << "repeated word: " << current << '\n';
        previous = current;
    }
}

//------------------------------------------------------------------------------
