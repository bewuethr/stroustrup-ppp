// Chapter 14, exercise 10: Pseudo_window to imitate real window

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");
    Vector_ref<Pseudo_window> vecpw;
    for (int i = 0; i<10; ++i) {
        vecpw.push_back(new Pseudo_window(Point(randint(1200),randint(800)),400,300,"Pseudo window"));
        win.attach(vecpw[vecpw.size()-1]);
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
