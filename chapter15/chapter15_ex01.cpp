// Chapter 15, exercise 01: recursive factorial
#include "Simple_window.h"
#include "Graph.h"

int fac(int n) { return n>1 ? n*fac(n-1) : 1; }

int main()
try {
    for (int i = 0; i<=20; ++i)
        cout << i << "! = " << fac(i) << endl;

    keep_window_open();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
