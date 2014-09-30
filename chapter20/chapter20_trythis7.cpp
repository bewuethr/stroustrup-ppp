// Chapter 20, Try This 7: create a char[], vector<char>, list<char> and string,
// each with the value "Hello". Pass it as an argument to a function, write out
// the number of characters in the string passed, try to compare it to "Hello"
// and compare the argument to "Howdy" to see which would come first in a dic-
// tionary. Copy the argument into another variable of the same type.

// Could be improved by using an array adapted to STL conventions and having a
// single functions doing the four tests, similar to the single function compa-
// ring the containers to another string.

#include "../lib_files/std_lib_facilities.h"
#include<cstring>

void ac_func(const char ac[])
{
    // get length
    cout << "Length of ac[]: " << strlen(ac) << "\n";

    // compare to "Hello"
    if (strcmp(ac,"Hello")==0) cout << "ac == \"Hello\"\n";

    // compare to "Howdy"
    int comp = strcmp(ac,"Howdy");
    switch (comp) {
    case -1:
        cout << "ac < \"Howdy\"\n";
        break;
    case 0:
        cout << "ac == \"Howdy\"\n";
        break;
    case 1:
        cout << "ac > \"Howdy\"\n";
        break;
    default:
        error("Illegal value");
    }

    // copy into another variable
    char ac_cp[6];          // size of array must be known
    strcpy(ac_cp,ac);
}

template<class T>
int cmp_to_str(const T& lhs, const string& rhs)
{
    int i = 0;

    for (typename T::const_iterator p = lhs.begin(); p!=lhs.end() && i<rhs.size(); ++p) {
        if (*p<rhs[i]) return -1;
        if (*p>rhs[i]) return 1;
        ++i;
    }
    if (lhs.size()<rhs.size()) return -1;
    if (lhs.size()>rhs.size()) return 1;
    return 0;
}

void vc_func(const vector<char>& vc)
{
    cout << "Length of vc: " << vc.size() << "\n";

    if (cmp_to_str(vc,"Hello")==0) cout << "vc == \"Hello\"\n";

    int comp = cmp_to_str(vc,"Howdy");
    switch (comp) {
    case -1:
        cout << "vc < \"Howdy\"\n";
        break;
    case 0:
        cout << "vc == \"Howdy\"\n";
        break;
    case 1:
        cout << "vc > \"Howdy\"\n";
        break;
    default:
        error("Illegal value");
    }

    vector<char> vc_cp = vc;
}

void lc_func(const list<char>& lc)
{
    cout << "Length of lc: " << lc.size() << "\n";

    if (cmp_to_str(lc,"Hello")==0) cout << "lc == \"Hello\"\n";

    int comp = cmp_to_str(lc,"Howdy");
    switch (comp) {
    case -1:
        cout << "lc < \"Howdy\"\n";
        break;
    case 0:
        cout << "lc == \"Howdy\"\n";
        break;
    case 1:
        cout << "lc > \"Howdy\"\n";
        break;
    default:
        error("Illegal value");
    }

    list<char> lc_cp = lc;
}

void sc_func(const string& sc)
{
    cout << "Length of sc: " << sc.size() << "\n";
    if (sc=="Hello") cout << "sc == \"Hello\"\n";
    if (sc<"Howdy") cout << "sc < \"Howdy\"\n";
    string sc_cp = sc;
}

int main()
try {
   char ac[] = "Hello";
   ac_func(ac);
   cout << "\n";

   vector<char> vc;
   vc.push_back('H');
   vc.push_back('e');
   vc.push_back('l');
   vc.push_back('l');
   vc.push_back('o');
   vc_func(vc);
   cout << "\n";

   list<char> lc;
   lc.push_back('H');
   lc.push_back('e');
   lc.push_back('l');
   lc.push_back('l');
   lc.push_back('o');
   lc_func(lc);
   cout << "\n";

   string sc = "Hello";
   sc_func(sc);
   cout << "\n";
}
catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

