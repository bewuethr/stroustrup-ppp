
//
// This is example code from Chapter 23.8.7 "Regular expression errors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost;

//------------------------------------------------------------------------------

void wrong_patterns()
{
    regex pat1("(|ghi)");    // missing alternative
    regex pat2("[c-a]");     // not a range
}

//------------------------------------------------------------------------------

// Accept a pattern and a set of lines from input
// Check the pattern and search for lines with that pattern

int main()
{
    regex pattern;

    string pat;
    cout << "enter pattern: ";
    getline(cin,pat);        // read pattern

    try {
        pattern = pat;       // this checks pat
        cout << "pattern: " << pattern << '\n';
    }
    catch (bad_expression) {
        cout << pat << " is not a valid regular expression\n";
        exit(1);
    }

    cout << "now enter lines:\n";
    string line;             // input buffer
    int lineno = 0;

    while (getline(cin,line)) {
        ++lineno;
        smatch matches;
        if (regex_search(line, matches, pattern)) {
            cout << "line " << lineno << ": " << line << '\n';
            for (int i = 0; i<matches.size(); ++i)
                cout << "\tmatches[" << i << "]: "
                     <<  matches[i]  << '\n';
        }
        else
            cout << "didn't match\n";
    }
}

//------------------------------------------------------------------------------
