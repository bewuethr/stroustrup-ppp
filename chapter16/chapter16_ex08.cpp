// Chapter 16, exercise 08:
// Currency converter: read conversion rates from file at startup;
// enter an amount in an input window, provide a way to select currencies
// to convert from and to, e.g., two menus

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    Point tl(580,400);
    Currency_window cwin(tl,415,125,"Currency Converter");
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
