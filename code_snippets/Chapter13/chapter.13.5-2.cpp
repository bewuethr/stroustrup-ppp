
//
// This is example code from Chapter 13.5 "Line style" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;    // our graphics facilities are in Graph_lib

    Simple_window win3(Point(100,100),600,400,"grid");    

    int x_size = win3.x_max();    // get the size of our window
    int y_size = win3.y_max();
    int x_grid = 80;
    int y_grid = 40; 

    Lines grid;
    for (int x=x_grid; x<x_size; x+=x_grid)
        grid.add(Point(x,0),Point(x,y_size));    // vertical line
    for (int y = y_grid; y<y_size; y+=y_grid)
        grid.add(Point(0,y),Point(x_size,y));    // horizontal line

    grid.set_color(Color::red);
    grid.set_style(Line_style(Line_style::dash,2));
    win3.attach(grid);                           // attach the lines to the window
    win3.wait_for_button();                      // Display!
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
