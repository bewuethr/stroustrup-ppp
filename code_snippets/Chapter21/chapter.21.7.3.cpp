
//
// This is example code from Chapter 21.7.3 "Using a set to keep order" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <set>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    string from, to;
    cin >> from >> to;                  // get source and target file names

    ifstream is(from.c_str());          // make input stream
    ofstream os(to.c_str());            // make output stream

    istream_iterator<string> ii(is);    // make input iterator for stream
    istream_iterator<string> eos;       // input sentinel
    ostream_iterator<string> oo(os," ");// make output iterator for stream

    set<string> b(ii,eos);              // b is a set initialized from input
    copy(b.begin() ,b.end() ,oo);       // copy buffer to output,
}

//------------------------------------------------------------------------------
