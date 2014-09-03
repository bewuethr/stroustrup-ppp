
//
// This is example code from Chapter 3.6.1 "An example: count repeated words" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int number_of_words = 0;
    string previous = " ";      // not a word
    string current;
    while (cin>>current) {
        ++number_of_words;      // increase word count
        if (previous == current)
            cout << "word number " << number_of_words
                 << " repeated: "<< current << '\n';
        previous = current;
    }
}

//------------------------------------------------------------------------------
