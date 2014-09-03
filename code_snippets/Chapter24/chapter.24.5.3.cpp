
//
// This is example code from Chapter 24.5.3 "2D Matrix" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Matrix.h"

using namespace Numeric_lib;

//------------------------------------------------------------------------------

int f(int a) { return a*a; }

//------------------------------------------------------------------------------

int g(int a, int b) { return a*b; }

//------------------------------------------------------------------------------

enum Piece { none, pawn, knight, queen, king, bishop, rook};

//------------------------------------------------------------------------------

void board()
{
    //enum Piece { none, pawn, knight, queen, king, bishop, rook };
    Matrix<Piece,2> board(8,8);        // a chessboard

    const int white_start_row = 0;
    const int black_start_row = 7;

    //Matrix<Piece>& white_start = board[0]; // works in MS C++, but not ISO C++; binds to rvalue
    //Matrix<Piece>& red_start = board[7];

    Piece a[] = { rook, knight, bishop, queen, king, bishop, knight, rook};
    Matrix<Piece> start_row(a); // = { castle, knight, bishop, queen, king, bishop, knight, castle};
    Matrix<Piece> clear_row(8);

    board[white_start_row] = start_row;    // reset white pieces
    for (int i = 1; i<7; ++i) board[i] = clear_row;    // clear middle of the board
    board[black_start_row] = start_row;    // reset black pieces
}

//------------------------------------------------------------------------------

int main()
{
    Matrix<int,2> a(3,4);

    int s  = a.size();    // number of elements
    int d1 = a.dim1();    // number of elements in a row
    int d2 = a.dim2();    // number of elements in a column
    int* p = a.data();    // extract data as a pointer to a C-style array

    int  i = 1;
    int  j = 2;
    int  n = 2;
    a(i,j);               // (i,j)th element (Fortran style), but range checked
    a[i];                 // ith row (C-style), range checked
    a[i][j];              // (i,j)th element C-style

    a.slice(i);           // the elements from the a[i] to the last
    a.slice(i,n);         // the elements from the a[i] to the a[i+n-1]

    Matrix<int,2> a2 = a; // copy initialization
    a = a2;               // copy assignment
    a *= 7;               // scaling (and +=, -=, /=, etc.)
    a.apply(f);           // a(i,j)=f(a(i,j)) for each element a(i,j)
    a.apply(g,7);         // a(i,j)=g(a(i,j),7) for each element a(i,j)
    Matrix<int,2> b(3,4);
    b=apply(f,a);         // make a new Matrix with b(i,j)==f(a(i,j)) 
    b=apply(g,a,7);       // make a new Matrix with b(i,j)==g(a(i,j),7) 

    a.swap_rows(1,2);     // swap rows a[1] <=> a[2]

    board();
}

//------------------------------------------------------------------------------
