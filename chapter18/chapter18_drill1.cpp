// Chapter 18, Drill 1: array drill

#include "../lib_files/std_lib_facilities.h"

const int gas = 10;
int ga[gas] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void print_ar(const int ai[], int n) {
    for (int i = 0; i<n; ++i) cout << ai[i] << " ";
}

void f(int ai[], int n) {
    const int las = 10;
    int la[las];
    for (int i = 0; i<las; ++i) la[i] = ga[i];
    print_ar(la,las);
    cout << "\n";
    int* p = new int[n];
    for (int i = 0; i<n; ++i) p[i] = ai[i];
    print_ar(p,n);
    cout << "\n";
    delete[] p;
}

int main()
try {
    f(ga,gas);
    const int las = 10;
    int aa[las] = { 1 };
    for (int i = 1; i<las; ++i) aa[i] = aa[i-1]*(i+1);
    f(aa,las);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
