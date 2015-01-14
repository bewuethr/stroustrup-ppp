// Chapter 23, exercise 14: like the sample program from 23.8.7, but read input
// from file into memory and experiment with patterns including '\n'

#include<regex>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    string ifname = "pics_and_txt/chapter23_ex12_in.txt";
    ifstream ifs(ifname);
    if (!ifs) throw runtime_error("Can't open " + ifname);
    string line;
    string text;
    while (getline(ifs,line))
        text += line + "\n";

    regex pattern;

    string pat;
    string prompt = "Enter pattern (qqq to exit): ";
    cout << prompt;
    while (getline(cin,pat)) {   // read pattern
        if (pat=="qqq") break;
        try {
            pattern = pat;  // this checks pat
        }
        catch (regex_error) {
            cout << pat << " is not a valid regular expression\n";
            exit(1);
        }

        smatch matches;
        if (regex_search(text,matches,pattern))
            cout << "Match found: " << matches[0] << '\n';
        else
            cout << "No match found\n";
        cout << prompt;
    }
}
