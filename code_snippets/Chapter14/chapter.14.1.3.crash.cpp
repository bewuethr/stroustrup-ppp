
//
// This is example code from Chapter 14.1.3 "Naming" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

void f(Simple_window& w)
{
    Rectangle r(Point(100,200),50,30);
    w.attach(r);
}    // oops, the lifetime of r ends here

//------------------------------------------------------------------------------

int main()
try
{
    Simple_window win(Point(100,100),600,400,"My window");

    Open_polyline opl;
    opl.add(Point(100,100));
    opl.add(Point(150,200));
    opl.add(Point(250,250));

    win.attach(opl);
    // ...
    f(win);        // asking for trouble
    // ...
    win.wait_for_button();
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
