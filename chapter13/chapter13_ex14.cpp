//  Chapter 13, exercise 14: create right triangle class, make octagon
// Exercise 15: tile window with right triangles

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Right_triangle rt1(Point(250,250),100,100,180);
    rt1.set_fill_color(Color::yellow);
    win.attach(rt1);
    Right_triangle rt2(Point(250,150),100,100,0);
    rt2.set_fill_color(Color::red);
    win.attach(rt2);
    Right_triangle rt3(Point(350,250),100,100,180);
    rt3.set_fill_color(Color::blue);
    win.attach(rt3);
    Right_triangle rt4(Point(350,250),100,100,-90);
    rt4.set_fill_color(Color::green);
    win.attach(rt4);
    Vector_ref<Right_triangle> vrt;
    for (int i = 0; i<3; ++i) {
        vrt.push_back(new Right_triangle(Point(150+100*i,250),100,100,0));
        vrt[vrt.size()-1].set_fill_color(50*i);
        win.attach(vrt[vrt.size()-1]);
        vrt.push_back(new Right_triangle(Point(250+100*i,350),100,100,180));
        vrt[vrt.size()-1].set_fill_color(50*i+25);
        win.attach(vrt[vrt.size()-1]);
    }
    Right_triangle rt5(Point(250,350),100,100,90);
    rt5.set_fill_color(Color::dark_blue);
    win.attach(rt5);
    Right_triangle rt6(Point(250,350),100,100,0);
    rt6.set_fill_color(Color::dark_green);
    win.attach(rt6);
    Right_triangle rt7(Point(350,450),100,100,180);
    rt7.set_fill_color(Color::dark_yellow);
    win.attach(rt7);
    Right_triangle rt8(Point(350,350),100,100,0);
    rt8.set_fill_color(Color::dark_magenta);
    win.attach(rt8);
    win.wait_for_button();

    Vector_ref<Right_triangle> vtri;
    int len = 50;

    for (int i = 0; i<win.x_max(); i+=len) {
        for (int j = 0; j<win.y_max(); j+=len) {
            vtri.push_back(new Right_triangle(Point(i,j),len,len,0));
            vtri[vtri.size()-1].set_fill_color(i/len%14);
            vtri[vtri.size()-1].set_style(Line_style(Line_style::solid,2));
            win.attach(vtri[vtri.size()-1]);
            vtri.push_back(new Right_triangle(Point(i+len,j+len),len,len,180));
            vtri[vtri.size()-1].set_fill_color(j/len%14);
            vtri[vtri.size()-1].set_style(Line_style(Line_style::solid,2));
            win.attach(vtri[vtri.size()-1]);
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
