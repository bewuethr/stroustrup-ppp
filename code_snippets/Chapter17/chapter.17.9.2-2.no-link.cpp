
//
// This is example code from Chapter 17.9.2 "Pointers, references, and inheritance" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"
#include "../GUI/Graph.h" // get access to our graphics library facilities

using namespace Graph_lib;

//------------------------------------------------------------------------------

void rotate(Shape& s, int n);  // rotate s n degrees

//------------------------------------------------------------------------------

int main()
{
    Circle c(Point(200,200),50);
    Shape& r = c;
    rotate(c,75);
}

//------------------------------------------------------------------------------
