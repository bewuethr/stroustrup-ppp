// Chapter 11, exercise 12: reverse the order of words in a text file
// Use pics_and_txt/macbeth.txt for input

#include "../lib_files/std_lib_facilities.h"

int main()
try {
    cout << "Enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ifs(iname.c_str());
    if (!ifs) error("can't open input file ",iname);
    cout << "Enter output file name: ";
    string oname;
    cin >> oname;
    ofstream ofs(oname.c_str());
    if (!ofs) error("can't open output file ",oname);

    // read file into string
    vector<string> contents;
    string s;
    while (ifs>>s)
        contents.push_back(s);

    // read string from end, write into file
    for (int i = contents.size()-1; i>=0; --i) {
        ofs << contents[i] << endl;
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
