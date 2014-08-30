// Chapter 17, exercise 05: function that finds the first occurrence of a
// C-style string in another

#include "../lib_files/std_lib_facilities.h"
#include<cstring>

const char* findx(const char* s, const char* x) {
    if (x==0) return s;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == x[0]) {                     // found first matching char
            for (int j = 1; x[j]; ++j) {        // loop through substring
                if (s[i+j]!=x[j]) break;        // does not match
                if (x[j+1]==0) return &s[i];    // found substring
                if (s[i+j+1]==0) return 0;      // s ended before substring
            }
        }
    }
    return 0;
}

int main()
try {
    char* ss = "Does this work with whitespace, too?";
    char* xx = "work with";
    char* s = new char[strlen(ss)+1];
    strcpy(s,ss);
    char* x = new char[strlen(xx)+1];
    strcpy(x,xx);
    const char* sub = findx(s,x);
    if (!sub) cout << "Not found!\n";
    else cout << sub << "\n";
    delete[] s;
    delete[] x;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
