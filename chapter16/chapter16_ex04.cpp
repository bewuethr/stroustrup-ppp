// Chapter 16, exercise 04:
// Menu with different shapes, inboxes for coordinates, draw upon click

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    Point tl(100,100);
    Shmenu_window shmwin(tl,800,600,"Enter coordinates, choose shape");
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
