// Chapter 11, exercise 02: read text file, "disemvowel" it and produce new
// file. Example: "Once upon a time!" becomes "nc pn tm!".
// Use pics_and_txt/chapter11_ex01_in.txt for input

#include "../lib_files/std_lib_facilities.h"

// check if letter is a vowel
bool isvowel(char ch)
{
    ch = tolower(ch);
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

// check if string consists of vowels only
bool allvowels(const string& s)
{
    for (int i = 0; i<s.size(); ++i)
        if (!isvowel(s[i])) return false;
    return true;
}

// take all vowels out of string
void disemvowel(string& s)
{
    string s_novow;
    for (int i = 0; i<s.size(); ++i) {
        if (!isvowel(s[i])) s_novow.push_back(s[i]);
    }
    s = s_novow;
}

int main()
try {
    cout << "Enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ifs(iname.c_str());
    if (!ifs) error("can't open input file ",iname);

    cout << "Enter output file name: ";
    string oname;
    cin >> oname;
    ofstream ofs(oname.c_str());
    if (!ofs) error("can't open output file ",oname);

    char ch;
    string s;
    while (ifs.get(ch)) {
        if (isgraph(ch)) {
            ifs.unget();
            ifs >> s;
            if (allvowels(s)) ifs.get(ch); // don't print s, skip next space
            else {
                disemvowel(s);
                ofs << s;
            }
        }
        else ofs << ch;
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
