
//
// This is example code from Chapter 13.13 "Ellipse" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Simple_window win(Point(100,100),600,400,"Ellipses");

    Ellipse e1(Point(200,200),50,50);
    Ellipse e2(Point(200,200),100,50);
    Ellipse e3(Point(200,200),100,150);

    win.attach(e1);
    win.attach(e2);
    win.attach(e3);

    win.wait_for_button();       // Display!
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
