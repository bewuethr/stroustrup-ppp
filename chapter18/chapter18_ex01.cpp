// Chapter 18, exercise 01: function that copies C-style string into heap
// without standard library functions, no subscripting (use dereference
// operator)

// Exercise 02: function that finds first occurrence of C-style string in other
// C-style string withouth standard library functions and subscripting

// Exercise 03: function that compares two C-style strings lexicographically,
// returns -1 if s1 < s2, 0 if s1 == s2, 1 if s1 > s2. Not stdlib functions,
// no subscripting

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

char* findx(const char* s, const char* x) {
    if (x==0 || !*x) return const_cast<char*>(s);
    if (s==0 || !*s) return 0;

    for (int i = 0; *(s+i); ++i) {
        if (*(s+i) == *x) {
            for (int j = 0; *(x+j); ++j) {
                if (!*(s+i+j)) return 0;    // reached end of s
                if (*(s+i+j)!=*(x+j)) break;    // x not found
                if (!*(x+j+1)) return const_cast<char*>(s+i);   // found x
            }
        }
    }
    return 0;   // reached end of s
}

int strcmp(const char* s1, const char* s2) {
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
    if (s==0) error("Cannot print from null pointer");
    while (*s) cout << *s++;
}

int main()
try {
    // test exercise 1
    char s[] = "Test";
    char* s_cpy = strdupl(s);
    print_str(s_cpy);
    cout << "\n";
    delete[] s_cpy;

    // test exercise 2
    char s2[] = "This is a test phrase";
    char x[] = "test";
    cout << "s: " << s2 << "\n";
    cout << "x: " << x << "\n";
    print_str(findx(s2,x));
    cout << "\n";

    // test exercise 3
    const int max = 5;
    char a[max];
    char b[max];
    while (cin>>a>>b) {
        int comp = strcmp(a,b);
        switch (comp) {
        case -1:
            cout << a << " < " << b << "\n";
            break;
        case 0:
            cout << a << " == " << b << "\n";
            break;
        case 1:
            cout << a << " > " << b << "\n";
            break;
        default:
            error("invalid result returned by strcmp");
            break;
        }
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
