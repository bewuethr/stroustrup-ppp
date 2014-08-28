// Chapter 14, exercise 05: Class Striped_rectangle that "fills" Rectangle with
// stripes
// Exercise 06: Class Striped_circle that "fills" Circle with stripes

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Striped_rectangle sr(Point(300,300),Point(500,400));
    win.attach(sr);
    win.wait_for_button();

    sr.set_fill_color(Color::red);
    win.wait_for_button();

    Striped_circle sc(Point(450,451),150);
    win.attach(sc);
    win.wait_for_button();

    sc.set_fill_color(Color::green);
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
