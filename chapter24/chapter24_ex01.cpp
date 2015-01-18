// Chapter 24, exercise 1: write a triple() function for a.apply(f) and for
// apply(f,a) to triple the elements of an array { 1 2 3 4 5 }. Define a single
// triple() function that can be used for both a.apply(triple) and
// apply(triple,a).

#include<iostream>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

namespace Numeric_lib {;

void triple1(int& elem)
{
    elem *= 3;
}

int triple2(int elem)
{
    return 3*elem;
}

int triple(int& elem)
{
    elem *= 3;
    return elem;
}

}   // Numeric_lib

int main()
try
{
    int arr[] = { 1, 2, 3, 4, 5 };
    Matrix<int> m1(arr);
    cout << "m1:\t\t\t\t\t" << m1 << '\n';

    m1.apply(triple1);
    cout << "m1 after m1.apply(triple1):\t\t" << m1 << '\n';

    Matrix<int> m2 = apply(triple2,m1);
    cout << "m1 after m2 = apply(triple2,m1):\t" << m1 << '\n';
    cout << "m2:\t\t\t\t\t" << m2 << '\n';

    m2.apply(triple);
    cout << "m2 after m2.apply(triple):\t\t" << m2 << '\n';
    Matrix<int> m3 = apply(triple,m2);
    cout << "m2 after m3 = apply(triple,m2):\t\t" << m2 << '\n';
    cout << "m3:\t\t\t\t\t" << m3 << '\n';
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
