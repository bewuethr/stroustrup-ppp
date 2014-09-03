
//
// This is example code from Chapter 24.5.2 "1D Matrix" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Matrix.h"

using namespace Numeric_lib;

//------------------------------------------------------------------------------

double f(double a) { return a*a; }

//------------------------------------------------------------------------------

double f2(double a, double b) { return a*b; }

//------------------------------------------------------------------------------

double scale(double d, double s) { return d*s; }

//------------------------------------------------------------------------------

void scale_in_place(double& d, double s) { d *= s; }

//------------------------------------------------------------------------------

int main()
{
    Matrix<int,1> a1(8);          // a1 is a 1D Matrix of ints
    Matrix<int>   a(8);           // means Matrix<int,1> a(8);

    a.size();                     // number of elements in Matrix
    a.dim1();                     // number of elements in 1st dimension

    int  i = 4;
    int  n = 7;
    int* p = a.data();            // extract data as a pointer to an array

    a(i);                         // ith element (Fortran style), but range checked
    a[i];                         // ith element (C-style), range checked
    //a(1,2);                     // error: a is a 1D Matrix

    a.slice(i);                   // the elements from the a[i] to the last
    a.slice(i,n);                 // the n elements from the a[i]to a[i+n-1]

    a.slice(4,4) = a.slice(0,4);  // assign first half of a to second half
    a.slice(4) = a.slice(0,4);    // assign first half of a to second half

    Matrix<int> a2 = a;           // copy initialization
    a = a2;                       // copy assignment
    a *= 7;                       // scaling: a[i]*=7 for each i (also +=, -=, /=, etc.)
    a = 7;                        // a[i]=7 for each i

    a.apply(f);                   // a[i]=f(a[i]) for each element a[i]
    a.apply(f2,7);                // a[i]=f(a[i],7) for each element a[i]

    Matrix<int> b = apply(abs,a); // make a new Matrix with b(i)==abs(a(i)) 

    b = a*7;                      // b[i] =a[i]*7 for each i
    a *= 7;                       // a[i] =a[i]*7 for each i
    Matrix<double> x(10);
    Matrix<double> y = apply(f,x);// y[i] =f(x[i]) for each i
    x.apply(f);                   // x[i] =f(x[i]) for each i

    b = apply(f2,a,7);            // b[i]=f(a[i],x) for each i
    b = apply(scale,a,7);         // b[i] = a[i]*7 for each i
    x.apply(scale_in_place,7);    // a[i] *= 7 for each i

    Matrix<int> a3  = scale_and_add(a,8,a2); // fused multiply and add
    int r = dot_product(a3,a);               // dot product

}

//------------------------------------------------------------------------------

void some_function(double* p, int n)
{
    double val[] = { 1.2, 2.3, 3.4, 4.5 };
    Matrix<double> data(p,n);
    Matrix<double> constants(val);
    // ...
}

//------------------------------------------------------------------------------
