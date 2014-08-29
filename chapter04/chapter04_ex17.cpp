// Chapter 04, exercise 17: find the mode in a vector of strings entered by user
// (only the first, not all of them)

#include "../lib_files/std_lib_facilities.h"

string get_mode(vector<string> v)
/*
    Sorts the vector, then iterates once through it, keeping track how often the most
    common element has appeared and which one it was. if the next element is different,
    the counter of the potential mode is reset to one and the potential mode is now the
    new element.
*/
{
    sort(v.begin(),v.end());
    string mode_cdt = v[0];
    int mode_cdt_ctr = 1;
    string mode = v[0];
    int mode_ctr = 1;
    for (int i = 1; i<v.size(); ++i) {
        if (v[i]==mode_cdt) {
            ++mode_cdt_ctr;
            if (mode_cdt_ctr>mode_ctr) {
                mode = mode_cdt;
                mode_ctr = mode_cdt_ctr;
            }
        }
        else {
            mode_cdt = v[i];
            mode_cdt_ctr = 1;
        }
    }
    cout << "Mode appears " << mode_ctr << " time";
    if (mode_ctr>1) cout << "s";
    cout << ".\n";
    return mode;
}

int main()
{
    string n = "";
    string smallest = "";
    string largest = "";
    string mode = "";
    vector<string> vals;
    bool is_first = true;

    cout << "Enter a number of strings, end with Ctrl+Z:\n";

    while (cin >> n) {
        if (n < smallest || is_first)
            smallest = n;
        if (n > largest || is_first)
            largest = n;
        vals.push_back(n);
        is_first = false;
    }

    mode = get_mode(vals);
    cout << "smallest value: " << smallest << endl;
    cout << "largest value: " << largest << endl;
    cout << "mode: " << mode << endl;

    sort(vals.begin(),vals.end());
    cout << "values:" << endl;
    for (int i = 0; i<vals.size(); ++i)
        cout << vals[i] << endl;
    return 0;
}
