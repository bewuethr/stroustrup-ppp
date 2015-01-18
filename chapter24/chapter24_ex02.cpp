// Chapter 24, exercise 2: same as exercise 1, but with function objects
// instead of functions

#include<iostream>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

namespace Numeric_lib {;

struct Triple1 {
    void operator()(int& a) { a *= 3; }
};

struct Triple2 {
    int operator()(int a) { return a*3; }
};

struct Triple {
    int operator()(int& a) { a*= 3; return a; }
};

}   // Numeric_lib

int main()
try
{
    int arr[] = { 1, 2, 3, 4, 5 };
    Matrix<int> m1(arr);
    cout << "m1:\t\t\t\t\t" << m1 << '\n';

    m1.apply(Triple1());
    cout << "m1 after m1.apply(Triple1()):\t\t" << m1 << '\n';

    Matrix<int> m2 = apply(Triple2(),m1);
    cout << "m1 after m2 = apply(Triple2(),m1):\t" << m1 << '\n';
    cout << "m2:\t\t\t\t\t" << m2 << '\n';

    m2.apply(Triple());
    cout << "m2 after m2.apply(Triple()):\t\t" << m2 << '\n';
    Matrix<int> m3 = apply(Triple(),m2);
    cout << "m2 after m3 = apply(Triple(),m2):\t" << m2 << '\n';
    cout << "m3:\t\t\t\t\t" << m3 << '\n';
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
