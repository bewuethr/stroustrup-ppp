// Chapter 13, exercise 16: tile window with hexagons
// Exercise 17: fill them with different
// colors

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Vector_ref<Regular_polygon> vpol;
    int s = 50;
    int dx = 0;
    for (int j = 0; j<=win.y_max(); j+=round(sqrt(3)/2*s)) {
        if (dx==0) dx = 1.5*s;
        else dx = 0;
        for (int i = 0; i<=win.x_max(); i+=3*s) {
            vpol.push_back(new Regular_polygon(Point(i+dx,j),6,s));
            vpol[vpol.size()-1].set_style(Line_style(Line_style::solid,2));
            vpol[vpol.size()-1].set_fill_color((i*win.y_max()+j)%256);
            win.attach(vpol[vpol.size()-1]);
        }
    }


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
