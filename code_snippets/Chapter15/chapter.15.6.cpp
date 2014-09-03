
//
// This is example code from Chapter 15.6.1 "Reading a file" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Distribution {
    int year, young, middle, old;
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Distribution& d)
// assume format: ( year : young middle old )
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if (is >> ch1 >> dd.year
        >> ch2 >> dd.young >> dd.middle >> dd.old
        >> ch3) {
            if (ch1!= '(' || ch2!=':' || ch3!=')') {
                is.clear(ios_base::failbit);
                return is;
            }
    }
    else
        return is;
    d = dd;
    return is;
}

//------------------------------------------------------------------------------

class Scale {                // data value to coordinate conversion
    int cbase;               // coordinate base
    int vbase;               // base of values
    double scale;
public:
    Scale(int b, int vb, double s) :cbase(b), vbase(vb), scale(s) { }
    int operator()(int v) const { return cbase + (v-vbase)*scale; }
};

//------------------------------------------------------------------------------

int main()
try
{
    const int xmax = 600;    // window size
    const int ymax = 400;

    const int xoffset = 100; // distance from left hand side of window to y axis
    const int yoffset = 60;  // distance from bottom of window to x axis

    const int xspace = 40;   // space beyond axis
    const int yspace = 40; 

    const int xlength = xmax-xoffset-xspace;    // length of axes
    const int ylength = ymax-yoffset-yspace;

    const int base_year = 1960;
    const int end_year  = 2040;

    const double xscale
        = double(xlength)/(end_year-base_year); // scale of x values
    const double yscale = double(ylength)/100;  // scale of y values 

    Scale xs(xoffset,base_year,xscale);
    Scale ys(ymax-yoffset,0,-yscale);

    string file_name = "japanese-age-data.txt";
    ifstream ifs(file_name.c_str());
    if (!ifs) error("can't open ",file_name);

    Open_polyline children;
    Open_polyline adults;
    Open_polyline aged;

    Distribution d;
    while (ifs>>d) {
        if (d.year<base_year || end_year<d.year) error("year out of range");
        if (d.young+d.middle+d.old != 100) error("percentages don't add up");
        int x = xs(d.year);
        children.add(Point(x,ys(d.young)));
        adults.add(Point(x,ys(d.middle)));
        aged.add(Point(x,ys(d.old)));
    }

    Simple_window win(Point(100,100),xmax,ymax,"Aging Japan");

    Axis x(Axis::x, Point(xoffset,ymax-yoffset), xlength,
        (end_year-base_year)/10, 
        "year   1960      1970      1980      1990      "
        "2000      2010      2020      2030      2040");
    x.label.move(-100,0);

    Axis y(Axis::y, Point(xoffset,ymax-yoffset), ylength, 10,"% of population");

    Line current_year(Point(xs(2004),ys(0)),Point(xs(2004),ys(100)));
    current_year.set_style(Line_style::dash);

    Text children_label(Point(20,children.point(0).y),"age 0-14");
    children.set_color(Color::red);
    children_label.set_color(Color::red);

    Text adults_label(Point(20,adults.point(0).y),"age 15-64");
    adults.set_color(Color::blue);
    adults_label.set_color(Color::blue);

    Text aged_label(Point(20,aged.point(0).y),"age 65+");
    aged.set_color(Color::dark_green);
    aged_label.set_color(Color::dark_green);

    win.attach(children);
    win.attach(adults);
    win.attach(aged);

    win.attach(children_label);
    win.attach(adults_label);
    win.attach(aged_label);

    win.attach(x);
    win.attach(y); 
    win.attach(current_year);

    win.wait_for_button();
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
