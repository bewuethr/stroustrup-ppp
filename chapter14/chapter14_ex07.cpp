// Chapter 14, exercise 07: Class Striped_closed_polyline

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    // how is a Closed_polyline filled?
    Closed_polyline cp;
    cp.add(Point(150,150));
    cp.add(Point(500,150));
    cp.add(Point(500,500));
    cp.add(Point(150,500));
    cp.set_fill_color(Color::red);
    win.attach(cp);
    win.wait_for_button();
    cp.add(Point(550,375));
    win.wait_for_button();
    cp.add(Point(375,550));
    cp.add(Point(375,100));
    cp.add(Point(300,550));
    win.wait_for_button();

    // same for Striped_closed_polyline
    Striped_closed_polyline scp;
    scp.add(Point(750,150));
    scp.add(Point(1100,150));
    scp.add(Point(1100,500));
    scp.add(Point(750,500));
    scp.set_fill_color(Color::red);
    win.attach(scp);
    win.wait_for_button();
    scp.add(Point(1150,375));
    win.wait_for_button();
    scp.add(Point(975,550));
    scp.add(Point(975,100));
    scp.add(Point(900,550));
    win.wait_for_button();
    scp.add(Point(1150,350));
    win.wait_for_button();

    // extreme shape
    Striped_closed_polyline scp_extr;
    for (int i = 0; i<100; ++i) {
        scp_extr.add(Point(600+randint(-300,300),400+randint(-300,300)));
    }
    scp_extr.set_fill_color(Color::blue);
    win.attach(scp_extr);
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
