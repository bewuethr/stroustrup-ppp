
//
// This is example code from Chapter 11.5 "Line-oriented input" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//------------------------------------------------------------------------------

using namespace std;

int main()
{
    string name;
    cin >> name;            // input: Dennis Ritchie
    cout << name << '\n';   // output: Dennis

    getline(cin,name);      // input: Dennis Ritchie
    cout << name << '\n';   // output: Dennis Ritchie



    string first_name;
    string second_name;
    stringstream ss(name);
    ss>>first_name;         // input Dennis
    ss>>second_name;        // input Ritchie

    {
        string command;
        getline(cin,command);   // read the line

        stringstream ss(command);
        vector<string> words;
        string s;
        while (ss>>s) words.push_back(s);    // extract the individual words
    }
}

//------------------------------------------------------------------------------
