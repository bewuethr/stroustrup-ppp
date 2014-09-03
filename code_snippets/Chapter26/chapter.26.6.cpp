
//
// This is example code from Chapter 26.6 "Performance" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template <class T, int N>
class Matrix 
{
public:
    int dim1() const { return N; }
    T operator()(int n1, int n2) const { return T(); } // not an actual implementation
};

//------------------------------------------------------------------------------

double row_sum(Matrix<double,2> m, int n)    // sum of elements in m[n]
{
    double s = 0;
    for (int i=0; i<n; ++i) s+=m(n,i);
    return s;
}

//------------------------------------------------------------------------------

double row_accum(Matrix<double,2> m, int n)  // sum of elements in m[0:n)
{
    double s = 0;
    for (int i=0; i<n; ++i) s+=row_sum(m,i);
    return s;
}

//------------------------------------------------------------------------------

int main()
{
    Matrix<double,2> m;
    // compute accumulated sums of rows of m:
    vector<double> v;
    for (int i = 0; i<m.dim1(); ++i) v.push_back(row_accum(m,i+1));

    const char* s = "Hello";
    for (int i=0; i<strlen(s); ++i) { /* do something with s[i] */ }
}

//------------------------------------------------------------------------------
