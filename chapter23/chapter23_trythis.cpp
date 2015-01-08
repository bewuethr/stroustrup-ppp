// Chapter 23, Try This: get regex test program from 23.8.7 to run

#include<regex>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
    regex pattern;

    string pat;
    cout << "Enter pattern: ";
    getline(cin,pat);   // read pattern

    try {
        pattern = pat;  // this checks pat
        cout << "Pattern: " << pat << '\n';
    }
    catch (regex_error) {
        cout << pat << " is not a valid regular expression\n";
        exit(1);
    }

    cout << "Now enter lines:\n";
    string line;    // input buffer
    int lineno = 0;

    while (getline(cin,line)) {
        ++lineno;
        smatch matches;
        if (regex_search(line,matches,pattern)) {
            cout << "Line " << lineno << ": " << line << '\n';
            for (int i = 0; i<matches.size(); ++i)
                cout << "matches[" << i << "]: " << matches[i] << '\n';
        }
        else
            cout << "didn't match\n";
    }
}