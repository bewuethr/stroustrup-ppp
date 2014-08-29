// Chapter 08, exercise 15: try to declare a non-reference function argument

#include "../lib_files/std_lib_facilities.h"

void f(const int n)
{
//    ++n;  // cannot modify const argument
    cout << n << endl;
}

int main()
try
{
    int n = 10;
    f(n);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
