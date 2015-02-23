// Chapter 26, exercise 11: time the sum example from 26.6 with m being square
// matrices with dimensions 100, 10,000, 1,000,000 and 10,000,000. Use random
// elements in the range [-10:10). Rewrite the calculation of v to use a more
// efficient (not O(N^2)) algorithm and compare timings.
//
// Dimensions way too big for stupid methods (takes forever) and memory (matrix
// of doubles with 100,000 elements per dimensions: 80 GB!), hence reduced
// number of elements
//
// Also worth to mention: the version in the book passes the matrices by value,
// leading to a lot of copies and unusably slow performance

#include<ctime>
#include<iostream>
#include<exception>
#include<vector>
#include<random>

#include "chapter24/Matrix.h"
#include "chapter24/MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

//------------------------------------------------------------------------------

inline int randint(int max) { return rand()%max; }

inline int randint(int min, int max) { return randint(max-min)+min; }

//------------------------------------------------------------------------------

// sum of elements in m[n]
double row_sum(const Matrix<double,2>& m, int n)
{
    double sum = 0;
    for (Index i = 0; i<m.dim2(); ++i)
        sum += m(n,i);
    return sum;
}

//------------------------------------------------------------------------------

// sum of elements in m[0:n)
double row_accum(const Matrix<double,2>& m, int n)
{
    double s = 0;
    for (Index i = 0; i<n; ++i)
        s += row_sum(m,i);
    return s;
}

//------------------------------------------------------------------------------

// creates random nxn-matrix with elements in range [-10:10)
Matrix<double,2> random_matrix(int n)
{
    Matrix<double,2> m(n,n);
    for (Index i = 0; i<m.dim1(); ++i)
        for (Index j = 0; j<m.dim2(); ++j)
            m(i,j) = randint(-10,10);
    return m;
}

//------------------------------------------------------------------------------

int main()
try {
    srand(time(0));
    vector<int> dims = {100, 200, 400, 800, 1600, 3200};

    cout << "With the dumb method:\n";
    // scales about with the square of the number of elements
    for (int i = 0; i<dims.size(); ++i) {
        clock_t t1 = clock();
        if (t1 == clock_t(-1))
            throw exception("sorry, no clock");
        Matrix<double,2> m = random_matrix(dims[i]);
        vector<double> v;
        for (Index idx = 0; idx<m.dim1(); ++idx)
            v.push_back(row_accum(m,idx+1));
        clock_t t2 = clock();
        if (t2 == clock_t(-1))
            throw exception("sorry, clock overflow");
        cout << "Size " << setw(8) << dims[i] << ": "
            << double(t2-t1)/CLOCKS_PER_SEC << " seconds\n";
    }

    dims.push_back(6400);
    dims.push_back(12800);

    cout << "\nWith the smart method:\n";
    // scales linearly with the number of elements
    for (int i = 0; i<dims.size(); ++i) {
        clock_t t1 = clock();
        if (t1 == clock_t(-1))
            throw exception("sorry, no clock");
        Matrix<double,2> m = random_matrix(dims[i]);
        vector<double> v;
        double sum = 0;
        for (Index idx = 0; idx<m.dim1(); ++idx) {
            sum += row_sum(m,idx);
            v.push_back(sum);
        }
        clock_t t2 = clock();
        if (t2 == clock_t(-1))
            throw exception("sorry, clock overflow");
        cout << "Size " << setw(8) << dims[i] << ": "
            << double(t2-t1)/CLOCKS_PER_SEC << " seconds\n";
    }

}
catch (exception& e) {
    cerr << e.what() << endl;
}
catch (...) {
    cerr << "exception \n";
}

//------------------------------------------------------------------------------
