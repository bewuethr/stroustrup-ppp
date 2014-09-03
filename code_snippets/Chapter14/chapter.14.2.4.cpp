
//
// This is example code from Chapter 14.2.4 "Copying and mutability" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

void my_fct(const Open_polyline& op, const Circle& c)
{
    //Open_polyline op2 = op; // error: Shape's copy constructor is private
    vector<Shape> v;
    //v.push_back(c);         // error: Shape's copy constructor is private
    // ...
    //op = op2;               // error: Shape's assignment is private
}

//------------------------------------------------------------------------------

int main()
try
{
    Point p;
    Marked_polyline mp("x");
    Circle c(p,10);
    my_fct(mp,c);             // the Open_polyline argument refers to a Marked_polyline
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
