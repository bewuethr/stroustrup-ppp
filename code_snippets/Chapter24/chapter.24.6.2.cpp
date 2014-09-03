
//
// This is example code from Chapter 24.6.2 "Pivoting" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using Numeric_lib::Index;

//------------------------------------------------------------------------------

typedef Numeric_lib::Matrix<double, 2> Matrix;
typedef Numeric_lib::Matrix<double, 1> Vector;

//------------------------------------------------------------------------------

void elim_with_partial_pivot(Matrix& A, Vector& b)
{
    const Index n = A.dim1();

    for (Index j = 0; j < n; ++j) {
        Index pivot_row = j;

        // look for a suitable pivot:
        for (Index k = j + 1; k < n; ++k)
            if (abs(A(k, j)) > abs(A(pivot_row, j))) pivot_row = j;

        // swap the rows if we found a better pivot:
        if (pivot_row != j) {
            A.swap_rows(j, pivot_row);
            std::swap(b(j), b(pivot_row));
        }

        // elimination:
        for (Index i = j + 1; i < n; ++i) {
            const double pivot = A(j, j);
            if (pivot==0) error("can't solve: pivot==0");
            const double mult = A(i, j)/pivot;
            A[i].slice(j) = scale_and_add(A[j].slice(j), -mult,
                A[i].slice(j)); 
            b(i) -= mult * b(j);
        }
    }
}

//------------------------------------------------------------------------------

Vector back_substitution(const Matrix& A, const Vector& b)
{
    const Index n = A.dim1();
    Vector x(n);

    for (Index i = n - 1; i >= 0; --i) {
        double s = b(i)-dot_product(A[i].slice(i+1),x.slice(i+1));

        if (double m = A(i, i))
            x(i) = s / m;
        else
            error("can't solve: diagonal element is zero during back substitution");
    }

    return x;
}

//------------------------------------------------------------------------------

Vector pivotal_elimination(Matrix A, Vector b)
{
    elim_with_partial_pivot(A, b);
    return back_substitution(A, b);
}

//------------------------------------------------------------------------------

int main()
try
{
    double a[3][3] = 
    {
       {1,2,3},
       {2,3,4},
       {3,4,1}
    };
    double b[3] = {14,20,14};

    Matrix A(a);
    Vector B(b);

    cout << "Solving A*x=B" << endl;
    cout << "A=\n" << A << endl;
    cout << "B="   << B << endl;

    Vector x = pivotal_elimination(A, B);
    cout << "x="   << x << endl;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
