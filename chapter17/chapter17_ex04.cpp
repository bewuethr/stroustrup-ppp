// Chapter 17, exercise 04: function that copies a C-style string into memory
// it allocates on the heap without using standard library functions

#include "../lib_files/std_lib_facilities.h"

char* strcopy(const char* s) {
    if (s==0) return 0;

    // get number of char in s
    int n = 0;
    while (s[n] != 0)
        ++n;

    // allocate memory with room for terminating 0
    char* pc = new char[n+1];

    // copy string
    for (int i = 0; s[i]; ++i)
        pc[i] = s[i];
    pc[n] = 0;  // zero-terminated

    delete[] s;
    return pc;
}

int main()
try {
    string s;
    char* cstr;
    while (cin>>s && s!="quit") {
        cstr = strcopy(&s[0]);
        cout << cstr << "\n";
        delete[] cstr;
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
