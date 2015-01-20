// Chapter 24, exercise 4: get Gaussian elimination example to work, test with
// simple example

#include<iostream>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using Numeric_lib::Index;
using Numeric_lib::scale_and_add;
using Numeric_lib::dot_product;

typedef Numeric_lib::Matrix<double,2> Matrix;
typedef Numeric_lib::Matrix<double,1> Vector;

//------------------------------------------------------------------------------

namespace Numeric_lib {;

struct Elim_failure : runtime_error {
	Elim_failure(Index i)
        :runtime_error("Elimination failure at index " + to_string(i)) { }
};

struct Back_subst_failure : runtime_error {
	Back_subst_failure(Index i)
        :runtime_error("Back substitution failure at index " + to_string(i)) { }
};

}   // Numeric_lib

using Numeric_lib::Elim_failure;
using Numeric_lib::Back_subst_failure;

//------------------------------------------------------------------------------

void classical_elimination(Matrix& A, Vector& b)
{
    const Index n = A.dim1();

    // traverse from 1st column to the next-to-last filling zeros into all
    // elements under the diagonal
    for (Index j = 0; j<n-1; ++j) {
        const double pivot = A(j,j);
        if (pivot==0) throw Elim_failure(j);

        // fill zeros into each element under the diagonal of the ith row
        for (Index i = j+1; i<n; ++i) {
            const double mult = A(i,j) / pivot;
            A[i].slice(j) = scale_and_add(A[j].slice(j),-mult,A[i].slice(j));
            b(i) -= mult * b(j);    // make the corresponding change to b
        }
    }
}

//------------------------------------------------------------------------------

Vector back_substitution(const Matrix& A, const Vector& b)
{
    const Index n = A.dim1();
    Vector x(n);

    for (Index i = n-1; i>=0; --i) {
        double s = b(i) - dot_product(A[i].slice(i+1),x.slice(i+1));

        if (double m = A(i,i))
            x(i) = s / m;
        else
            throw Back_subst_failure(i);
    }
    return x;
}

//------------------------------------------------------------------------------

Vector classical_gaussian_elimination(Matrix A,Vector b)
{
    classical_elimination(A,b);
    return back_substitution(A,b);
}

//------------------------------------------------------------------------------

int main()
try
{
    double lhs[][3] =  { { 2, -2, 4 }, { -5, 6, -7 }, { 3, 2, 1 } };
    Matrix A(lhs);
    double rhs[] = { 6, -7, 9 };
    Vector b = rhs;

    cout << "A:\n" << A << '\n';
    cout << "\nb:\n" << b << '\n';

    Vector x = classical_gaussian_elimination(A,b);
    cout << "\nx:\n" << x << '\n';
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
