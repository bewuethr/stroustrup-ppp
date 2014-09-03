
//
// This is example code from Chapter 24.6.1 "Classical Gaussian elimination" of
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

void classical_elimination(Matrix& A, Vector& b);

//------------------------------------------------------------------------------

Vector back_substitution(const Matrix& A, const Vector& b);

//------------------------------------------------------------------------------

template<class T>
string to_string(const T& t)
{
    ostringstream os;
    os << t;
    return os.str();
}

//------------------------------------------------------------------------------

// An exception of this type is thrown when elimination fails.
struct Elim_failure : std::domain_error {
    Elim_failure(std::string s) : std::domain_error(s) { }
};

//------------------------------------------------------------------------------

// An exception of this type is thrown when back substitution fails.
struct Back_subst_failure : std::domain_error {
    Back_subst_failure(std::string s) : std::domain_error(s) { }
};

//------------------------------------------------------------------------------

Vector classical_gaussian_elimination(Matrix A, Vector b)
{
    classical_elimination(A, b);
    return back_substitution(A, b);
}

//------------------------------------------------------------------------------

void classical_elimination(Matrix& A, Vector& b)
{
    const Index n = A.dim1();

    // traverse from 1st column to the next-to-last
    // filling zeros into all elements under the diagonal:
    for (Index j = 0; j<n-1; ++j) {
        const double pivot = A(j, j);
        if (pivot == 0) throw Elim_failure("Elimination failure in row " + to_string(j));

        // fill zeros into each element under the diagonal of the ith row:
        for (Index i = j+1; i<n; ++i) {
            const double mult = A(i, j) / pivot; 
            A[i].slice(j) = scale_and_add(A[j].slice(j), -mult,
                A[i].slice(j));
            b(i) -= mult * b(j); // make the corresponding change to b
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
            throw Back_subst_failure("Back substitution failure in row " + to_string(i));
    }

    return x;
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

    Vector x = classical_gaussian_elimination(A, B);
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
