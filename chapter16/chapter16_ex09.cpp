// Chapter 16 exercise 09: modify calculator to read from In_box and write to
// Out_box

#include "../lib_files/Simple_window.h"
//#include "Graph.h"

int main()
try {
    Point tl(580,400);
    Calc_window cwin(tl,415,125,"Calculator");
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
