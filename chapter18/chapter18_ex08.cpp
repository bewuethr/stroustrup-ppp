// Chapter 18, exercise 08: rewrite all palindrome functions to utilise the
// comparison to backward string approach

#include "../lib_files/std_lib_facilities.h"
#include<cstring>

// using std::string
bool is_palindrome(const string& s) {
    string s_cp;
    for (int i = s.size()-1; i>=0; --i) s_cp.push_back(s[i]);
    if (s==s_cp) return true;
    return false;
}

// using arrays
bool is_palindrome(const char s[], int n) {
    char* s_cp = new char[n+1];
    s_cp[n] = 0;
    for (int i = 0; i<n; ++i) s_cp[n-1-i] = s[i];

    if (strcmp(s,s_cp)) {
        delete[] s_cp;
        return false;
    }

    delete[] s_cp;
    return true;
}

// using pointers
bool is_palindrome(const char* first, const char* last) {
    char* s_cp = new char[last-first+2];
    char* s_cp_ptr = s_cp;
    while (last>=first) {
        *s_cp_ptr = *last;
        ++s_cp_ptr;
        --last;
    }
    *s_cp_ptr = 0;

    if (strcmp(first,s_cp)) {
        delete[] s_cp;
        return false;
    }

    delete[] s_cp;
    return true;
}

istream& read_word(istream& is, char* buffer, int max) {
    is.width(max);
    is >> buffer;
    return is;
}

int main()
try {
    // test string
    string s;
    while (cin>>s && s!="quit") {
        cout << s << " is";
        if (!is_palindrome(s)) cout << " not";
        cout << " a palindrome\n";
    }

    // test array
    const int max = 128;
    char s2[max];
    while (read_word(cin,s2,max) && strcmp(s2,"quit")) {
        cout << s2 <<  " is";
        if (!is_palindrome(s2,strlen(s2))) cout << " not";
        cout << " a palindrome\n";
    }

    // test pointer
    while (read_word(cin,s2,max) && strcmp(s2,"quit")) {
        cout << s2 << " is";
        if (!is_palindrome(&s2[0],&s2[strlen(s2)-1])) cout << " not";
        cout << " a palindrome\n";
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
