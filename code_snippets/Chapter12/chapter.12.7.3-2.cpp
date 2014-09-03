
//
// This is example code from Chapter 12.7.3 "Axis" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // if we want that "Next" button
#include "Graph.h" 
#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main ()
try
{ 
    Point tl(100,100);                   // top-left corner of our window

    Simple_window win(tl,600,400,"Canvas");
    // screen coordinate tl for top-left corner
    // window size(600*400)
    // title: Canvas

    Axis xa(Axis::x, Point(20,300), 280, 10, "x axis"); // make an Axis
    // an axis is a kind of Shape
    // Axis::x means horizontal
    // starting at (20,300)
    // 280 pixels long
    // 10 "notches"
    // label the axis "x axis"
    win.attach(xa);                      // attach xa to the window, win

    Axis ya(Axis::y, Point(20,300), 280, 10, "y axis");
    ya.set_color(Color::cyan);           // choose a color
    ya.label.set_color(Color::dark_red); // choose a color for the text
    win.attach(ya);
    win.set_label("Canvas #3");
    win.wait_for_button();               // Display!
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
