// Chapter 16, exercise 02: window with 4x4 buttons, doing something simple
// like change color or print coordinates

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    Point tl(100,100);
    Button_window bwin(tl,600,400,"Buttons do simple stuff");
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
