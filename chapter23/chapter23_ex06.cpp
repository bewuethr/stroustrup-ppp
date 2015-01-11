// Chapter 23, exercise 6: find dates in a text file, write out each line con-
// taining at least on date in the format line-number: line

#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include<regex>
#include<iomanip>

using namespace std;

int main()
try {
    cout << "Enter file name: ";
    string fname;
    cin >> fname;
    ifstream ifs(fname);
    if (!ifs) throw runtime_error("Can't open " + fname);

    // month or day first, separated by / or . or -
    regex pat1("\\d\\d?\\s*[-/\\.]\\s*\\d\\d?\\s*[-/\\.]\\s*\\d{4}");

    // January 31, 2008
    regex pat2("(January|February|March|April|May|June|July|August|September|October|November|December)\\s+\\d\\d?,\\s+\\d{4}");

    // 31 January 2008
    regex pat3("\\d\\d?\\s+(January|February|March|April|May|June|July|August|September|October|November|December)\\s+\\d{4}");

    smatch matches;
    string line;
    int line_count = 0;
    while (getline(ifs,line)) {
        ++line_count;
        if (regex_search(line,matches,pat1) ||
            regex_search(line,matches,pat2) ||
            regex_search(line,matches,pat3))
            cout << setw(3) << line_count << ": " << line << '\n';
    }
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}