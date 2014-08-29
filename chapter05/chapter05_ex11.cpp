// Chapter 05, exercise 11: write out the first so many elements of the
// Fibonacci series n[i] = n[i-1] + n[i-2], starting with 1, 1, 2, 3, 5, ...
// Can be used to find the biggest Fibonacci number that fits in an int

#include "../lib_files/std_lib_facilities.h"

int main()
try {
    char largest = 0;
    cout << "Do you just want to find the largest Fibonacci number (y/n)?\n";
    cin >> largest;
    if (!(largest=='y' || largest=='n' || largest=='Y' || largest=='N'))
        error("Please enter either 'y' or 'n'");
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);
    if (largest=='n' || largest=='N') {
        int n = 0;
        cout << "How many Fibonacci numbers do you want to see?\n";
        cin >> n;
        if (n < 1) error("Please enter a non-negative number");
        for (int i = 2; fib.size()<n; ++i) {
            fib.push_back(fib[i-1]+fib[i-2]);
        }

        cout << "Fibonacci numbers:\n";
        for (int i = 0; i<n; ++i)
            cout << fib[i] << endl;
    }
    else {
        while (fib[fib.size()-1] + fib[fib.size()-2] > fib[fib.size()-1])
            fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
        cout << "The biggest Fibonacci number to fit in an int is " << fib[fib.size()-1] << endl;
    }

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
