// Chapter 20, Try This 3: write a function void copy(int* f1, int* e1, int* f2)
// that copies the elements of an array of ints defined by [f1:e1) into another
// [f2:f2+(e1-f1)) using only iterator operations (no subscripting)

#include "../lib_files/std_lib_facilities.h"

void cpy(int* f1, int* e1, int* f2)
{
    while (f1!=e1) {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
}

int main()
try {
    const int sz = 6;
    int ar1[] = { 0, 1, 2, 3, 4, 5 };
    int* par1 = ar1;
    for (int i = 0; i<sz; ++i)
        cout << ar1[i] << ' ';
    cout << "\n";

    int ar2[sz];
    int* par2 = ar2;
    cpy(par1,par1+sz,par2);
    for (int i = 0; i<sz; ++i)
        cout << ar2[i] << ' ';
    cout << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}

