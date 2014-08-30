// Chapter 18, exercise 04: then redesign the functions to take argument giving
// the number maximum number of elements allowed in argument strings. Test with
// correct and "bad" strings

#include "../lib_files/std_lib_facilities.h"

char* strdupl(const char* s, int num_max = 128) {
    // get size of s
    int i = 0;
    const char* p = s;
    while (*p++) ++i;
    if (i>num_max) i = num_max;

    // allocate new string, add space for terminating 0
    char* s_cpy = new char[i+1];

    // copy s, add terminating 0
    char* s_cpy_ptr = s_cpy;
    int ctr = 0;
    while (*s && ctr<num_max) {
        *s_cpy_ptr++ = *s++;
        ++ctr;
    }
    *s_cpy_ptr = 0;
    return s_cpy;
}

// find substring x in string s, return pointer to first element of x in s
char* findx(const char* s, const char* x,
            int num_max_s = 128, int num_max_x = 128) {
    if (x==0 || !*x) return const_cast<char*>(s);
    if (s==0 || !*s) return 0;

    for (int i = 0; *(s+i) && i<num_max_s; ++i) {
        if (*(s+i) == *x) {
            for (int j = 0; *(x+j) && j<num_max_x; ++j) {
                if (!*(s+i+j) || (i+j)==num_max_s) return 0;    // reached end of s
                if (*(s+i+j) != *(x+j)) break;    // x not found
                if (!*(x+j+1) || (j+1)==num_max_x)
                    return const_cast<char*>(s+i);   // found x
            }
        }
    }
    return 0;   // reached end of s
}

int strcomp(const char* s1, const char* s2,
            int num_max_s1 = 128, int num_max_s2 = 128) {
    if (s1==0||s2==0) error("Null pointer sent to strcomp()");
    for (int i = 0; i<num_max_s1; ++i) {
        // if only s1 ends or s1[i]<s2[i], s1<s2
        if ((*(s1+i)==0 || i+1==num_max_s1) && *(s2+i) && i+1<num_max_s2 || *(s1+i) < *(s2+i)) return -1;

        // if only s2 ends or s1[i]>s2[i], s1>s2
        if ((*(s2+i)==0 || i+1==num_max_s2) && *(s1+i) && i+1<num_max_s1 || *(s1+i) > *(s2+i)) return 1;
    }

    // s1 and s2 are identical
    return 0;
}

void print_str(const char* s, int num_max = 128) {
    if (s==0) {
        cout << "Cannot print from null pointer";
        return;
    }
    int ctr = 0;
    while (*s && ctr<num_max) {
        cout << *s++;
        ++ctr;
    }
}

int main()
try {
    // test new duplicate function
    char a[] = "test";
    char* a_dpl = strdupl(a,5);
    print_str(a_dpl);
    cout << "\n";
    char b[] = { 't','e','s','t' };
    char* b_dpl = strdupl(b,4);
    print_str(b_dpl);
    cout << "\n";
    delete[] b_dpl;
    delete[] a_dpl;

    // test new find substring function
    char s[] = "xxxtestxxx";
    char x[] = "test";
    char* sub = findx(s,x);
    print_str(sub);
    cout << "\n";
    char s2[] = { 'x','x','t','e','s','t','x','x' };
    char x2[] = { 't','e','s','t' };
    char* sub2 = findx(s2,x2,8,4);
    print_str(sub2,6);
    cout << "\n";

    // test new comparison function
    char str1[] = "atest";
    char str2[] = "btest";
    cout << str1 << " to " << str2 << " is " << strcomp(str1,str2) << "\n";
    char str3[] = { 't','e','s','t','1' };
    char str4[] = { 't','e','s','t','1', 'a' };
    cout << str3 << " to " << str4 << " is " << strcomp(str3,str4,5,6) << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
