// Chapter 13, exercise 12: move a marker around on a circle

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"Moving marker");

    const double pi = 3.1415926;

    Point cen(600,400);
    int rad = 200;
    double dphi = pi/6;

    Circle c(cen,rad);
    win.attach(c);
    Mark x(Point(cen.x+rad,cen.y),'o');
    win.attach(x);
    win.wait_for_button();
    win.set_label("Moving marker");

    double phi = 0;

    while (phi < 2*pi) {
        phi += dphi;
        int dx = round(rad*cos(phi)-rad*cos(phi-dphi));
        int dy = round(rad*sin(phi)-rad*sin(phi-dphi));
        x.move(dx,dy);
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
