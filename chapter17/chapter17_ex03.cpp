// Chapter 17, exercise 03: function that replaces all upercase characters in a
// C-style string with their lowercase equivalents. No standard library
// functions!

#include "../lib_files/std_lib_facilities.h"

void to_lower(char* s) {
    for (int i = 0; s[i]; ++i) {
        if (s[i]>='A' && s[i]<='Z')
            s[i] += 'a'-'A';
    }
}

void print_array(char* s) {
    for (int i = 0; s[i]; ++i) {
        cout << s[i];
    }
}

void test(string s) {
    to_lower(&s[0]);
    print_array(&s[0]);
    cout << "\n";
}

int main()
try {
    string s;
    while (cin>>s && s!="quit")
        test(s);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
