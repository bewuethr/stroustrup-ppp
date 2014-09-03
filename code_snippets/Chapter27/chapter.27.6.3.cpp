
//
// This is example code from Chapter 27.6.3 "Files" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void f(const char* fn)
{
    FILE* fi = fopen(fn, "r");    /* open fn for reading */ 
    FILE* fo = fopen(fn, "w");    /* open fn for writing */

    if (fi == 0) error("failed to open input file");
    if (fo == 0) error("failed to open output file");

    /* Read from file using stdio input functions, e.g. getc() */
    /* Write from file using stdio output functions, e.g. fprintf() */

    fclose(fo); 
    fclose(fi);

}

//------------------------------------------------------------------------------

int main()
try
{
    f("My_file");
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
