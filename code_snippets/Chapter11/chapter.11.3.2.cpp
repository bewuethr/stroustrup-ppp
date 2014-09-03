
//
// This is example code from Chapter 11.3.2 "Binary Files" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

template<class T>
char* as_bytes(T& i)    // treat a T as a sequence of bytes
{
    void* addr = &i;    // get the address of the first byte
    // of memory used to store the object
    return static_cast<char*>(addr); // treat that memory as bytes
}

//------------------------------------------------------------------------------

int main()
try
{
    // open an istream for binary input from a file:
    cout << "Please enter input file name\n";
    string name;
    cin >> name;
    ifstream ifs(name.c_str(),ios_base::binary);    // note: stream mode
    // "binary" tells the stream not to try anything clever with the bytes
    if (!ifs) error("can't open input file ", name);

    // open an ostream for binary output from a file:
    cout << "Please enter output file name\n";
    cin >> name;
    ofstream ofs(name.c_str(),ios_base::binary);    // note: stream mode
    // "binary" tells the stream not to try anything clever with the bytes
    if (!ofs) error("can't open output file ",name);

    vector<int> v;

    // read from binary file:
    int i;
    while (ifs.read(as_bytes(i),sizeof(int))) // note: reading bytes
        v.push_back(i);    

    // ... do something with v ...

    // write to binary file:
    for(int i=0; i<v.size(); ++i)
        ofs.write(as_bytes(v[i]),sizeof(int));    // note: writing bytes
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
