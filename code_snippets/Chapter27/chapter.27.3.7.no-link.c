/*
//
// This is example code from Chapter 27.3.7 "Namespaces" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
*/

/*----------------------------------------------------------------------------*/

// in bs.h:
typedef struct bs_string { /* ... */ char* str; } bs_string; // Bjarne's string
typedef int bs_bool ;          // Bjarne's Boolean type

/*----------------------------------------------------------------------------*/

// in pete.h:
typedef char* pete_string;     // Pete's string
typedef char pete_bool ;       // Pete's Boolean type

/*----------------------------------------------------------------------------*/
