// Chapter 04, exercise 16: find the mode in a vector of integers entered by
// user (only the first, not all of them)

#include "../lib_files/std_lib_facilities.h"

int get_mode(vector<int> v)
{
    sort(v.begin(),v.end());
    int mode_cdt = v[0];
    int mode_cdt_ctr = 1;
    int mode = 0;
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
    cout << "Top value appears " << mode_ctr << " times.\n";
    return mode;
}

int main()
{
    int n = 0;
    int smallest = 0;
    int largest = 0;
    int mode = 0;
    vector<int> vals;
    bool is_first = true;

    cout << "Enter sequence of integers:\n";

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
