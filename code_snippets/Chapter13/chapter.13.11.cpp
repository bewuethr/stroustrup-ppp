
//
// This is example code from Chapter 13.11 "Text" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Simple_window win(Point(100,100),600,400,"Closed polyline");    

    Closed_polyline cpl;

    cpl.add(Point(100,100));
    cpl.add(Point(150,200));
    cpl.add(Point(250,250));
    cpl.add(Point(300,200));
    cpl.add(Point(100,250));
    win.attach(cpl);

    Text t(Point(200,200),"A closed polyline that isn't a polygon");    
    t.set_color(Color::blue);
    win.attach(t);

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
