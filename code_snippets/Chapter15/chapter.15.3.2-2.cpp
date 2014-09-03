
//
// This is example code from Chapter 15.3.2 "More examples" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <cmath>
#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

using namespace std;

//------------------------------------------------------------------------------

double one(double) { return 1; }

double slope(double x) { return x/2; }

double square(double x) { return x*x; }

double sloping_cos(double x) { return cos(x)+slope(x); }

//------------------------------------------------------------------------------

int main()
try
{
    const int xmax = 600;      // window size
    const int ymax = 400;

    const int x_orig = xmax/2; // position of (0,0) is center of window
    const int y_orig = ymax/2; 
    const Point orig(x_orig,y_orig);

    const int r_min = -10;     // range [-10:11) 
    const int r_max = 11;

    const int n_points = 400;  // number of points used in range

    const int x_scale = 30;    // scaling factors
    const int y_scale = 30;

    Simple_window win0(Point(100,100),xmax,ymax,"Function graphing");

    Function f1(log,0.000001,r_max,orig,200,30,30); // log() logarithm, base e
    Function f2(sin,   r_min,r_max,orig,200,30,30); // sin()
    f2.set_color(Color::blue);
    Function f3(cos,   r_min,r_max,orig,200,30,30); // cos()
    Function f4(exp,   r_min,r_max,orig,200,30,30); // exp() exponential e^x
    f4.set_color(Color::green);

    win0.attach(f1);
    win0.attach(f2);
    win0.attach(f3);
    win0.attach(f4);

    win0.set_label("log, exp, sin and cos");

    const int xlength = xmax-40;   // make the axis a bit smaller than the window
    const int ylength = ymax-40;

    Axis x(Axis::x,Point(20,y_orig), xlength, xlength/x_scale, "one notch == 1");
    Axis y(Axis::y,Point(x_orig, ylength+20), ylength, ylength/y_scale, "one notch == 1");
    win0.attach(x);
    win0.attach(y);
    x.set_color(Color::red);
    y.set_color(Color::red);

    x.label.move(-160,0);
    x.notches.set_color(Color::dark_red);

    win0.wait_for_button();
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
