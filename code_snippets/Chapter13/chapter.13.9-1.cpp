
//
// This is example code from Chapter 13.9 "Rectangle" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Simple_window win(Point(100,100),600,400,"Rectangle");

    Rectangle rect00(Point(150,100),200,100); 
    Rectangle rect11(Point(50,50),Point(250,150)); 
    Rectangle rect12(Point(50,150),Point(250,250)); // just  below rect11
    Rectangle rect21(Point(250,50),200,100);        // just to the right of rect11
    Rectangle rect22(Point(250,150),200,100);       // just below rect21

    rect00.set_fill_color(Color::yellow);
    rect11.set_fill_color(Color::blue);
    rect12.set_fill_color(Color::red);
    rect21.set_fill_color(Color::green);

    win.attach(rect00);
    win.attach(rect11);
    win.attach(rect12);
    win.attach(rect21);

    win.set_label("rectangles");
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
