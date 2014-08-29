// Chapter 08, exercise 14: functions to determine number of characters in each
// element of a vector<string>, longest and shortest string, lexicographically
// first and last string

#include "../lib_files/std_lib_facilities.h"

// print vector of integers
void print(const vector<int>& v)
{
    cout << "{ ";
    for (int i = 0; i<v.size(); ++i)
        cout << v[i] << ' ';
    cout << " }\n";
}

// print vector of strings
void print(const vector<string>& v)
{
    cout << "{ ";
    for (int i = 0; i<v.size(); ++i)
        cout << v[i] << ' ';
    cout << " }\n";
}

// returns vector with length of each string in argument
vector<int> string_lengths(const vector<string>& v)
{
    if (v.size() == 0) error("string_lengths: argument is empty vector");
    vector<int> lengths;
    for (int i = 0; i<v.size(); ++i)
        lengths.push_back(v[i].size());
    return lengths;
}

// returns longest string in a vector of strings
string longest_string(const vector<string>& v)
{
    if (v.size() == 0) error("longest_string: argument is empty vector");
    string ls;
    int maxl = 0;
    for (int i = 0; i<v.size(); ++i) {
        if (v[i].size() > maxl) {
            maxl = v[i].size();
            ls = v[i];
        }
    }
    return ls;
}

// returns shortest string in a vector of strings
string shortest_string(const vector<string>& v)
{
    if (v.size() == 0) error("shortest_string: argument is empty vector");
    string ss = v[0];
    int minl = v[0].size();
    for (int i = 1; i<v.size(); ++i) {
        if (v[i].size() < minl) {
            minl = v[i].size();
            ss = v[i];
        }
    }
    return ss;
}

// returns lexicographically first string in a vector of strings
string alpha_first_string(const vector<string>& v)
{
    if (v.size() == 0) error("alpha_first_string: argument is empty vector");
    vector<string> v_cp = v;
    sort(v_cp.begin(),v_cp.end());
    return v_cp[0];
}

// returns lexicographically last string in a vector of strings
string alpha_last_string(const vector<string>& v)
{
    if (v.size() == 0) error("alpha_last_string: argument is empty vector");
    vector<string> v_cp = v;
    sort(v_cp.begin(),v_cp.end());
    return v_cp[v_cp.size()-1];
}

int main()
try
{
    vector<string> string_v;
    string_v.push_back("first");
    string_v.push_back("second");
    string_v.push_back("third");
    string_v.push_back("fourth");
    string_v.push_back("fifth");
    string_v.push_back("sixth");
    string_v.push_back("seventh");
    cout << "Vector of strings:\n";
    print(string_v);
    vector<int> lengths = string_lengths(string_v);
    cout << "Vector of lengths:\n";
    print(lengths);
    cout << "Longest string: " << longest_string(string_v) << endl;
    cout << "Shortest string: " << shortest_string(string_v) << endl;
    cout << "Lexicographically first string: " << alpha_first_string(string_v) << endl;
    cout << "Lexicographically last string: " << alpha_last_string(string_v) << endl;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
