// Chapter 23, Drill: get regex (or not, if you use std::regex in C++11) and
// run the example from 23.7

#include<regex>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    ifstream in("pics_and_txt/chapter23_drill_in.txt");
    if (!in) cerr << "No file\n";

    const string pat_string = "\\w{2}\\s*\\d{5}(-\\d{4})?"; // ZIP code pattern
    regex pat(pat_string);
    cout << "Pattern: " << pat_string << '\n';

    int lineno = 0;
    string line;    // input buffer
    while (getline(in,line)) {
        ++lineno;
        smatch matches; // matched strings go here
        if (regex_search(line,matches,pat)) {
            cout << lineno << ": " << matches[0] << '\n';
            if (1<matches.size() && matches[1].matched)
                cout << "\t: " << matches[1] << '\n';
        }
    }
}
