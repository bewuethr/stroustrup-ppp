// Chapter 16, exercise 06:
// Analog clock - doesn't really work. Fl::add_timeout and Fl::repeat_timeout die
// when using a clock as a global variable, and when it's not global, it's not
// accessible in the callback function :(

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    Point tl(100,100);
    Graph_lib::Window qwin(tl,800,600,"Analog clock");
    Clock my_clock(Point(400,300),150);
    qwin.attach(my_clock);
    qwin.redraw();
    for (int i = 0; i<3; ++i) {
        Sleep(1000);
        my_clock.increase_time();
        my_clock.update_hands();
        qwin.redraw();
    }
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
