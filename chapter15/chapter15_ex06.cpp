// Chapter 15, exerise 06: Bar_chart class
// Exercise 07: add labeling to bar chart

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    const int xmax = 600;
    const int ymax = 600;

    const int x_orig = 100;
    const int y_orig = ymax/2;
    const Point orig(x_orig,y_orig);

    const int r_min = 0;
    const int r_max = 20;

    const int x_scale = 20;
    const int y_scale = 20;

    Point tl(600,50);
    Simple_window win(tl,xmax,ymax,"Bar_chart test");

    const int xlength = xmax - 200;
    const int ylength = ymax - 200;

    Axis x(Axis::x,Point(x_orig,y_orig),xlength,xlength/x_scale,"1 == 20 pixels");
    x.set_color(Color::red);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig,500),ylength,ylength/y_scale,"1 == 20 pixels");
    y.set_color(Color::red);
    win.attach(y);

    Bar_chart bc(orig,y_scale,20,10);
    for (int i = 0; i<10; ++i)
        bc.add_val(double(randint(100))/5 - 10);
    win.attach(bc);
    win.wait_for_button();

    bc.set_fill_color(Color::red);
    win.wait_for_button();

    for (int i = 0; i<10; ++i) {
        bc.set_label(i,to_string(bc.value(i)));
    }
    win.wait_for_button();

    bc.move(-15,-15);
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
