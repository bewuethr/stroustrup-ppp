// Chapter 24, exercise 7: rewrite the Gaussian elimination example without
// using the Matrix library, i.e., use built-in arrays or vectors

#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef vector<vector<double>> Matrix;
typedef vector<double> Vector;

//------------------------------------------------------------------------------

struct Elim_failure : runtime_error {
	Elim_failure(int i)
        :runtime_error("Elimination failure at index " + to_string(i)) { }
};

//------------------------------------------------------------------------------

struct Back_subst_failure : runtime_error {
	Back_subst_failure(int i)
        :runtime_error("Back substitution failure at index " + to_string(i)) { }
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Vector& v)
{
    os << "{ ";
    for (int i = 0; i<v.size(); ++i)
        os << v[i] << ' ';
    os << '}';
    return os;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Matrix& m)
{
    os << "{\n";
    for (int i = 0; i<m.size(); ++i)
        os << m[i] << '\n';
    os << '}';
    return os;
}

//------------------------------------------------------------------------------

void classical_elimination(Matrix& A, Vector& b)
{
    const int n = A.size();

    // traverse from 1st column to the next-to-last filling zeros into all
    // elements under the diagonal
    for (int j = 0; j<n-1; ++j) {
        const double pivot = A[j][j];
        if (pivot==0) throw Elim_failure(j);

        // fill zeros into each element under the diagonal of the ith row
        for (int i = j+1; i<n; ++i) {
            const double mult = A[i][j] / pivot;
            for (int k = j; k<n; ++k)
                A[i][k] -= A[j][k] * mult;
            b[i] -= mult * b[j];    // make the corresponding change to b
        }
    }
}

//------------------------------------------------------------------------------

Vector back_substitution(const Matrix& A, const Vector& b)
{
    const int n = A.size();
    Vector x(n);

    for (int i = n-1; i>=0; --i) {
        double s = b[i];
        for (int j = i+1; j<n; ++j)
            s -= A[i][j] * x[j];
        if (double m = A[i][i])
            x[i] = s / m;
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
    Matrix A = { { 1, -2, -3 }, { 0, 2, 1 }, { -1, 1, 2 } };
    Vector b = { 0, -8, 3 };

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
