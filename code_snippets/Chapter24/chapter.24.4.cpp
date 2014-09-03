
//
// This is example code from Chapter 24.4 "C-style multidimensional arrays" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int main()
{
    int ai[4];        // 1 dimensional array 
    double ad[3][4];  // 2 dimensional array
    char ac[3][4][5]; // 3 dimensional array
    ai[1] = 7;
    ad[2][3] = 7.2;
    ac[2][3][4] = 'c';    
}

//------------------------------------------------------------------------------

void f1(int a[3][5]);                     // useful for [3][5] matrices only

//------------------------------------------------------------------------------

void f2(int [ ][5], int dim1);            // 1st dimension can be a variable 

//------------------------------------------------------------------------------

//void f3(int [5 ][ ], int dim2);         // error: 2nd dimension cannot be a variable

//------------------------------------------------------------------------------

//void f4(int[ ][ ], int dim1, int dim2); // error (and wouldn't work anyway)

//------------------------------------------------------------------------------

void f5(int* m, int dim1, int dim2)       // odd, but works
{
    for (int i=0; i<dim1; ++i)
        for (int j = 0; j<dim2; ++j) m[i*dim2+j] = 0;
}

//------------------------------------------------------------------------------
