
//
// This is example code from Chapter 5.9 "Pre-and post-conditions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int my_complicated_function(int a, int b, int c)
// the arguments are positive and a < b < c
{
    if (!(0<a && a<b && b<c))    // ! means 'not' and && means 'and'
        error("bad arguments for mcf");
    // ...
}

//------------------------------------------------------------------------------

int main()
try
{
    //int x = my_complicated_function(1, 2, "horsefeathers");
    int y = my_complicated_function(1, 2, 3);
    int z = my_complicated_function(3, 2, 1);
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
