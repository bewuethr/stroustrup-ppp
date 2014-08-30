// Chapter 18, exercise 04: test what happens with functions from exercise 1-3
// when called with a non-C-style string (free-store- and stack-allocated)

#include "../lib_files/std_lib_facilities.h"

char* strdupl(const char* s) {
    // get size of s
    int i = 0;
    const char* p = s;
    while (*p++) ++i;

    // allocate new string, add space for terminating 0
    char* s_cpy = new char[i+1];

    // copy s, add terminating 0
    char* s_cpy_ptr = s_cpy;
    while (*s) *s_cpy_ptr++ = *s++;
    *s_cpy_ptr = 0;
    return s_cpy;
}

// find substring x in string s, return pointer to first element of x in s
char* findx(const char* s, const char* x) {
    if (x==0 || !*x) return const_cast<char*>(s);
    if (s==0 || !*s) return 0;

    for (int i = 0; *(s+i); ++i) {
        if (*(s+i) == *x) {
            for (int j = 0; *(x+j); ++j) {
                if (!*(s+i+j)) return 0;    // reached end of s
                if (*(s+i+j) != *(x+j)) break;    // x not found
                if (!*(x+j+1)) return const_cast<char*>(s+i);   // found x
            }
        }
    }
    return 0;   // reached end of s
}

int strcomp(const char* s1, const char* s2) {
    if (s1==0||s2==0) error("Null pointer sent to strcmp()");
    for (int i = 0; *(s1+i); ++i) {
        // if only s1 ends or s1[i]<s2[i], s1<s2
        if (*(s1+i)==0 && *(s2+i) || *(s1+i) < *(s2+i)) return -1;

        // if only s2 ends or s1[i]>s2[i], s1>s2
        if (*(s2+i)==0 && *(s1+i) || *(s1+i) > *(s2+i)) return 1;
    }

    // s1 and s2 are identical
    return 0;
}

void print_str(const char* s) {
    if (s==0) {
        cout << "Cannot print from null pointer";
        return;
    }
    while (*s) cout << *s++;
}

void test1() {
    char a[] = { 't','e','s','t' };
    char* ap = new char[4];
    ap[0] = 'T';
    ap[1] = 'E';
    ap[2] = 'S';
    ap[3] = 'T';
    print_str(a);
    cout << "\n";
    print_str(ap);
    cout << "\n";
    char* a_dup = strdupl(a);
    char* ap_dup = strdupl(ap);
    print_str(a_dup);
    cout << "\n";
    print_str(ap_dup);
    cout << "\n";
    delete[] ap_dup;
    delete[] a_dup;
    delete[] ap;
}

void test2() {
    char a[] = "Longer test strin";
    a[sizeof(a)-1] = 'g';
    char b[] = { 't','e','s','t' };
    char* sub = findx(a,b);
    print_str(sub);
    cout << "\n";

    char* ap = new char[sizeof(a)];
    for (int i = 0; i<sizeof(a); ++i)
        ap[i] = a[i];
    char* bp = new char[4];
    bp[0] = 't';
    bp[1] = 'e';
    bp[2] = 's';
    bp[3] = 't';
    char* subp = findx(ap,bp);
    print_str(subp);
    cout << "\n";
    delete[] bp;
    delete[] ap;
}

void test3() {
    char a[] ={ 't','e','s','t','1' };
    char b[] = { 't','e','s','t','1' };
    cout << "strcomp(" << a << "," << b << "): " << strcomp(a,b) << "\n";

    char* ap = new char[5];
    char* bp = new char[5];
    for (int i = 0; i<5; ++i) {
        ap[i] = a[i];
        bp[i] = b[i];
    }
    cout << "strcomp(" << ap << "," << bp << "): " << strcomp(ap,bp) << "\n";
    delete[] bp;
    delete[] ap;
}

int main()
try {
    // call strdupl with non-zero-terminated string
    test1();

    // call findx with non-zero terminated strings
    test2();

    // call strcomp with non-zero terminated strings
     test3();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
