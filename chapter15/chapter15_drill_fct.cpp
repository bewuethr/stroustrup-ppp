#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
try {
    const int xmax = 600;
    const int ymax = 600;

    const int x_orig = xmax/2;
    const int y_orig = ymax/2;
    const Point orig(x_orig,y_orig);

    const int r_min = -10;
    const int r_max = 11;

    const int n_points = 400;

    const int x_scale = 20;
    const int y_scale = 20;

    Point tl(600,50);
    Simple_window win(tl,xmax,ymax,"Function graphs");

    const int xlength = xmax - 200;
    const int ylength = ymax - 200;

    Axis x(Axis::x,Point(100,y_orig),xlength,xlength/x_scale,"1 == 20 pixels");
    x.set_color(Color::red);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig,500),ylength,ylength/y_scale,"1 == 20 pixels");
    y.set_color(Color::red);
    win.attach(y);
    win.wait_for_button();

    Function s(one,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(s);
    win.wait_for_button();

    Function s2(slope,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(s2);
    win.wait_for_button();

    Text ts2(Point(100,y_orig+4*y_scale),"x/2");
    win.attach(ts2);
    win.wait_for_button();

    Function s3(square,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(s3);
    win.wait_for_button();

    Function s4(cos,r_min,r_max,orig,n_points,x_scale,y_scale);
    s4.set_color(Color::blue);
    win.attach(s4);
    win.wait_for_button();

    Function s5(sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(s5);
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