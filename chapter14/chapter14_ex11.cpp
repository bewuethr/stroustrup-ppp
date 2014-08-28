// Chapter 14, exercise 11: Binary_tree
// Exercise 12: make draw_lines of Binary_tree virtual, derive a class from
// Binary_tree and use a different node representation
// Exercise 13: add parameter to indicate what kind of line to use to connect
// the nodes (e.g., an arrow pointing down or a red arrow pointing up)
// Exercise 14: add operation to add label to nodes

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Binary_tree bt(Point(600,50),6,"");
    win.attach(bt);
    win.wait_for_button();

    bt.move(50,50);
    win.wait_for_button();
    bt.move(-50,-50);
    win.wait_for_button();

    win.detach(bt);

    Binary_tree_squares bts(Point(600,50),6,"");
    win.attach(bts);
    win.wait_for_button();

    win.detach(bts);

    Binary_tree bt2(Point(600,50),6,"ad");
    win.attach(bt2);
    win.wait_for_button();

    win.detach(bt2);

    Binary_tree bt3(Point(600,50),6,"au");
    win.attach(bt3);
    win.wait_for_button();

    bt3.set_node_label("l","Root");
    bt3.set_node_label("lr","lr");
    bt3.set_node_label("lrl","lrl");
    bt3.set_node_label("lrlr","lrlr");
    bt3.set_node_label("lrlrl","lrlrl");
    bt3.set_node_label("lrlrlr","lrlrlr");
    //bt3.set_node_label("","");
    //bt3.set_node_label("x","x");
    //bt3.set_node_label("lrlx","lrlx");
    //bt3.set_node_label("lrlrlrl","lrlrlrl");
    win.wait_for_button();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
