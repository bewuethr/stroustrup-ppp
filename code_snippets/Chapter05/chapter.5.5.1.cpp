
//
// This is example code from Chapter 5.5.1 "The caller deals with errors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int area(int length, int width)    // calculate area of a rectangle
{
    return length*width;
}

//------------------------------------------------------------------------------

const int frame_width = 2;
int framed_area(int x, int y)        // calculate area within frame
{
    return area(x-frame_width,y-frame_width);
}

//------------------------------------------------------------------------------

int main()
try
{
    int x = -1;
    int y = 2;
    int z = 4;
    // ...

    {
        if (x<=0) error("non-positive x");
        if (y<=0) error("non-positive y");
        int area1 = area(x,y);
    }

    {
        // If we didn't need separate error messages about each argument, we would simplify:
        if (x<=0 || y<=0) error("non-positive argument for area()");   // ||  means "or"
        int area1 = area(x,y); 

        if (z<=2) 
            error("non-positive 2nd argument for area() called by framed_area()");

        int area2 = framed_area(1,z); 
        if (y<=2 || z<=2)
            error("non-positive argument for area() called by framed_area()");
        int area3 = framed_area(y,z);
        double ratio = double(area1)/area3;    // convert to double to get
        // floating-point division
    }

    {
        if (1-frame_width<=0 || z-frame_width<=0)
            error("non-positive 2nd argument for area() called by framed_area()");
        int area2 = framed_area(1,z); 
        if (y-frame_width<=0 || z-frame_width<=0)
            error("non-positive argument for area() called by framed_area()");
        int area3 = framed_area(y,z);
    }
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
