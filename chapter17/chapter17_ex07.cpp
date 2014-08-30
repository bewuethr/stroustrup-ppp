// Chapter 17, exercise 07: read characters from cin into array on heap; read
// until '!' is entered, do not use std::string, ignore memory exhaustion

#include "../lib_files/std_lib_facilities.h"

// copy C-style string into new array one element bigger
char* add_size(const char* s) {
    if (s==0) return 0;

    // get number of char in s
    int n = 0;
    while (s[n] != 0)
        ++n;

    // allocate memory with room for terminating 0
    char* pc = new char[n+2];

    // copy string
    for (int i = 0; s[i]; ++i)
        pc[i] = s[i];
    pc[n] = 0;  // zero-terminated

    delete[] s;
    return pc;
}

int main()
try {
    char ch;
    char* my_array = new char[1];
    *my_array = 0;
    while (cin>>ch && ch!='!') {
        my_array = add_size(my_array);
        int i = 0;
        for (; my_array[i]; ++i);
        my_array[i] = ch;
        my_array[i+1] = 0;
    }

    cout << my_array << "\n";
    delete[] my_array;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
