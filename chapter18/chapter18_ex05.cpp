// Chapter 18, exercise 05: write a function that concatenates two strings with
// a dot in between

// Exercise 06: modify function to take a string to be used as separator

#include "../lib_files/std_lib_facilities.h"

string cat_dot(const string& s1, const string& s2, const string& s3 = ".") {
    return s1 + s3 + s2;
}

int main()
try {
    cout << cat_dot("Niels","Bohr") << "\n";
    cout << cat_dot("Niels","Bohr","dot") << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
