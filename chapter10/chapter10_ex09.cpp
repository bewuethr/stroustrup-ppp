// Chapter 10, exercise 09: take names of two files containing sorted
// whitespace-separated words and merge them, preserving order
// use pics_and_txt/chapter10_ex09_in1.txt and pics_and_txt/chapter10_ex09_in2.txt
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
    string oname = "pics_and_txt/chapter10_ex09_out.txt";

    ifstream ifs1(s1.c_str());
    if (!ifs1) error("can't open input file ",s1);
    ifstream ifs2(s2.c_str());
    if (!ifs2) error("can't open input file ",s2);
    ofstream ofs(oname.c_str());
    if (!ofs) error("can't open output file ",oname);

    string sf1;
    string sf2;
    ifs1 >> sf1;
    ifs2 >> sf2;
    if (sf1=="" || sf2=="") error("at least one input file is empty");

    while (true) {
        if (sf1 <= sf2) {
            ofs << sf1 << endl;
            if (ifs1.eof()) break;
            else ifs1 >> sf1;
        }
        else {
            ofs << sf2 << endl;
            if (ifs2.eof()) break;
            else ifs2 >> sf2;
        }
    }

    // empty unfinished files
    if (ifs1.eof()) {
        ofs << sf2 << endl;
        while (ifs2>>sf2) ofs << sf2 << endl;
    }
    else {
        ofs << sf1 << endl;
        while (ifs1>>sf1) ofs << sf1 << endl;
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
