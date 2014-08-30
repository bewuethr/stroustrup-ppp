// Chapter 17, exercise 08: same as exercise 7, but read into a std:string

#include "../lib_files/std_lib_facilities.h"

int main()
try {
    char ch;
    string s;
    while (cin>>ch && ch!='!')
        s.push_back(ch);
    cout << s << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
