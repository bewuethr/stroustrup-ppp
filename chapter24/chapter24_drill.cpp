// Chapter 24, Drill

#include<iostream>
#include<iomanip>
#include<cmath>
#include<complex>
#include<cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

//------------------------------------------------------------------------------

void ex04()
{
    int i;
    cout << "\nEnter ints (char to exit): ";
    //errno = 0;<<
    while (cin >> i) {
        errno = 0;
        double d = sqrt(i);
        if (errno == EDOM)
            cout << "no square root\n";
        else
            cout << "sqrt(" << i << ") = " << d << '\n';
    }
}

//------------------------------------------------------------------------------

void ex05()
{
    cin.clear();
    cin.ignore();
    cout << "\nEnter 10 floating point values: ";
    Matrix<double> m(10);
    double d;
    for (int i = 0; i<m.size(); ++i) {
        cin >> d;
        if (!cin) throw runtime_error("Problem reading from cin");
        m[i] = d;
    }
    cout << "Matrix:\n" << m << '\n';
}

//------------------------------------------------------------------------------

void ex06()
{
    cout << "\nMultiplication table\nEnter n: ";
    int n;
    cin >> n;
    cout << "Enter m: ";
    int m;
    cin >> m;
    Matrix<int,2> mtable(n,m);
    for (Index i = 0; i<mtable.dim1(); ++i) {
        for (Index j = 0; j<mtable.dim2(); ++j) {
            mtable(i,j) = (i+1)*(j+1);
            cout << setw(5) << mtable(i,j);
        }
        cout << '\n';
    }
}

//------------------------------------------------------------------------------

void ex07()
{
    Matrix<complex<double>> m(10);
    cout << "\nEnter 10 complex numbers (Re,Im): ";
    complex<double> c;
    for (int i = 0; i<10; ++i) {
        cin >> c;
        if (!cin) throw runtime_error("problem reading complex number");
        m[i] = c;
    }
    complex<double> sum;
    for (Index i = 0; i<m.size(); ++i)
        sum += m[i];
    cout << "Sum: " << sum << '\n';
}

//------------------------------------------------------------------------------

void ex08()
{
    Matrix<int,2> m(2,3);
    cout << "\nEnter six ints: ";
    int n;
    for (int i = 0; i<m.dim1(); ++i)
        for (int j = 0; j<m.dim2(); ++j) {
            cin >> n;
            m(i,j) = n;
        }
    cout << "Matrix:\n" << m << '\n';
}

//------------------------------------------------------------------------------

int main()
try
{
    // 1: size of various types
    cout << "sizeof:\n";
    cout << "char\t" << sizeof(char) << '\n';
    cout << "short\t" << sizeof(short) << '\n';
    cout << "int\t" << sizeof(int) << '\n';
    cout << "long\t" << sizeof(long) << '\n';
    cout << "float\t" << sizeof(float) << '\n';
    cout << "double\t" << sizeof(double) << '\n';
    cout << "int*\t" << sizeof(int*) << '\n';
    cout << "double*\t" << sizeof(double*) << '\n';

    // 2: size of Matrixes
    cout << "\nMatrix sizes:\n";
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);
    cout << "1D int, 10 elements\t\t" << sizeof(a) << '\n';
    cout << "1D int, 100 elements\t\t" << sizeof(b) << '\n';
    cout << "1D double, 10 elements\t\t" << sizeof(c) << '\n';
    cout << "2D int, 10x10 elements\t\t" << sizeof(d) << '\n';
    cout << "3D int, 10x10x10 elements\t" << sizeof(e) << '\n';

    // 3: number of elements
    cout << "\nNumber of elements (same order):\n";
    cout << "a:\t" << a.size() << '\n';
    cout << "b:\t" << b.size() << '\n';
    cout << "c:\t" << c.size() << '\n';
    cout << "d:\t" << d.size() << '\n';
    cout << "e:\t" << e.size() << '\n';

    // 4: take ints from cin and output sqrt of each or "no square root" if
    // illegal
    ex04();

    // 5: read ten floating-point values from input and put them into a
    // Matrix<double>; print out the Matrix
    ex05();

    // 6: compute a multiplication table for [0,n)*[0,m), represent it as a 2D
    // Matrix. Take n and m from cin and print the table nicely
    ex06();

    // 7: read ten complex<double> from cin, put them into a Matrix, calculate
    // and output the sum of the ten complex numbers
    ex07();

    // 8: read six ints into a Matrix<int,2> m(2,3) and print them out
    ex08();
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
