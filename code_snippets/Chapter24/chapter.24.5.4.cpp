
//
// This is example code from Chapter 24.5.4 "Matrix I/O" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

//------------------------------------------------------------------------------

int main()
{
    Matrix<double> a(4);
    cin >> a;
    cout << a;

    Matrix<int,2> m(2,2);
    cin >> m;
    cout << m;
}

//------------------------------------------------------------------------------
