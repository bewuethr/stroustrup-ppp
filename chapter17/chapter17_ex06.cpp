// Chapter 17, exercise 06: test memory exhaustion

#include "../lib_files/std_lib_facilities.h"

int main()
try {
    int i = 0;
    while (true) {
        cout << ++i << " MB\n";
        double* pd = new double[131072];    // allocate 1 MB
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
