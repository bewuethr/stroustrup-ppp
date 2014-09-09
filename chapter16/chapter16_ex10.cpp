// Chapter 16, exercise 10: function grapher: user can choose among a set of
// functions (e.g., sin() and log(), provide parameters for those functions and
// then graph them

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    Point tl(400,150);
    Fgraph_window fwin(tl,800,605,"Function Grapher");
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
