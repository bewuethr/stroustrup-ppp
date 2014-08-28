// Chapter 13, exercise 08: make a Regular_hexagon class
// Exercise 09: cover parts of a window with hexagons

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"Hexagon");

    vector<Point> centers;
    int s = 150;
    for (int i = 0; i<win.y_max()/(sqrt(3)/2.0*s); ++i) {
        for (int j = 0; j<win.x_max()/3.0/s; ++j) {
            int dx = 0;
            if (i%2==0) dx = 0;
            else dx = round(1.5*s);
            centers.push_back(Point(j*3*s+dx,i*sqrt(3)/2*s));
        }
    }

    Vector_ref<Regular_hexagon> vhex;
    for (int i = 0; i<centers.size(); ++i) {
        vhex.push_back(new Regular_hexagon(centers[i],s));
        vhex[vhex.size()-1].set_fill_color(Color::yellow);
        vhex[vhex.size()-1].set_style(Line_style(Line_style::solid,4));
        win.attach(vhex[vhex.size()-1]);
    }
    win.wait_for_button();

    for (int i =0; i<vhex.size(); ++i) {
        vhex[i].set_side(s-50);
        vhex[i].set_fill_color(Color::red);
    }
    win.wait_for_button();

    for (int i =0; i<vhex.size(); ++i) {
        vhex[i].set_side(s+50);
        vhex[i].set_fill_color(Color::green);
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
