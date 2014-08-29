// Chapter 04, exercise 09: enter name-and-value pairs, check for double names,
// write out (name,score) pairs
// Exercise 20: output score for given name or "name not found"
// Exercise 21: output names for given score or "score not found"

#include "../lib_files/std_lib_facilities.h"

vector<string> names;
vector<int> scores;

void list_score(string s)
{
    int i = 0;
    while (i<names.size()) {
        if (names[i]==s) {
            cout << '(' << s << ',' << scores[i] << ")\n";
            return;
        }
        ++i;
    }
    cout << "Name not found\n";
}

void list_names(int n)
{
    bool exists = false;
    for (int i = 0; i<scores.size(); ++i) {
        if (scores[i]==n) {
            cout << '(' << names[i] << ',' << n << ")\n";
            exists = true;
        }
    }
    if (!exists)
        cout << "Score not found\n";
}

int main()
{
    // Get names
    string name = " ";
    int score = 0;
    cout << "Enter name-and-value pairs such as 'Joe 17', terminate with 'NoName 0'\n";
    while (cin>>name>>score && !(name=="NoName" && score==0)) {
        names.push_back(name);
        scores.push_back(score);
    }

    // Make sure names are unique
    for (int i = 0; i<names.size(); ++i) {
        for (int j = i+1; j<names.size(); ++j) {
            if (names[i]==names[j])
                simple_error("Name appears twice!");
        }
    }

    // List names
    for (int i = 0; i<names.size(); ++i)
        cout << '(' << names[i] << ',' << scores[i] << ")\n";

    // Search for either score for given name or names for given score
    int sc = 0;
    cout << "Enter name or score ('NoName' to exit):\n";
    while (true) {
        if (cin>>sc)
            list_names(sc);
        else {
            cin.clear();
            string na;
            cin>>na;
            if (na=="NoName")
                return 0;
            list_score(na);
        }
        cout << "Try again:\n";
    }
}
