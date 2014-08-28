// Chapter 13, exercise 17: Poly class, which checks if polygon already in
// constructor

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    // this one should work
    vector<Point> points;
    points.push_back(Point(100,100));
    points.push_back(Point(150,100));
    points.push_back(Point(150,150));
    points.push_back(Point(125,150));
    points.push_back(Point(100,125));
    Poly p(points);
    win.attach(p);
    win.wait_for_button();
    p.set_fill_color(Color::red);
    win.wait_for_button();

    // this one should complain
    vector<Point> points2;
    points2.push_back(Point(300,300));
    points2.push_back(Point(350,300));
    points2.push_back(Point(350,350));
    points2.push_back(Point(325,275));
    Poly p2(points2);   // complain!
    win.attach(p2);
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
