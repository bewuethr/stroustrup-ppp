// Chapter 14, exercise 09: Group as container for shapes

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Group grp;
    Octagon oct(Point(600,400),150);
    win.attach(oct);
    grp.add_shape(oct);
    //win.attach(grp);
    win.wait_for_button();

    Hat_smiley hs(Point(150,150),100);
    win.attach(hs);
    grp.add_shape(hs);
    win.wait_for_button();

    grp.move(100,100);
    win.wait_for_button();

    grp.set_fill_color(Color::yellow);
    win.wait_for_button();

    grp.set_style(Line_style::dashdot);
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
