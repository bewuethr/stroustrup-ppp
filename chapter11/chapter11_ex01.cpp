// Chapter 11, exercise 01: read text file, convert input to all lower case,
// producing new file
// Use pics_and_txt/chapter11_ex01_in.txt

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

    char ch;
    while (ifs.get(ch)) {
        if (isalpha(ch)) ch = tolower(ch);
        ofs << ch;
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
