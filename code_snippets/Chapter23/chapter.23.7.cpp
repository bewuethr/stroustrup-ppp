
//
// This is example code from Chapter 23.7 "Searching with regular expressions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <boost/regex.hpp>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

using namespace std;

//------------------------------------------------------------------------------

int main()
try
{
    ifstream in("file.txt");    // input file
    if (!in) cerr << "no file\n";

    boost::regex pat ("\\w{2}\\s*\\d{5}(-\\d{4})?");    // ZIP code pattern
    cout << "pattern: " << pat << '\n';

    int lineno = 0;
    string line;    // input buffer
    while (getline(in,line)) {
        ++lineno;
        boost::smatch matches;    // matched strings go here
        if (boost::regex_search(line, matches, pat)) {
            cout << lineno << ": " << matches[0] << '\n';
            if (1<matches.size() && matches[1].matched)
                cout  << "\t: " << matches[1] << '\n';    // sub-match
        }
    }
}
catch (std::exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
};

//------------------------------------------------------------------------------
