// Chapter 14, exercise 08: Octagon class

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Octagon oct(Point(600,400),150);
    win.attach(oct);
    win.wait_for_button();

    // move
    oct.move(50,50);
    win.wait_for_button();
    oct.move(-50,-50);
    win.wait_for_button();

    // set_color
    oct.set_color(Color::blue);
    win.wait_for_button();

    // color
    Graph_lib::Rectangle r1(Point(150,150),Point(250,250));
    r1.set_color(oct.color());
    win.attach(r1);
    win.wait_for_button();

    // set_style
    oct.set_style(Line_style(Line_style::dashdot,3));
    win.wait_for_button();

    // style
    r1.set_style(oct.style());
    win.wait_for_button();

    // set_fill_color
    oct.set_fill_color(Color::red);
    win.wait_for_button();

    // fill_color
    r1.set_fill_color(oct.fill_color());
    win.wait_for_button();

    // point, number_of_points
    Line l1(oct.point(0),oct.point(oct.number_of_points()-1));
    win.attach(l1);
    win.wait_for_button();

    // center
    Circle c1(oct.center(),50);
    win.attach(c1);
    win.wait_for_button();

    // radius, set_radius
    c1.set_radius(oct.radius());
    win.wait_for_button();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
