// Chapter 05, exercise 08: compute the sum of the first n integers of a user
// specified series of integers, handle all inputs with exceptions

#include "../lib_files/std_lib_facilities.h"

int main()
try {
    vector<int> vals;
    int val = 0;
    int n = 0;

    cout << "Please enter the number of values you want to sum:\n";
    cin >> n;
    if (n < 1) error("You have to sum at least one value!");
    cout << "Please enter some integers (press '|' to stop)\n";
    while (cin>>val)
        vals.push_back(val);

    if (vals.size() < n) error("You wanted to sum more values than you entered, namely", n);

    int sum = 0;
    cout << "The sum of the first ";
    if (n > 1) cout << n << ' ';
    cout << " number";
    if (n > 1) cout << 's';
    cout << " ( ";
    for (int i = 0; i<n; ++i) {
        sum += vals[i];
        cout << vals[i] << ' ';
    }
    cout << ") is " << sum << ".\n";

    return 0;
}
catch (exception& e) {
    cerr << "Error: " << e.what() << endl;
    //keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Unknown exception!\n";
    return 2;
}
