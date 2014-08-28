// Chapter 15, exercise 05: "animate" Leibniz's series 1-1/3+1/5-1/7+1/9-1/11+...

#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }
double sum_sin_cos(double x) { return sin(x) + cos(x); }
double sum_sin_cos_sq(double x) { return sin(x)*sin(x) + cos(x)*cos(x); }

double leibniz(int n)
{
    double sum = 0;
    for (int i = 0; i<=n; ++i) {
        int fac = 1;
        if (i%2!=0) fac = -1;
        sum += 1/double(2*i+1) * fac;
    }
    return sum;
}

int main()
try {
    const int xmax = 1200;
    const int ymax = 600;

    const int x_orig = 100;
    const int y_orig = ymax - 100;
    const Point orig(x_orig,y_orig);

    const int r_min = 0;
    const int r_max = 20;

    const int x_scale = 20;
    const int y_scale = 200;

    Point tl(300,50);
    Simple_window win(tl,xmax,ymax,"");

    const int xlength = xmax - 200;
    const int ylength = ymax - 200;

    Axis x(Axis::x,Point(100,y_orig),xlength,xlength/x_scale,"1 == 20 pixels");
    x.set_color(Color::red);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig,500),ylength,ylength/y_scale,"1 == 200 pixels");
    y.set_color(Color::red);
    win.attach(y);

    Open_polyline opl;
    opl.add(Point(orig.x,orig.y-y_scale));
    win.attach(opl);

    for (int i = 1; i<=50; ++i) {
        ostringstream ss;
        ss << "Leibniz series, element " << i;
        win.set_label(ss.str());
        int x = opl.point(i-1).x + x_scale;
        int y = orig.y - leibniz(i) * y_scale;
        opl.add(Point(x,y));
        win.wait_for_button();
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
