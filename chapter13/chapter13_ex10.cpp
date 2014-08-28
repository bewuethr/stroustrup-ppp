// Chapter 13, exercise 10: make a Regular_polygon class

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"Regular polygon");

    Vector_ref<Regular_polygon> vpoly;

    for (int i = 0; i<30; i+=2) {
        vpoly.push_back(new Regular_polygon(Point(200+20*i,200+20*i),i+3,250-5*i));
        vpoly[vpoly.size()-1].set_style(Line_style(Line_style::solid,4));
        vpoly[vpoly.size()-1].set_fill_color(i*30%255);
        win.attach(vpoly[vpoly.size()-1]);
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
