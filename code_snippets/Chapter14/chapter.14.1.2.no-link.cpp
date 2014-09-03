
//
// This is example code from Chapter 14.1.2 "Operations" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

void draw_line(Point p1, Point p2);              // from p1 to p2 (our style)
void draw_line(int x1, int y1, int x2, int y2);  // from (x1,y1) to (x2,y2)
void draw_rectangle(Point p, int w, int h);
void draw_rectangle(int x, int y, int w, int h);

//------------------------------------------------------------------------------

int main()
try
{
    Line ln(Point(100,200),Point(300,400));
    Mark m(Point(100,200),'x');                  // display a single point as an 'x'
    Circle c(Point(200,200),250);

    draw_rectangle(Point(100,200), 300, 400);    // our style
    draw_rectangle (100,200,300,400);            // alternative
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
