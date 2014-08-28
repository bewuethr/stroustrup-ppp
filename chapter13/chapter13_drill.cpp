// Chapter 13, drill

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {

    Point tl(300,50);
    Simple_window win(tl,1000,800,"My window");
    win.wait_for_button();
    win.set_label("My window");

    // add grid on leftmost 800-by-800 part
    Lines grid;
    int x_size = 800;
    int y_size = 800;
    for (int i = 100; i<=x_size; i+=100) {
        grid.add(Point(i,0),Point(i,y_size));
        grid.add(Point(0,i),Point(x_size,i));
    }
    win.attach(grid);
    //win.resize(1000,800);
    win.wait_for_button();

    // make squares on the diagonal red
    Vector_ref<Graph_lib::Rectangle> vr;
    for (int i = 0; i<8; ++i) {
        vr.push_back(new Graph_lib::Rectangle(Point(i*100,i*100),101,101));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }
    //win.resize(1000,800);
    win.wait_for_button();

    // place 3 copies of a 200-by-200 image, don't cover the red squares
    Image plane1(Point(200,0),"pics_and_txt/image.jpg");
    plane1.set_mask(Point(200,0),200,200);
    win.attach(plane1);
    Image plane2(Point(500,200),"pics_and_txt/image.jpg");
    plane2.set_mask(Point(200,0),200,200);
    win.attach(plane2);
    Image plane3(Point(100,500),"pics_and_txt/image.jpg");
    plane3.set_mask(Point(200,0),200,200);
    win.attach(plane3);
    //win.resize(1000,800);
    win.wait_for_button();

    // add a 100-by-100 image, have it move around
    Image snow(Point(0,0),"pics_and_txt/snow_cpp.gif");
    snow.set_mask(Point(110,70),100,100);
    win.attach(snow);
    //win.resize(1000,800);
    win.wait_for_button();

    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    while (true) {
        x = randint(8);
        y = randint(8);
        dx = 100*x - snow.point(0).x;
        dy = 100*y - snow.point(0).y;
        snow.move(dx,dy);
        //win.resize(1000,800);
        win.wait_for_button();
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
