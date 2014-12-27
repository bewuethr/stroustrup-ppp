// Chapter 21, exercise 11: provide a GUI interface for entering Orders into
// files

#include "chapter21_ex11_Simple_window.h"

using namespace Graph_lib;

int main()
try {
    Order_enter_window oewin;
    return gui_main();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}