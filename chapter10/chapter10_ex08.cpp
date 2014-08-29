// Chapter 10, exercise 08: take two file names, produce file that is content
// of the first file, followed by content of the second file
// Use pics_and_txt/chapter10_ex08_in1.txt and pics_and_txt/chapter10_ex08_in2.txt
// for input

#include "../lib_files/std_lib_facilities.h"

int main()
try {
    string s1;
    string s2;
    cout << "Enter first file name: ";
    cin >> s1;
    cout << "Enter second file name: ";
    cin >> s2;
    string oname = "pics_and_txt/chapter10_ex08_out.txt";

    ifstream ifs1(s1.c_str());
    if (!ifs1) error("can't open input file ",s1);
    ifstream ifs2(s2.c_str());
    if (!ifs2) error("can't open input file ",s2);
    ofstream ofs(oname.c_str());
    if (!ofs) error("can't open output file ",oname);

    char ch;
    while (ifs1.get(ch)) ofs << ch;
    while (ifs2.get(ch)) ofs << ch;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
