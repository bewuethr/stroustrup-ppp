// Chapter 18, exercise 07: write functions from exercises 5 and 6 for C-style
// strings, no stdlib functions and types allowed

#include "../lib_files/std_lib_facilities.h"

char* cat_dot(const char* s1, const char* s2) {
    // get length of s1 and s2
    const char* p = s1;
    int ctr = 0;
    while (*p) { ++ctr; ++p; }
    p = s2;
    while (*p) { ++ctr; ++p; }

    // allocate new array with extra room for '.' and terminating 0
    char* res = new char[ctr+2];

    // copy arrays
    p = s1;
    char* res_ptr = res;
    while (*p) *res_ptr++ = *p++;
    *res_ptr++ = '.';
    p = s2;
    while (*p) *res_ptr++ = *p++;
    *res_ptr = 0;

    return res;
}

char* cat_dot2(const char* s1, const char* s2, const char* s3) {
    // get length of s1, s2 and s3
    const char* p = s1;
    int ctr = 0;
    while (*p) { ++ctr; ++p; }
    p = s2;
    while (*p) { ++ctr; ++p; }
    p = s3;
    while (*p) { ++ctr; ++p; }

    // allocate new array with extra room for terminating 0
    char* res = new char[ctr+1];

    // copy arrays
    p = s1;
    char* res_ptr = res;
    while (*p) *res_ptr++ = *p++;
    p = s3;
    while (*p) *res_ptr++ = *p++;
    p = s2;
    while (*p) *res_ptr++ = *p++;
    *res_ptr = 0;

    return res;
}

int main()
try {
    char* res = cat_dot("Niels","Bohr");
    cout << res << "\n";
    delete[] res;

    res = cat_dot2("Niels","Bohr"," dot ");
    cout << res << "\n";
    delete[] res;

    char a[] = "Niels";
    char b[] = "Bohr";
    res = cat_dot(a,b);
    cout << res << "\n";
    delete[] res;

    char* ap = "Niels";
    char* bp = "Bohr";
    res = cat_dot(a,b);
    cout << res << "\n";
    delete[] res;

    char* as = new char[6];
    for (int i = 0; i<6; ++i) as[i] = ap[i];
    char* bs = new char[5];
    for (int i = 0; i<5; ++i) bs[i] = bp[i];
    res = cat_dot(as,bs);
    cout << res << "\n";
    delete[] res;
    delete[] bs;
    delete[] as;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
