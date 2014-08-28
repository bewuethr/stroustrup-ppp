// Chapter 14, exercise 01: Smiley derived from Circle, with eyes and a mouth
// Exercise 02: Frowny class
// Exercise 03: Smiley with hat, derived from Smiley
// Exercise 04: Frowny with hat

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Smiley s1(Point(600,400),150);
    win.attach(s1);
    s1.set_fill_color(Color::yellow);
    //win.wait_for_button();
    s1.set_color(Color::red);
    //win.wait_for_button();
    s1.move(-180,50);
    //win.wait_for_button();
    s1.set_radius(300);
    //win.wait_for_button();
    s1.set_style(Line_style(Line_style::solid,4));
    //win.wait_for_button();

    Frowny f1(Point(150,150),100);
    win.attach(f1);
    //win.wait_for_button();

    Hat_smiley hs1(Point(900,400),175);
    win.attach(hs1);
    //win.wait_for_button();
    hs1.set_fill_color(Color::yellow);
    hs1.set_color(Color::dark_blue);
    hs1.set_style(Line_style(Line_style::solid,4));
    //win.wait_for_button();

    Hat_frowny hf1(Point(600,100),75);
    win.attach(hf1);
    //win.wait_for_button();
    hf1.move(50,50);
    hf1.set_style(Line_style(Line_style::solid,4));
    hf1.set_fill_color(Color::yellow);
    //win.wait_for_button();

    //Hat_frowny hf2 = hf1; // Ex. 2: trying to copy a shape
    //Shape sh1;  // Ex. 3: trying to define an object of an abstract class
    Vector_ref<Shape> shapes;
    shapes.push_back(s1);
    shapes.push_back(f1);
    shapes.push_back(hs1);
    shapes.push_back(hf1);
    for (int i = 0; i<shapes.size(); ++i)
        shapes[i].move(50,50);
    win.wait_for_button();

    Immobile_circle ic(Point(100,500),100);
    win.attach(ic);
    win.wait_for_button();
    //ic.move(50,50);   // Ex. 4: trying to move an Immobile_circle
    //win.wait_for_button();

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
