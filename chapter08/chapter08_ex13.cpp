// Chapter 08, exercise 13:improve print_until_s() from §8.5.2; write
// print_until_ss() that prints until second occurrence of quit argument

#include "../lib_files/std_lib_facilities.h"

// print until quit string occurs
void print_until_s(const vector<string>& v, const string& quit)
{
    for (int i = 0; i<v.size(); ++i) {
        if (v[i]==quit) return;
        cout << v[i] << endl;
    }
}

// print until quit string occurs twice
void print_until_ss(const vector<string>& v, const string& quit)
{
    int counter = 0;
    for (int i = 0; i<v.size(); ++i) {
        if (v[i]==quit)
            if (counter==1) return;
            else ++counter;
        cout << v[i] << endl;
    }
}

int main()
try
{
    vector<string> v;
    v.push_back("one");
    v.push_back("word");
    v.push_back("and");
    v.push_back("then");
    v.push_back("another");
    v.push_back("word");
    cout << "print_until_s:\n";
    print_until_s(v,"word");
    cout << "print_until_ss:\n";
    print_until_ss(v,"word");
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
