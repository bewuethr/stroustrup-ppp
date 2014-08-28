// Chapter 13, exercise 13: draw the color chart from 13.10, but without
// borders

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Vector_ref<Graph_lib::Rectangle> rects;
    const int rect_size = 40;

    for (int i = 0; i<16; ++i) {
        for (int j = 0; j<16; ++j) {
            rects.push_back(new Graph_lib::Rectangle(Point(i*rect_size,j*rect_size),rect_size,rect_size));
            rects[rects.size()-1].set_fill_color(16*i+j);
            rects[rects.size()-1].set_color(Color(Color::black,Color::invisible));
            win.attach(rects[rects.size()-1]);
        }
    }
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
