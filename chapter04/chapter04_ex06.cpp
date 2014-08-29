// Chapter 04, exercise 06: convert digits to spelled-out values and vice versa

#include "../lib_files/std_lib_facilities.h"

int main()
{
    vector<string> s_digits;
    s_digits.push_back("zero");
    s_digits.push_back("one");
    s_digits.push_back("two");
    s_digits.push_back("three");
    s_digits.push_back("four");
    s_digits.push_back("five");
    s_digits.push_back("six");
    s_digits.push_back("seven");
    s_digits.push_back("eight");
    s_digits.push_back("nine");
    vector<string> i_digits;
    i_digits.push_back("0");
    i_digits.push_back("1");
    i_digits.push_back("2");
    i_digits.push_back("3");
    i_digits.push_back("4");
    i_digits.push_back("5");
    i_digits.push_back("6");
    i_digits.push_back("7");
    i_digits.push_back("8");
    i_digits.push_back("9");
    string inp = "";
    while (cin>>inp) {
        bool was_found = false;
        for (int i = 0; i<s_digits.size(); ++i) {
            if (s_digits[i]==inp) {
                cout << i << endl;
                was_found = true;
            }
            if (i_digits[i]==inp) {
                cout << s_digits[i] << endl;
                was_found = true;
            }
        }
        if (!was_found)
            cout << "Input must be zero, one, ..., nine or 0-9\n";
    }
}
