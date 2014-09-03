
//
// This is example code from Chapter 11.3.3 "Positioning in files" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    string name = "chapter.11.3.3.in";
    fstream fs(name.c_str());    // open for input and output
    if (!fs) error("can't open ",name);

    fs.seekg(5);    // move reading position ('g' for 'get') to 5 (the 6th character)
    char ch;
    fs>>ch;         // read and increment reading position
    cout << "character 6 is " << ch << '(' << int(ch) << ")\n";

    fs.seekp(1);    // move writing position ('p' for 'put') to 1
    fs<<'y';        // write and increment writing position 
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
