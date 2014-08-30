// Chapter 18, exercise 10: rewrite array solution from 18.6.2. to deal with
// long strings by a) reporting if an input string was too long and b)
// allowing an arbitrarily long string

#include "../lib_files/std_lib_facilities.h"
#include<cstring>

// using arrays
bool is_palindrome(const char s[], int n) {
    int first = 0;
    int last = n - 1;
    while (first < last) {
        if (s[first]!=s[last]) return false;
        ++first;
        --last;
    }
    return true;
}

istream& read_word(istream& is, char* buffer, int max) {
    is.width(max);
    is >> buffer;
    if (strlen(buffer) == max-1) {
        cout << "Input cut off after " << max-1 << " characters!\n";
        char ch;
        while (is.get(ch)) {
            if (ch=='\n') break;
        }
    }
    return is;
}

istream& read_long_word(istream& is, char*& buffer) {
    int max = 128;
    char* temp1 = new char[max];
    *temp1 = 0;
    char ch;
    while (cin.get(ch)) {
        if (ch=='\n') break;
        if (strlen(temp1) == max-1) {
            // double length of temp1
            char* temp2 = new char[max];
            strcpy(temp2,temp1);
            delete[] temp1;
            max *= 2;
            temp1 = new char[max];
            strcpy(temp1,temp2);
            delete[] temp2;
        }
        temp1[strlen(temp1)+1] = 0;
        temp1[strlen(temp1)] = ch;
    }
    buffer = temp1;
    return is;
}

int main()
try {
    // test with overflow warning
    const int max = 128;
    char s[max];
    while (read_word(cin,s,max) && strcmp(s,"quit")) {
        cout << s <<  " is";
        if (!is_palindrome(s,strlen(s))) cout << " not";
        cout << " a palindrome\n";
    }

    // test for arbitrarily long array
    char* s2 = 0;
    while (read_long_word(cin,s2) && strcmp(s2,"quit")) {
            cout << s2 <<  " is";
            if (!is_palindrome(s2,strlen(s2))) cout << " not";
            cout << " a palindrome\n";
            delete[] s2;
    }
    delete[] s2;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
