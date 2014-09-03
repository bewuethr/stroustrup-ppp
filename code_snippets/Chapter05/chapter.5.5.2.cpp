
//
// This is example code from Chapter 5.5.2 "The callee deals with errors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int area(int length, int width);    // calculate area of a rectangle

//------------------------------------------------------------------------------

int framed_area(int x, int y)        // calculate area within frame
{ 
    const int frame_width = 2;
    if (x-frame_width<=0 || y-frame_width<=0)
        error("non-positive argument for area() called by framed_area()");
    return area(x-frame_width,y-frame_width);
}

//------------------------------------------------------------------------------

int area(int length, int width)    // calculate area of a rectangle
{
    if (length<=0 || width <=0)
        error("non-positive argument for area()");
    return length*width;
}

//------------------------------------------------------------------------------

int main()
try
{
    int x = -1;
    int y = 2;
    int z = 4;
    // ...
    int area1 = area(x,y);
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3;    // convert to double to get
  // floating-point division
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
