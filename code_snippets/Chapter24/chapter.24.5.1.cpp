
//
// This is example code from Chapter 24.5.1 "Dimensions and access" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include "Matrix.h"

using namespace std;
using namespace Numeric_lib;

//------------------------------------------------------------------------------

void f(int n1, int n2, int n3)
{
    Matrix<double,1> ad1(n1);       // elements are doubles; one dimension    
    Matrix<int,1>    ai1(n1);       // elements are ints; one dimension
    ad1(7) = 0;                     // subscript using ( ) - Fortran style
    ad1[7] = 8;                     // [ ] also works - C style

    Matrix<double,2> ad2(n1,n2);    // 2 dimensional
    Matrix<double,3> ad3(n1,n2,n3); // 3 dimensional
    ad2(3,4)   = 7.5;               // true multidimensional subscripting
    ad3(3,4,5) = 9.2;
}

//------------------------------------------------------------------------------

void f1(int n1, int n2, int n3)
{
    //Matrix<int,0> ai0;            // error: no 0D matrices

    Matrix<double,1> ad1(5);
    Matrix<int,1>    ai(5);
    Matrix<double,1> ad11(7); 

    ad1(7) = 0;                     // Matrix_error exception (7 is out of range)
    //ad1 = ai;                     // error: different element types
    ad1 = ad11;                     // Matrix_error exception (different dimensions)

    //Matrix<double,2>  ad2(n1);    // error: length of 2nd dimension missing
    //ad2(3) = 7.5;                 // error: wrong number of subscripts
    //ad2(1,2,3) = 7.5;             // error: wrong number of subscripts

    Matrix<double,3> ad3(n1,n2,n3);
    Matrix<double,3> ad33(n1,n2,n3);
    ad3 = ad33;                     // ok: same element type, same dimensions
}

//------------------------------------------------------------------------------

void init(Matrix<int,2>& a) // initialize each element to a characteristic value
{
    for (int i=0; i<a.dim1(); ++i)
        for (int j = 0; j<a.dim2(); ++j)
            a(i,j) = 10*i+j;
}

//------------------------------------------------------------------------------

void print(const Matrix<int,2>& a) // print the elements of a row by row
{
    for (int i=0; i<a.dim1(); ++i) {
        for (int j = 0; j<a.dim2(); ++j)
            cout << a(i,j) <<'\t';
        cout << '\n';
    }
}

//------------------------------------------------------------------------------

//void init(Matrix& a);  // error: element type and number of dimensions missing

//------------------------------------------------------------------------------

int main()
try
{
    Matrix<int,2> a(4,3);
    init(a);
    print(a);
    f1(10, 20, 30);
    f(10, 20, 30);
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
