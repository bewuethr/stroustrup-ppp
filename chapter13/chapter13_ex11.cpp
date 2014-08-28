// Chapter 13, exercise 11: Ellipse antics

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"Regular polygon");

    Graph_lib::Ellipse ell(Point(600,400),150,100);
    win.attach(ell);
    win.wait_for_button();

    Lines axes;
    axes.add(Point(ell.center().x-200,ell.center().y),
        Point(ell.center().x+200,ell.center().y));
    axes.add(Point(ell.center().x,ell.center().y-150),
        Point(ell.center().x,ell.center().y+150));
    win.attach(axes);
    win.wait_for_button();

    Mark f1(ell.focus1(),'x');
    win.attach(f1);
    Mark f2(ell.focus2(),'x');
    win.attach(f2);
    win.wait_for_button();

    Mark on_line(ne(ell),'x');
    win.attach(on_line);
    win.wait_for_button();

    Lines foci;
    foci.add(ell.focus1(),ne(ell));
    foci.add(ne(ell),ell.focus2());
    win.attach(foci);
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
