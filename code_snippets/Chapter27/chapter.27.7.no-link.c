/*
//
// This is example code from Chapter 27.7 "Constants and macros" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
*/

/*----------------------------------------------------------------------------*/

const int max = 30;
const int x;    /* const not initialized: ok in C (error in C++) */

/*----------------------------------------------------------------------------*/

void f(int v)
{
    /*int a1[max];*/  /* error: array bound not a constant (ok in C++) */
                      /*  (max is not allowed in a constant expression!) */
    /*int a2[x];*/    /* error: array bound not a constant */

    switch (v) {
    case 1:
        /* ... */
        break;
    /*case max:*/     /* error: case label not a constant (ok in C++) */
        /* ... */
        break;
    }
}

/*----------------------------------------------------------------------------*/

/* file x.c: */
const int x;        /* initialize elsewhere */

/*----------------------------------------------------------------------------*/

/* file xx.c: */
const int x = 7;    /* here is the real definition */

#define  MAX 30

void f1(int v)
{
    int a1[MAX];        /* ok */

    switch (v) {
    case 1:
        /* ... */
        break;
    case MAX:        /* ok */
        /* ... */
        break;
    }
}

/*----------------------------------------------------------------------------*/
