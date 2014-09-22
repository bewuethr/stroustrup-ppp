// Chapter 19, exercise 14: provide GUI interface and graphical output for
// "Hunt the Wumpus": take input in an input box, display a map of the part of
// the cave currently known to the player in a window

// Exercise 15: allow user to mark rooms based on knowledge and guesses, such as
// "maybe bats" or "bottomless pit"

#include "chapter19_ex14_Simple_window.h"

using namespace Graph_lib;

int main()
try {
    Wumpus_window wwin;
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
