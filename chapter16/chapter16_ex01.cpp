// Chapter 16 exercise 01:
// My_window type

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    Point tl(100,100);
    My_window mw(tl,600,400,"My_window");
//    return gui_main();

    Circle c(Point(300,200),100);
    mw.attach(c);
    mw.wait_for_button();

    Graph_lib::Rectangle s(Point(50,50),100,200);
    mw.attach(s);
    mw.wait_for_button();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
