
//
// This is example code from Chapter 15.5 "Approximation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <cmath>
#include <sstream>
#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

using namespace std;

//------------------------------------------------------------------------------

int fac(int n)    // factorial(n); n!
{
    int r = 1;
    while (n>1) {
        r*=n;
        --n;
    }
    return r;
}

//------------------------------------------------------------------------------

double term(double x, int n) { return pow(x,n)/fac(n); }    // nth term of series

//------------------------------------------------------------------------------

double expe(double x, int n)        // sum of n terms for x
{
    double sum = 0;
    for (int i=0; i<n; ++i) sum+=term(x,i);
    return sum;
}

//------------------------------------------------------------------------------

int expN_number_of_terms = 10;

double expN(double x)
{
    return expe(x,expN_number_of_terms);
}

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

    Simple_window win(Point(100,100),xmax,ymax,"exp approximation");

    const int xlength = xmax-40;   // make the axis a bit smaller than the window
    const int ylength = ymax-40;

    Axis x(Axis::x,Point(20,y_orig), xlength, xlength/x_scale, "one notch == 1");
    Axis y(Axis::y,Point(x_orig, ylength+20), ylength, ylength/y_scale, "one notch == 1");
    win.attach(x);
    win.attach(y);
    x.set_color(Color::red);
    y.set_color(Color::red);

    Function real_exp(exp,r_min,r_max,orig,200,x_scale,y_scale);
    real_exp.set_color(Color::blue);
    win.attach(real_exp);

    for (int n = 0; n<50; ++n) {
        ostringstream ss;
        ss << "exp approximation; n==" << n ;
        win.set_label(ss.str());
        expN_number_of_terms = n;
        // get next approximation
        Function e(expN,r_min,r_max,orig,200,x_scale,y_scale);
        win.attach(e);
        if (!win.wait_for_button())
            break; // User asked to quit
        win.detach(e);
    }

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
