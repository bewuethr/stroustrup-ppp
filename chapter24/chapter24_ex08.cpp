// Chapter 24, exercise 8: animate Gaussian elimination

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

void anim_print(const Matrix& A, const Vector& b)
{
    for (int i = 0; i<A.dim1(); ++i)
        cout << A[i] << " {" << setw(5) << setprecision(3) << b(i) << " }\n";
    cin.ignore();
    system("cls");
}

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
        anim_print(A,b);
    }
}

//------------------------------------------------------------------------------

void elim_with_partial_pivot(Matrix& A, Vector& b)
{
    const Index n = A.dim1();

    for (Index j = 0; j<n; ++j) {
        Index pivot_row = j;

        // look for a suitable pivot
        for (Index k = j+1; k<n; ++k)
            if (abs(A(k,j)) > abs(A(pivot_row,j))) pivot_row = k;

        // swap the rows if we found a better pivot
        if (pivot_row != j) {
            A.swap_rows(j,pivot_row);
            swap(b(j),b(pivot_row));
        }

        // elimination
        for (Index i = j+1; i<n; ++i) {
            const double pivot = A(j,j);
            if (pivot==0) throw runtime_error("can't solve: pivot==0");
            const double mult = A(i,j) / pivot;
            A[i].slice(j) = scale_and_add(A[j].slice(j),-mult,A[i].slice(j));
            b(i) -= mult * b(j);
        }
    }
}

//------------------------------------------------------------------------------

Vector back_substitution(Matrix& A, Vector& b)
{
    const Index n = A.dim1();
    Vector x(n);

    for (Index i = n-1; i>=0; --i) {
        double s = b(i) - dot_product(A[i].slice(i+1),x.slice(i+1));

        if (double m = A(i,i)) {
            x(i) = s / m;
            b(i) = x(i);
            A(i,i) = 1;
            A[i].slice(i+1) = scale_and_add(A[i].slice(i+1),-1.0,A[i].slice(i+1));
        }
        else
            throw Back_subst_failure(i);
        anim_print(A,b);
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

Vector gaussian_elimination_w_pivot(Matrix A, Vector b)
{
    elim_with_partial_pivot(A,b);
    return back_substitution(A,b);
}

//------------------------------------------------------------------------------

int main()
try
{
    double lhs[][5] =  { { 2, 2, 3, 4, 5 },
                         { 1, 3, 3, 4, 5 },
                         { 1, 2, 4, 4, 5 },
                         { 1, 2, 3, 5, 5 },
                         { 1, 2, 3, 4, 6 } };
    Matrix A(lhs);
    double rhs[] = { 6, -7, 9, 8, 10 };
    Vector b = rhs;

    anim_print(A,b);

    Vector x = classical_gaussian_elimination(A,b);
    cout << "x:\n" << x << '\n';
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
