// Chapter 08, exercise 07: read names and ages, sort names, print out both in
// correct order

#include "../lib_files/std_lib_facilities.h"

vector<string> name;
vector<double> age;

// enter (name,age) pairs
void enter_values()
{
    string s;
    cout << "Enter list of names, 'done' when done:\n";
    while (cin>>s && s!="done") {
        for (int i = 0; i<name.size(); ++i) {
            if (s == name[i]) error("Duplicate name");
        }
        name.push_back(s);
    }

    for (int i = 0; i<name.size(); ++i) {
        cout << "Age of " << name[i] << ": ";
        double a;
        cin >> a;
        age.push_back(a);
    }
}

// print (name,age) pairs
void print(const vector<string>& name,const vector<double>& age)
{
    if (name.size() != age.size()) error("print: vectors must be same size");
    for (int i = 0; i<name.size(); ++i)
        cout << '(' << name[i] << ',' << age[i] << ")\n";
}

// look up index if given string in vector of strings
int find_index(const vector<string>& vec, const string& s)
{
    for (int i = 0; i<vec.size(); ++i) {
        if (vec[i] == s)
            return i;
    }
    error("name not found");
}

int main()
try
{
    enter_values();
    cout << "Entered like this:\n";
    print(name,age);

    vector<string> name_orig = name;
    vector<double> age_orig = age;
    sort(name.begin(),name.end());
    for (int i = 0; i<name.size(); ++i)
        age[i] = age_orig[find_index(name_orig,name[i])];

    cout << "\nAfter sorting:\n";
    print(name,age);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
