// Chapter 24, exercise 12: implement
// Matrix<double> operator*(Matrix<double,2>&, Matrix<double>&) and
// Matrix<double,N> operator+(Matrix<double,N>&, Matrix<double,N>&)

#include<iostream>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using Numeric_lib::Index;
using Numeric_lib::Matrix;

//------------------------------------------------------------------------------

namespace Numeric_lib {;

Matrix<double> operator*(const Matrix<double,2>& m, const Matrix<double>& v)
{
    if (m.dim1()!=v.size() || m.dim2()!=v.size())
        error("matrix vector multiplication dimension mismatch");
    Matrix<double> res(v.size());
    for (Index i = 0; i<res.size(); ++i)
        res(i) = dot_product(m[i],v);
    return res;
}

// client has to make sure that dimensions match - can only check size
template<int N>
Matrix<double,N> operator+(const Matrix<double,N>& m1, const Matrix<double,N>& m2)
{
    if (m1.size() != m2.size())
        error("matrix addition: dimension mismatch");
    Matrix<double,N> m3 = m1;
    double* dp3 = m3.data();
    const double* dp2 = m2.data();
    for (int i = 0; i<m3.size(); ++i)
        dp3[i] += dp2[i];
    return m3;
}

}   // Numeric_lib

//------------------------------------------------------------------------------

int main()
try
{
    double m2_arr[][3] = { { 11, 12, 13 },
                        { 21, 22, 23 },
                        { 31, 32, 33 } };
    Matrix<double,2> m2 = m2_arr;
    double v_arr[] = { 1, 2, 3 };
    Matrix<double> v = v_arr;
    Matrix<double> m2_v = m2 * v;
    cout << m2 << "\n *\n" << v << "\n =\n" << m2_v << '\n';

    double v21_arr[] = { 1, 2, 3 };
    double v22_arr[] = { 10, 20, 30 };
    Matrix<double> v21 = v21_arr;
    Matrix<double> v22 = v22_arr;
    Matrix<double> v23 = v21 + v22;
    cout << '\n' << v21 << "\n +\n" << v22 << "\n =\n" << v23 << '\n';

    double m21_arr[][3] =  { { 111, 112, 113 },
                             { 121, 122, 123 },
                             { 131, 132, 133 } };
    double m22_arr[][3] =  { { 211, 212, 213 },
                             { 221, 222, 223 },
                             { 231, 232, 233 } };
    Matrix<double,2> m21 = m21_arr;
    Matrix<double,2> m22 = m22_arr;
    Matrix<double,2> m23 = m21 + m22;
    cout << '\n' << m21 << "\n +\n" << m22 << "\n =\n" << m23 << '\n';

    Matrix<double,3> m31(3,3,3);
    for (int i = 0; i<3; ++i)
        for (int j = 0; j<3; ++j)
            for (int k = 0; k<3; ++k)
                m31(i,j,k) = 100*(i+1) + 10*(j+1) + k+1;
    Matrix<double,3> m32(3,3,3);
    for (int i = 0; i<3; ++i)
        for (int j = 0; j<3; ++j)
            for (int k = 0; k<3; ++k)
                m32(i,j,k) = 300 + 100*(i+1) + 10*(j+1) + k+1;
    Matrix<double,3> m33 = m31 + m32;
    cout << '\n';
    for (int i = 0; i<3; ++i)
        cout << m31[i] << '\n';
    cout << " +\n";
    for (int i = 0; i<3; ++i)
        cout << m32[i] << '\n';
    cout << " =\n";
    for (int i = 0; i<3; ++i)
        cout << m33[i] << '\n';

    // test chaining
    Matrix<double> v24 = v21 + v22 + v23;
    cout << '\n' << v21 << "\n +\n" << v22 << "\n + \n" << v23 << "\n =\n"
        << v24 << '\n';
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
