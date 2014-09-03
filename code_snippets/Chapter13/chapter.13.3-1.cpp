
//
// This is example code from Chapter 13.3 "Lines" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;    // our graphics facilities are in Graph_lib

    Simple_window win1(Point(100,100),600,400,"lines: +");    

    Lines x;
    x.add(Point(100,100), Point(200,100));   // first line: horizontal
    x.add(Point(150,50), Point(150,150));    // second line: vertical

    win1.attach(x);                          // attach the lines to the window
    win1.wait_for_button();                  // Display!
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
