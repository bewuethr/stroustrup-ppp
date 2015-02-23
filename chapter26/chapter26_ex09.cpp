// Chapter 26, exercise 9: add text-based output to the graphics interface
// library. For example, when a call to Circle(Point(0,1),15) is executed, a
// string like "Circle(Point(0,1),15)" should be produced in an output stream.
//
// Adding output only for Line, Rectangle and Circle
//
// Alternative to adding output to every draw_lines() function: define output
// operator for each shape, then add printing to draw() loop in Window.cpp

#include "Simple_window.h"

using namespace Graph_lib;

//-----------------------------------------------------------------------------

int main()
try {
    Simple_window win(Point(400,100),800,700,"My window");
    Vector_ref<Shape> vec;
    vec.push_back(new Graph_lib::Rectangle(Point(100,300),500,400));
    vec.push_back(new Line(Point(100,300),Point(350,100)));
    vec.push_back(new Line(Point(350,100),Point(600,300)));
    vec.push_back(new Graph_lib::Rectangle(Point(300,500),100,200));
    vec.push_back(new Circle(Point(200,550),50));
    vec.push_back(new Circle(Point(500,550),50));
    vec.push_back(new Line(Point(150,550),Point(250,550)));
    vec.push_back(new Line(Point(200,500),Point(200,600)));
    vec.push_back(new Line(Point(450,550),Point(550,550)));
    vec.push_back(new Line(Point(500,500),Point(500,600)));
    for (int i = 0; i<vec.size(); ++i)
        win.attach(vec[i]);
    win.wait_for_button();
}
catch (exception& e) {
    cerr << e.what() << endl;
}
catch (...) {
    cerr << "exception \n";
}

//------------------------------------------------------------------------------
