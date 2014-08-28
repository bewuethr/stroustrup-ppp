// Chapter 11, exercise 13: read text file, write out how many characters of
// each character classification are in the file
// Use pics_and_txt/macbeth.txt for input

#include "../lib_files/std_lib_facilities.h"

int main()
try {
    cout << "Enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ifs(iname.c_str());
    if (!ifs) error("can't open input file ",iname);

    // read file into string
    char ch;
    int space = 0;  // counter for character types
    int alpha = 0;
    int digit = 0;
    int xdigit = 0;
    int upper = 0;
    int lower = 0;
    int alnum = 0;
    int cntrl = 0;
    int punct = 0;
    int print = 0;
    int graph = 0;

    while (ifs.get(ch)) {
        if (isspace(ch)) ++space;
        if (isalpha(ch)) ++alpha;
        if (isdigit(ch)) ++digit;
        if (isxdigit(ch)) ++xdigit;
        if (isupper(ch)) ++upper;
        if (islower(ch)) ++lower;
        if (isalnum(ch)) ++alnum;
        if (iscntrl(ch)) ++cntrl;
        if (ispunct(ch)) ++punct;
        if (isprint(ch)) ++print;
        if (isgraph(ch)) ++graph;
    }

    cout << "Analysis:\n";
    cout << "isspace:\t" << space << endl;
    cout << "isalpha:\t" << alpha << endl;
    cout << "isdigit:\t" << digit << endl;
    cout << "isxdigit:\t" << xdigit << endl;
    cout << "isupper:\t" << upper << endl;
    cout << "islower:\t" << lower << endl;
    cout << "isalnum:\t" << alnum << endl;
    cout << "iscntrl:\t" << cntrl << endl;
    cout << "ispunct:\t" << punct << endl;
    cout << "isprint:\t" << print << endl;
    cout << "isgraph:\t" << graph << endl;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
