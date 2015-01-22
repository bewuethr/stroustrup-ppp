// Chapter 24, exercise 6: in the Gaussian elimination example, replace the
// vector operations dot_product() and scale_and_add() with loops

#include<iostream>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using Numeric_lib::Index;

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
            for (Index k = j; k<n; ++k) // replaces scale_and_add()
                A(i,k) -= A(j,k) * mult;
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
        double s = b(i);
        for (Index j = i+1; j<n; ++j)   // replaces dot_product()
            s -= A(i,j) * x(j);
        if (double m = A(i,i))
            x(i) = s / m;
        else
            throw Back_subst_failure(i);
    }
    return x;
}

//------------------------------------------------------------------------------

Vector classical_gaussian_elimination(Matrix A, Vector b)
{
    classical_elimination(A,b);
    return back_substitution(A,b);
}

//------------------------------------------------------------------------------

int main()
try
{
    double lhs[][3] =  { { 1, -2, -3 }, { 0, 2, 1 }, { -1, 1, 2 } };
    Matrix A(lhs);
    double rhs[] = { 0, -8, 3 };
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
