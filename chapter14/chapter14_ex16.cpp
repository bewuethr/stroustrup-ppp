// Chapter 14, exercise 16: Controller class with virtual functions

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

class Controller {
public:
    virtual void on() =0;
    virtual void off() =0;
    virtual void set_level(int level) =0;
    virtual void show() const =0;
protected:
    Controller() { };
};

class Controller_test : public Controller {
public:
    Controller_test(bool on, int level) : is_on(on), lvl(level) { }
    void on() { is_on = true; }
    void off() { is_on = false; }
    void set_level(int level) { lvl = level; }
    void show() const;
private:
    bool is_on;
    int lvl;
};

void Controller_test::show() const
{
    if (is_on) cout << "Controller is set to on" << endl;
    else cout << "Controller is set to off" << endl;
    cout << "Level is " << lvl << endl;
}

class Shape_controller : public Controller {
public:
    Shape_controller(Shape& shape) : shp(&shape) { }
    void on() { shp->set_color(Color::visible); }
    void off() { shp->set_color(Color::invisible); }
    void set_level(int level) { shp->set_style(Line_style(Line_style::solid,level)); }
    void show() const;
private:
    Shape* shp;
};

void Shape_controller::show() const
{
    if (shp->color().visibility()) cout << "Shape is visible" << endl;
    else cout << "Shape is invisible" << endl;
    cout << "Line width is " << shp->style().width() << endl;
}

int main()
try {
    using namespace Graph_lib;

    Controller_test ctrl_test(false,0);
    ctrl_test.show();
    ctrl_test.on();
    ctrl_test.set_level(10);
    ctrl_test.show();
    ctrl_test.off();
    ctrl_test.set_level(5);
    ctrl_test.show();

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Circle c(Point(150,150),100);
    c.set_style(Line_style(Line_style::solid,4));
    win.attach(c);
    Shape_controller sc1(c);
    sc1.show();
    win.wait_for_button();
    sc1.set_level(8);
    sc1.show();
    win.wait_for_button();
    sc1.off();
    sc1.show();
    win.wait_for_button();

    Hat_frowny hf(Point(500,150),100);
    hf.set_style(Line_style(Line_style::solid,4));
    win.attach(hf);
    Shape_controller sc2(hf);
    sc2.show();
    win.wait_for_button();
    sc2.set_level(8);
    sc2.show();
    win.wait_for_button();
    sc2.off();
    sc2.show();
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
