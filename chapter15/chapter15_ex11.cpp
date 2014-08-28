// Chapter 15, exercise 11: draw temperature data from three different places
// Uses pics_and_txt/chapter15_ex11_in.txt

#include "Simple_window.h"
#include "Graph.h"

struct Temp_max {
    int month;
    double cay, zur, crb;   // Grand Cayman, Zurich, Cranbrook
};

istream& operator>>(istream& is, Temp_max& tm)
// assume format ( month : cay zur crb )
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Temp_max ttmm;

    if (is >> ch1 >> ttmm.month
           >> ch2 >> ttmm.cay >> ttmm.zur >> ttmm.crb
           >> ch3) {
        if (ch1!='(' || ch2!=':' || ch3!=')') {
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else
        return is;
    tm = ttmm;
    return is;
}

class Scale {
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int b, int vb, double s) : cbase(b), vbase(vb), scale(s) { }
    int operator()(int v) const { return cbase + (v-vbase)*scale; }
};


int main()
try {
    const int base_month = 1;
    const int end_month = 12;

    const int xmax = 900;
    const int ymax = 400;

    const int xoffset = 100;
    const int yoffset = 60;

    const int xspace = 40;
    const int yspace = 40;

    const int xlength = xmax - xoffset - xspace;
    const int ylength = ymax - yoffset - yspace;

    const double xscale = double(xlength)/(end_month-base_month);
    const double yscale = double(ylength)/40;

    Scale xs(xoffset,base_month,xscale);
    Scale ys(ymax-yoffset,-10,-yscale);

    Simple_window win(Point(100,100),xmax,ymax,"Temperatures in Cayman, Zurich and Cranbrook");

    Axis x(Axis::x,Point(xoffset,ymax-yoffset),xlength,12,
           "month          1             2             3             4             5             6             "
           "7             8             9            10            11            12");
    x.label.move(-200,0);

    Axis y(Axis::y,Point(xoffset,ymax-yoffset),ylength,8,"Average maximum temperature [°C]");

    Line zero_line(Point(xs(1),ys(0)),Point(xs(12),ys(0)));
    zero_line.set_style(Line_style::dash);

    Open_polyline cayman;
    Open_polyline zurich;
    Open_polyline cranbrook;

    string file_name = "pics_and_txt/chapter15_ex11_in.txt";
    ifstream ifs(file_name.c_str());
    if (!ifs) error("can't open ",file_name);

    Temp_max tm;
    while (ifs>>tm) {
        if (tm.month<base_month || tm.month>end_month)
            error("month out of range");
        int x = xs(tm.month);
        cayman.add(Point(x,ys(tm.cay)));
        zurich.add(Point(x,ys(tm.zur)));
        cranbrook.add(Point(x,ys(tm.crb)));
    }

    Text cayman_label(Point(20,cayman.point(0).y),"Cayman");
    cayman.set_color(Color::red);
    cayman_label.set_color(Color::red);

    Text zurich_label(Point(20,zurich.point(0).y),"Zurich");
    zurich.set_color(Color::blue);
    zurich_label.set_color(Color::blue);

    Text cranbrook_label(Point(20,cranbrook.point(0).y),"Cranbrook");
    cranbrook.set_color(Color::dark_green);
    cranbrook_label.set_color(Color::dark_green);

    win.attach(cayman);
    win.attach(zurich);
    win.attach(cranbrook);

    win.attach(cayman_label);
    win.attach(zurich_label);
    win.attach(cranbrook_label);

    win.attach(x);
    win.attach(y);
    win.attach(zero_line);

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
