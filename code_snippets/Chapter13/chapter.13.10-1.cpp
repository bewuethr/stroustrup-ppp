
//
// This is example code from Chapter 13.10 "Managing unnamed objects" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    Vector_ref<Rectangle> rect;

    Rectangle x(Point(100,200),Point(200,300));
    rect.push_back(x);    // add named 

    rect.push_back(new Rectangle(Point(50,60),Point(80,90))); // add unnamed

    for (int i=0; i<rect.size(); ++i) rect[i].move(10,10);    // use rect
}
catch(exception& e) {
    // some error reporting
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}

//------------------------------------------------------------------------------
