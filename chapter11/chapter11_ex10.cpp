// Chapter 11, exercise 10: write a function to return a vector of whitespace-
// separated substrings of the argument string where whitespace is regular
// whitespace plus the characters of a string argument

#include "../lib_files/std_lib_facilities.h"

// returns whitespace-separated substrings of s
vector<string> split(const string& s)
{
    istringstream is(s);
    string ss;
    vector<string> substrings;
    while (is>>ss) substrings.push_back(ss);
    return substrings;
}

// checks if string s contains character ch
bool contains(const string& s, char ch)
{
    for (int i = 0; i<s.size(); ++i)
        if (s[i]==ch) return true;
    return false;
}

// returns whitespace-separated substrings of s where
// "whitespace" is defined as "ordinary whitespace plus
// characters in w"
vector<string> split(const string& s, const string& w)
{
    string ss = s;
    for (int i = 0; i<ss.size(); ++i) {
        for (int j = 0; j<w.size(); ++j) {
            if (contains(w,ss[i])) ss[i] = ' ';
        }
    }
    return split(ss);
}

// print vector of strings
void print_vec(const vector<string> vs)
{
    for (int i = 0; i<vs.size(); ++i)
        cout << vs[i] << endl;
}

int main()
try {
    cout << "Enter string with separation characters: ";
    string w;
    getline(cin,w);
    cout << "Enter a few words: ";
    string s;
    while (getline(cin,s)) {
        vector<string> substrings = split(s,w);
        cout << "\nYou entered:\n";
        print_vec(substrings);
        cout << "\nAnother try: ";
    }

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
