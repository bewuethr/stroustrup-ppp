
//
// This is example code from Chapter 5.9.1 "Post-conditions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Bad_area { };    // a type specifically for reporting errors from area()

// calculate area of a rectangle;
// throw a Bad_area exception in case of a bad argument
int area1(int length, int width)
{
    if (length<=0 || width <=0) throw Bad_area();
    return length*width;
}

//------------------------------------------------------------------------------

int area(int length, int width)
// calculate area of a rectangle;
// pre-conditions: length and width are positive
// post-condition: returns a positive value that is the area
{
    if (length<=0 || width <=0) error("area() pre-condition");
    int a =  length*width;
    if (a<=0) error("area() post-condition");
    return a;
}

//------------------------------------------------------------------------------

int main()
try
{
    area(2000000000, 2000000000);
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
