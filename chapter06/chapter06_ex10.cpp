// Chapter 06, exercise 10: ask for two numbers, then ask if permutations or
// combinations should be calculated, then calculates the corresponding result.
// Should have error checking for everything.

// Permutations: P(a,b) = a!/(a-b)!
// Combinations: C(a,b) = P(a,b)/b!

#include "../lib_files/std_lib_facilities.h"

// calculate factorial
int factorial(int n)
{
    if (n < 0)
        error("factorial of a negative number is not defined");
    if (n == 0)
        return 1;
    int prod = 1;
    for (int i = 1; i<=n; ++i) {
        prod *= i;
        if (prod < 1)
            error("factorial got too large");
    }
    return prod;
}

// calculate permutations
int permutations(int a, int b)
{
    if (a < b)
        error("for P(a,b), a cannot be smaller than b");
    int prod = 1;
    int next = 0;
    for (int i = a-b+1; i<=a; ++i) {
        next = prod * i;
        if (next < prod)
            error("number too large for permutation function");
        prod *= i;
    }
    return prod;

}

// calculate combinations
int combinations(int a, int b)
{
    return permutations(a,b) / factorial(b);
}

int main()
try {
    int a = 0;
    int b = 0;
    while (cin) {
        // get two numbers
        cout << "Enter two integers to get permutations or combinations from:\n";
        cin >> a >> b;
        if (!cin) {
            cout << "Numbers, please!\n";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else {
            // ask if permutations or combinations
            char ch = 0;
            cout << "(P)ermutations or (c)ombinations?\n";
            cin >> ch;
            int res = 0;
            switch (ch) {
            case 'p': case 'P':
                // calculate permutations
                res = permutations(a,b);
                cout << "P(" << a << ',' << b << ") = " << res << endl;
                break;
            case 'c': case 'C':
                // calcluate combinations
                res = combinations(a,b);
                cout << "C(" << a << ',' << b << ") = " << res << endl;
                break;
            default:
                cout << "Illegal choice for 'p' or 'c'\n";
                cin.ignore(10000,'\n');
                break;
            }
        }
    }
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
