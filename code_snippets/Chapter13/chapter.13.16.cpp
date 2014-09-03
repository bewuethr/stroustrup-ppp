
//
// This is example code from Chapter 13.16 "Mark" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Simple_window win(Point(100,100),600,400,"Circles with centers");

    Circle c1(Point(100,200),50);
    Circle c2(Point(150,200),100);
    Circle c3(Point(200,200),150);

    win.attach(c1);
    win.attach(c2);
    win.attach(c3);

    Mark m1(Point(100,200),'x');
    Mark m2(Point(150,200),'y');
    Mark m3(Point(200,200),'z');
    c1.set_color(Color::blue);
    c2.set_color(Color::red);
    c3.set_color(Color::green);
    win.attach(m1);
    win.attach(m2);
    win.attach(m3);

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
