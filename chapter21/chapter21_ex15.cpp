// Chapter 21, exercise 15: provide a GUI for the text file query tool from
// exercise 14

#include "chapter21_ex11_Simple_window.h"

//------------------------------------------------------------------------------

int main()
try {    
    Graph_lib::Text_query_window tqwin;
    return Graph_lib::gui_main();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}