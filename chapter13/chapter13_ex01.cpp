// Chapter 13, exercise 01: Arc class, draws part of an ellipse
// Exercise 02: Box class, box with rounded corners
// Exercise 03: Arrow class, line with arrowhead
// Exercise 04: Functions n(), s() etc. returning connection points
// Exercise 05: Functions from 4. for Circle and Ellipse
// Exercise 06: Diagram like in 12.6, add Textbox for rectangle with text label

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Graph_lib::Arc arc1(Point(150,100),100,50,45,175);
    win.attach(arc1);
    //win.wait_for_button();
    arc1.set_color(Color::red);
    //win.wait_for_button();
    arc1.set_angle1(-15);
    //win.wait_for_button();
    arc1.set_angle2(270);
    //win.wait_for_button();
    arc1.set_angles(-175,5);
    //win.wait_for_button();

    Graph_lib::Arc arc2(Point(200,200),50,90,10,170);
    arc2.set_color(Color::green);
    win.attach(arc2);
    //win.wait_for_button();
    arc2.set_fill_color(Color::blue);
    //win.wait_for_button();

    Box box1(Point(300,100),100,80);
    win.attach(box1);
    //win.wait_for_button();
    Box box2(Point(450,100),400,200,25);
    win.attach(box2);
    //win.wait_for_button();
    box1.set_style(Line_style(Line_style::dashdotdot,4));
    //win.wait_for_button();
    box2.set_fill_color(Color::yellow);
    //win.wait_for_button();
    box2.move(50,0);
    //win.wait_for_button();

    Arrow arrow1(Point(100,500),Point(400,450));
    win.attach(arrow1);
    //win.wait_for_button();
    Arrow arrow2(Point(500,500),Point(750,250));
    win.attach(arrow2);
    //win.wait_for_button();
    arrow2.set_color(Color::red);
    //win.wait_for_button();
    arrow2.set_fill_color(Color::green);
    //win.wait_for_button();
    arrow2.set_style(Line_style::dot);
    //win.wait_for_button();
    arrow2.set_style(Line_style(Line_style::solid,4));
    //win.wait_for_button();
    arrow2.move(50,50);
    //win.wait_for_button();
    Arrow arrow3(Point(100,500),Point(200,500));
    win.attach(arrow3);
    Arrow arrow4(Point(100,500),Point(100,300));
    win.attach(arrow4);
    //win.wait_for_button();
    Arrow arrow5(Point(100,500),Point(50,500));
    win.attach(arrow5);
    Arrow arrow6(Point(100,500),Point(75,550));
    win.attach(arrow6);
    //win.wait_for_button();
    arrow6.set_color(Color(Color::black,Color::invisible));
    //win.wait_for_button();

    Graph_lib::Rectangle rect1(Point(200,200),150,150);
    win.attach(rect1);
    Arrow nwr(nw(rect1),Point(nw(rect1).x-30,nw(rect1).y-30));
    win.attach(nwr);
    Arrow nr(n(rect1),Point(n(rect1).x,n(rect1).y-30));
    win.attach(nr);
    Arrow ner(ne(rect1),Point(ne(rect1).x+30,ne(rect1).y-30));
    win.attach(ner);
    Arrow er(e(rect1),Point(e(rect1).x+30,e(rect1).y));
    win.attach(er);
    Arrow ser(se(rect1),Point(se(rect1).x+30,se(rect1).y+30));
    win.attach(ser);
    Arrow sr(s(rect1),Point(s(rect1).x,s(rect1).y+30));
    win.attach(sr);
    Arrow swr(sw(rect1),Point(sw(rect1).x-30,sw(rect1).y+30));
    win.attach(swr);
    Arrow wr(w(rect1),Point(w(rect1).x-30,w(rect1).y));
    win.attach(wr);
    Arrow cr(center(rect1),Point(center(rect1).x+15,center(rect1).y+15));
    win.attach(cr);
    //win.wait_for_button();

    Circle circ1(Point(600,400),105);
    win.attach(circ1);
    Arrow nwc(nw(circ1),Point(nw(circ1).x-30,nw(circ1).y-30));
    win.attach(nwc);
    Arrow nc(n(circ1),Point(n(circ1).x,n(circ1).y-30));
    win.attach(nc);
    Arrow nec(ne(circ1),Point(ne(circ1).x+30,ne(circ1).y-30));
    win.attach(nec);
    Arrow ec(e(circ1),Point(e(circ1).x+30,e(circ1).y));
    win.attach(ec);
    Arrow sec(se(circ1),Point(se(circ1).x+30,se(circ1).y+30));
    win.attach(sec);
    Arrow sc(s(circ1),Point(s(circ1).x,s(circ1).y+30));
    win.attach(sc);
    Arrow swc(sw(circ1),Point(sw(circ1).x-30,sw(circ1).y+30));
    win.attach(swc);
    Arrow wc(w(circ1),Point(w(circ1).x-30,w(circ1).y));
    win.attach(wc);
    Arrow cc(center(circ1),Point(center(circ1).x+15,center(circ1).y+15));
    win.attach(cc);
    //win.wait_for_button();

    Graph_lib::Ellipse ell1(Point(900,400),105,55);
    win.attach(ell1);
    Arrow nwel(nw(ell1),Point(nw(ell1).x-30,nw(ell1).y-30));
    win.attach(nwel);
    Arrow nel(n(ell1),Point(n(ell1).x,n(ell1).y-30));
    win.attach(nel);
    Arrow neel(ne(ell1),Point(ne(ell1).x+30,ne(ell1).y-30));
    win.attach(neel);
    Arrow eel(e(ell1),Point(e(ell1).x+30,e(ell1).y));
    win.attach(eel);
    Arrow seel(se(ell1),Point(se(ell1).x+30,se(ell1).y+30));
    win.attach(seel);
    Arrow sel(s(ell1),Point(s(ell1).x,s(ell1).y+30));
    win.attach(sel);
    Arrow swel(sw(ell1),Point(sw(ell1).x-30,sw(ell1).y+30));
    win.attach(swel);
    Arrow wel(w(ell1),Point(w(ell1).x-30,w(ell1).y));
    win.attach(wel);
    Arrow cel(center(ell1),Point(center(ell1).x+15,center(ell1).y+15));
    win.attach(cel);
    win.wait_for_button();

    Textbox tb(Point(100,600),75,"Window");
    tb.label.set_font(Font::helvetica_bold);
    win.attach(tb);
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
