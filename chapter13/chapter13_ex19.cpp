// Chapter 13, exercise 19: define Star class, draw different stars

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Vector_ref<Star> stars;
    int min = 10;
    int max = 150;

    for (int i = 0; i<50; ++i) {
        stars.push_back(new Star(Point(randint(0,win.x_max()),
            randint(0,win.y_max())),
            randint(4,25),
            randint(min,max)));
        stars[stars.size()-1].set_fill_color(randint(255));
        stars[stars.size()-1].set_color(randint(255));
        win.attach(stars[stars.size()-1]);
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
