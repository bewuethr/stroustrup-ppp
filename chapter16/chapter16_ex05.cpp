// Chapter 16, exercise 05:
// Menu with different shapes, inboxes for coordinates, draw upon click
// In addition, option to move shape to new coordinates

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    Point tl(100,100);
    Mvshape_window mswin(tl,800,600,"Enter coordinates, choose shape, next to move");
    return gui_main();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
