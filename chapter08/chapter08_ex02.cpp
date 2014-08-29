// Chapter 08, exercise 02: function that prints a vector<int> to cout
// Exercise 03: create a vector of Fibonacci numbers, print them with function
// from exercise 02
// Exercise 04: find approximation to maximum int value

#include "../lib_files/std_lib_facilities.h"

void print(const string& label, const vector<int>& v)
{
    cout << label << " (" << v.size() << "): {";
    for (int i = 0; i<v.size(); ++i) {
        if (i%8 == 0) cout << endl;
        cout << v[i];
        if (i<v.size()-1) cout << ", ";
    }
    cout << "\n}\n";
}

// fill a vector with the Fibonacci sequence
void fibonacci(int x, int y, vector<int>& v, int n)
{
    if (n < 1) error("there must be at least one number in the series");
    v.push_back(x);
    if (n == 1) return;
    v.push_back(y);
    if (n==2) return;
    for (int i = 2; i<n; ++i)
        v.push_back(v[i-2] + v[i-1]);
}

int main()
try
{
    int x = 0;
    int y = 0;
    vector<int> v;
    int n = 0;

    cout << "Enter first number in Fibonacci sequence: ";
    cin >> x;
    cout << "Enter second number in Fibonacci sequence: ";
    cin >> y;
    cout << "Enter number of elements in sequence: ";
    cin >> n;

    fibonacci(x,y,v,n);

    string s = "Your Fibonacci sequence";
    print(s,v);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    char c;
    while (cin>>c && c!=';');
    return 1;
}
catch (...) {
    cerr << "exception\n";
    char c;
    while (cin>>c && c!=';');
    return 2;
}
