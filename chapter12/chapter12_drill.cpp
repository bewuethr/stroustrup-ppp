// Chapter 12, drill

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(150,150);
    Simple_window win(tl,600,400,"My window");
    win.resize(600,400);
    win.wait_for_button();

    Axis xa(Axis::x,Point(20,330),300,10,"some axis");
    win.attach(xa);
    win.set_label("Canvas #2");
    win.resize(600,400);
    win.wait_for_button();

    Axis ya(Axis::y,Point(20,330),280,30,"other axis");
    ya.set_color(Color::dark_yellow);
    ya.label.set_color(Color::dark_magenta);
    win.attach(ya);
    win.set_label("Canvas #3");
    win.resize(600,400);
    win.wait_for_button();

    Function cosine(cos,0,100,Point(20,175),100,10,10);
    win.attach(cosine);
    win.set_label("Canvas #4");
    win.resize(600,400);
    win.wait_for_button();

    cosine.set_color(Color::blue);
    Graph_lib::Polygon poly;
    poly.add(Point(300,200));
    poly.add(Point(275,175));
    poly.add(Point(350,100));
    poly.add(Point(425,175));
    poly.add(Point(400,200));

    poly.set_color(Color::dark_blue);
    poly.set_style(Line_style::dot);
    win.attach(poly);
    win.set_label("Canvas #5");
    win.resize(600,400);
    win.wait_for_button();

    Graph_lib::Rectangle r(Point(200,200),100,30);
    win.attach(r);
    win.set_label("Canvas #6");
    win.resize(600,400);
    win.wait_for_button();

    Closed_polyline poly_rect;
    poly_rect.add(Point(100,50));
    poly_rect.add(Point(200,50));
    poly_rect.add(Point(200,120));
    poly_rect.add(Point(100,100));
    win.attach(poly_rect);
    win.resize(600,400);
    win.wait_for_button();

    poly_rect.add(Point(125,75));
    win.resize(600,400);
    win.wait_for_button();

    r.set_fill_color(Color::red);
    poly.set_style(Line_style(Line_style::dashdotdot,2));
    poly_rect.set_style(Line_style(Line_style::dashdot,4));
    poly_rect.set_fill_color(Color::red);
    win.set_label("Canvas #7");
    win.resize(600,400);
    win.wait_for_button();

    Text t(Point(150,150),"Hello, customised world!");
    win.attach(t);
    win.set_label("Canvas #8");
    win.resize(600,400);
    win.wait_for_button();

    t.set_font(Font::helvetica_italic);
    t.set_font_size(50);
    win.set_label("Canvas #9");
    win.resize(600,400);
    win.wait_for_button();

    Image ii(Point(100,50),"pics_and_txt/image.jpg");
    win.attach(ii);
    win.set_label("Canvas #10");
    win.resize(600,400);
    win.wait_for_button();

    ii.move(100,200);
    win.set_label("Canvas #11");
    win.resize(600,400);
    win.wait_for_button();

    Circle c(Point(100,200),50);
    Graph_lib::Ellipse e(Point(100,200),75,25);
    e.set_color(Color::dark_red);
    Mark m(Point(100,200),'X');

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes(Point(100,20),oss.str());

    Image cal(Point(225,225),"pics_and_txt/snow_cpp.gif");
    cal.set_mask(Point(40,40),200,150);

    win.attach(c);
    win.attach(m);
    win.attach(e);
    win.attach(sizes);
    win.attach(cal);
    win.set_label("Canvas #12");
    win.resize(600,400);
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
