// Chapter 24, exercise 11: write a swap_columns() analogous to swap_rows()

#include<iostream>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using Numeric_lib::Index;
using Numeric_lib::Matrix;

//------------------------------------------------------------------------------

int main()
try
{
    int lhs[][3] = { { 11, 12, 13 },
                     { 21, 22, 23 },
                     { 31, 32, 33 },
                     { 41, 42, 43 } };
    Matrix<int,2> m2 = lhs;
    cout << "Matrix:\n" << m2 << '\n';
    m2.swap_rows(0,1);
    cout << "\nswap_rows(0,1):\n";
    cout << m2 << '\n';
    m2.swap_columns(1,2);
    cout << "\nswap_columns(1,2):\n";
    cout << m2 << '\n';
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
