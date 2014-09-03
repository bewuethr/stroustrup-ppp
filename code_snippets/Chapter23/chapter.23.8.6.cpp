
//
// This is example code from Chapter 23.8.6 "Character sets and ranges" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <boost/regex.hpp>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

//------------------------------------------------------------------------------
using namespace boost;

int main()
try
{
    string s = "\"[[:alnum:]]+\"";

    // Furthermore, to put that string into a regex, we must escape the backslashes:

    regex r("\\\"[[:alnum:]]+\\\"");
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
