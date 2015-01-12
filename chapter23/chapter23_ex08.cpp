// Chapter 23, exercise 8: modify program from 23.8.7 to take as input a pattern
// and a file name, then output numbered lines (line-number: line) that contain
// a match of the pattern. No match - no output

#include<regex>
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include<stdexcept>

using namespace std;

int main()
try {
    while (true) {
        string pat;
        cout << "Enter pattern (q to exit): ";
        getline(cin,pat);   // read pattern
        if (pat=="q") break;
        regex pattern;
        try {
            pattern = pat;  // this checks pat
        }
        catch (regex_error) {
            cerr << "Not a valid regular expression: " << pat << '\n';
            continue;
        }

        string fname;
        cout << "Enter file name: ";
        getline(cin,fname);
        ifstream ifs(fname);
        if (!ifs) throw runtime_error("Can't open " + fname);
        string line;
        int lineno = 0;
        while (getline(ifs,line)) {
            ++lineno;
            smatch matches;
            if (regex_search(line,matches,pattern))
                cout << setw(3) << lineno << ": " << line << '\n';
        }
    }
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}