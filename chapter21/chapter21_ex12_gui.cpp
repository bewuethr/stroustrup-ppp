// Chapter 21, exercise 12: provide a GUI for querying a file of Orders, e.g.:
// "Find all orders from Joe", "Find the total value of orders in file Hardware"
// and "List all orders in file Clothing". Design non-GUI interface first.

#include "chapter21_ex11_Simple_window.h"

//------------------------------------------------------------------------------

int main()
try {    
    Graph_lib::File_query_window fqwin;
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