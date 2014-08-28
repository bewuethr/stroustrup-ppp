// Chapter 15, exercise 04: graph a sine, a cosine, the sum of those and the
// sum of their squares

#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }
double sum_sin_cos(double x) { return sin(x) + cos(x); }
double sum_sin_cos_sq(double x) { return sin(x)*sin(x) + cos(x)*cos(x); }

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
    Simple_window win(tl,xmax,ymax,"sine and cosine");

    const int xlength = xmax - 200;
    const int ylength = ymax - 200;

    Axis x(Axis::x,Point(100,y_orig),xlength,xlength/x_scale,"1 == 20 pixels");
    x.set_color(Color::red);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig,500),ylength,ylength/y_scale,"1 == 20 pixels");
    y.set_color(Color::red);
    win.attach(y);
    win.wait_for_button();

    Function sine(sin,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(sine);
    Text sine_lbl(Point(70,290),"sin");
    win.attach(sine_lbl);
    win.wait_for_button();

    Function cosine(cos,r_min,r_max,orig,n_points,x_scale,y_scale);
    cosine.set_color(Color::blue);
    win.attach(cosine);
    Text cosine_lbl(Point(70,320),"cos");
    cosine_lbl.set_color(Color::blue);
    win.attach(cosine_lbl);
    win.wait_for_button();

    Function sumsc(sum_sin_cos,r_min,r_max,orig,n_points,x_scale,y_scale);
    sumsc.set_color(Color::green);
    win.attach(sumsc);
    Text sumsc_lbl(Point(35,305),"sin + cos");
    sumsc_lbl.set_color(Color::green);
    win.attach(sumsc_lbl);
    win.wait_for_button();

    Function sumscsq(sum_sin_cos_sq,r_min,r_max,orig,n_points,x_scale,y_scale);
    sumscsq.set_color(Color::yellow);
    win.attach(sumscsq);
    Text sumscsq_lbl(Point(20,270),"sin^2 + cos^2");
    sumscsq_lbl.set_color(Color::yellow);
    win.attach(sumscsq_lbl);
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
