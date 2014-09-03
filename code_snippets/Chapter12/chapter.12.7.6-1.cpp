
//
// This is example code from Chapter 12.7.6 "Rectangles" of
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
    Point tl(100,100);    // top-left corner of our window

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

    Function sine(sin,0,100,Point(20,150),1000,50,50);    // sine curve
    // plot sin() in the range [0:100) with (0,0) at (20,150)
    // using 1000 points; scale x values *50, scale y values *50
    win.attach(sine);
    sine.set_color(Color::blue);         // we changed our mind about sine's color

    Polygon poly;                        // a polygon, a Polygon is a kind of Shape
    poly.add(Point(300,200));            // three points makes a triangle
    poly.add(Point(350,100));
    poly.add(Point(400,200));

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);

    Rectangle r(Point(200,200), 100, 50);// top-left corner, width, height
    win.attach(r); 

    Closed_polyline poly_rect;
    poly_rect.add(Point(100,50)); 
    poly_rect.add(Point(200,50));
    poly_rect.add(Point(200,100));
    poly_rect.add(Point(100,100));
    win.attach(poly_rect);

    win.set_label("Canvas #6.1");
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
