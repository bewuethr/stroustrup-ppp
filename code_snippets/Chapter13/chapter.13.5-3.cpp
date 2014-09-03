
//
// This is example code from Chapter 13.5 "Line style" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;    // our graphics facilities are in Graph_lib

    Simple_window win1(Point(100,100),600,400,"two lines");    

    Line horizontal(Point(100,100),Point(200,100)); // make a horizontal line
    Line vertical(Point(150,50),Point(150,150));    // make a vertical line

    horizontal.set_color(Color::red);
    vertical.set_color(Color::green);

    win1.attach(horizontal);      // attach the lines to the window
    win1.attach(vertical);

    win1.wait_for_button();       // Display!
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
