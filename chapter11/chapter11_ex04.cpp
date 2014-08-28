// Chapter 11, exercise 04: read strings and for each string, present for each
// character its classifications

#include "../lib_files/std_lib_facilities.h"

// print for each character all its classifications
void char_class(const string& s)
{
    for (int i = 0; i<s.size(); ++i) {
        cout << s[i];
        if (isspace(s[i])) cout << " isspace";
        if (isalpha(s[i])) cout << " isalpha";
        if (isdigit(s[i])) cout << " isdigit";
        if (isxdigit(s[i])) cout << " isxdigit";
        if (isupper(s[i])) cout << " isupper";
        if (islower(s[i])) cout << " islower";
        if (isalnum(s[i])) cout << " isalnum";
        if (iscntrl(s[i])) cout << " iscntrl";
        if (ispunct(s[i])) cout << " ispunct";
        if (isprint(s[i])) cout << " isprint";
        if (isgraph(s[i])) cout << " isgraph";
        cout << endl;
    }
}

int main()
try {
    cout << "Enter strings:\n";
    string s;
    while (cin>>s) {
        char_class(s);
        cout << endl;
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
