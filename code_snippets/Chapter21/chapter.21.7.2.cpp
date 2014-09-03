
//
// This is example code from Chapter 21.7.2 "Stream iterators" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

void foo()
{
    ostream_iterator<string> oo(cout);        // assigning to *oo is to write to cout

    *oo = "Hello, ";    // meaning cout << "Hello, "
    ++oo;               // "get ready for next output operation"
    *oo = "world!\n";   // meaning cout << "world!\n"

    istream_iterator<string> ii(cin); // reading *ii is to read a string from cin

    string s1 = *ii;    // meaning cin>>s1
    ++ii;               // "get ready for the next input operation"
    string s2 = *ii;    // meaning cin>>s2
}

//------------------------------------------------------------------------------

int main()
{
    string from, to;
    cin >> from >> to;  // get source and target file names

    ifstream is(from.c_str());            // open input stream
    ofstream os(to.c_str());              // open output stream

    istream_iterator<string> ii(is);      // make input iterator for stream
    istream_iterator<string> eos;         // input sentinel
    ostream_iterator<string> oo(os,"\n"); // make output iterator for stream

    vector<string> b(ii,eos);             // b is a vector initialized from input
    sort(b.begin() ,b.end());             // sort the buffer
    copy(b.begin() ,b.end() ,oo);         // copy buffer to output,
}

//------------------------------------------------------------------------------
