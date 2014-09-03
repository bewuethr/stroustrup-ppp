
//
// This is example code from Chapter 24.5.5 "3D Matrix" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "MatrixIO.h"

using namespace Numeric_lib;

//------------------------------------------------------------------------------

int f(int a) { return a*a; }

//------------------------------------------------------------------------------

int g(int a, int b) { return a*b; }

//------------------------------------------------------------------------------

int main()
{
    Matrix<int,3> a(10,20,30);

    a.size();          // number of elements
    a.dim1();          // number of elements in dimension 1
    a.dim2();          // number of elements in dimension 2
    a.dim3();          // number of elements in dimension 3
    int* p = a.data(); // extract data as a pointer to a C-style array
    int  i = 2;
    int  j = 3;
    int  k = 4;

    a(i,j,k);          // (i,j,k)th element (Fortran style), but range checked
    a[i];              // ith row (C-style), range checked
    a[i][j][k];        // (i,j,k)th element C-style
    a.slice(i);        // the elements from the ith to the last
    a.slice(i,j);      // the elements from the ith to the jth
    Matrix<int,3> a2 = a; // copy initialization
    a = a2;            // copy assignment
    a *= 7;            // scaling (and +=, -=, /=, etc.)
    a.apply(f);        // a(i,j,k)=f(a(i,j)) for each element a(i,j,k)
    a.apply(g,7);      // a(i,j,k)=g(a(i,j),7) for each element a(i,j,k)
    Matrix<int,3> b(10,20,30);
    b=apply(f,a);      // make a new Matrix with b(i,j,k)==f(a(i,j,k)) 
    b=apply(g,a,7);    // make a new Matrix with b(i,j,k)==g(a(i,j,k),7) 
    a.swap_rows(7,9);  // swap rows a[7] <=> a[9]

    int grid_nx = 5;   // grid resolution; set at startup
    int grid_ny = 5;
    int grid_nz = 5;
    Matrix<double,3> cube(grid_nx, grid_ny, grid_nz);
}

//------------------------------------------------------------------------------
