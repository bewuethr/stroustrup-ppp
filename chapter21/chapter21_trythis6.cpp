// Chapter 21, Try This 6: get the stream iterator example to work with a file
// of a few hundred words, then try the "emphatically not recommended" version
// and see what happens when the input buffer overflows (hint: it crashes)

#include "../lib_files/std_lib_facilities.h"<

//------------------------------------------------------------------------------

int main()
try {
    string from, to;
    cout << "Enter input file name, then output file name: ";
    cin >> from >> to;                      // get source and target file names

    ifstream is(from.c_str());              // open input stream
    ofstream os(to.c_str());                // open output stream

    istream_iterator<string> ii(is);        // make input iterator for stream
    istream_iterator<string> eos;           // input sentinel
    ostream_iterator<string> oo(os,"\n");   // make output iterator for stream

    //// doing it the wrong way
    //const int max_size = 150;               // input has 250 words!
    //vector<string> b(max_size);
    //copy(ii,eos,b.begin());

    vector<string> b(ii,eos);               // b is a vector initialised from input
    sort(b.begin(),b.end());                // sort the buffer
    copy(b.begin(),b.end(),oo);             // copy buffer to output
}
catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

//------------------------------------------------------------------------------