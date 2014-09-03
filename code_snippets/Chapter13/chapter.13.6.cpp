
//
// This is example code from Chapter 13.6 "Open polyline" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Simple_window win(Point(100,100),600,400,"Open polyline");    

    Open_polyline opl;

    opl.add(Point(100,100));
    opl.add(Point(150,200));
    opl.add(Point(250,250));
    opl.add(Point(300,200));

    win.attach(opl);
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
