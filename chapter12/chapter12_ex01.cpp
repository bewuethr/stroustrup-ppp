// Chapter 12, exercise 01: draw rectangle as Rectangle and Polygon
// Exercise 02: Draw 100-by-30 Rectangle, place text inside it
// Exercise 03: Draw initials 150 px high
// Exercise 04: Draw 3-by-3 tic-tac-toe board
// Exercise 05: Draw red frame around rectangle
// Exercise 06: Draw Shape that doesn't fit window, draw Window that doesn't
// fit screen
// Exercise 07: Draw 2D house
// Exercise 08: Draw Olympic rings
// Exercise 09: Display image, label with title and caption
// Exercise 10: Draw file diagram from §12.8
// Exercise 11: Draw series of polygons inside of each other
// Exercise 12: Connect points on superellipse
// Exercise 13: Add colour to exercise 12

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

// draw retangle as Rectangle (blue) and as Polygon (red)
void ex01(Simple_window& win)
{
    Graph_lib::Rectangle rect(Point(100,100),150,100);
    rect.set_color(Color::blue);
    win.attach(rect);

    Graph_lib::Polygon polyg;
    polyg.add(Point(100,250));
    polyg.add(Point(250,250));
    polyg.add(Point(250,300));
    polyg.add(Point(100,300));
    polyg.set_color(Color::red);
    win.attach(polyg);

    win.wait_for_button();
}

// draw a 100-by-30 rectangle and write "Howdy!" in it
void ex02(Simple_window& win)
{
    Graph_lib::Rectangle name_rect(Point(300,100),100,30);
    win.attach(name_rect);

    Text t(Point(325,120),"Howdy!");
    win.attach(t);

    win.wait_for_button();
}

// draw your initials 150 px high with a thick line, different colors each
void ex03(Simple_window& win)
{
    Closed_polyline letter_b;
    letter_b.add(Point(100,100));
    letter_b.add(Point(150,100));
    letter_b.add(Point(170,125));
    letter_b.add(Point(170,150));
    letter_b.add(Point(150,175));
    letter_b.add(Point(100,175));
    letter_b.add(Point(150,175));
    letter_b.add(Point(175,200));
    letter_b.add(Point(175,225));
    letter_b.add(Point(150,250));
    letter_b.add(Point(100,250));
    letter_b.set_color(Color::blue);
    letter_b.set_style(Line_style(Line_style::solid,4));
    win.attach(letter_b);

    Open_polyline letter_w;
    letter_w.add(Point(190,100));
    letter_w.add(Point(215,250));
    letter_w.add(Point(240,175));
    letter_w.add(Point(265,250));
    letter_w.add(Point(290,100));
    letter_w.set_color(Color::red);
    letter_w.set_style(Line_style(Line_style::solid,4));
    win.attach(letter_w);

    win.wait_for_button();
}

// draw a 3-by-3 tic-tac-toe board of alternating white and red squares
void ex04(Simple_window& win)
{
    // create squares
    Graph_lib::Rectangle rect1(Point(100,100),100,100);
    rect1.set_fill_color(Color::white);
    win.attach(rect1);

    Graph_lib::Rectangle rect2(Point(200,100),100,100);
    rect2.set_fill_color(Color::red);
    win.attach(rect2);

    Graph_lib::Rectangle rect3(Point(300,100),100,100);
    rect3.set_fill_color(Color::white);
    win.attach(rect3);

    Graph_lib::Rectangle rect4(Point(100,200),100,100);
    rect4.set_fill_color(Color::red);
    win.attach(rect4);

    Graph_lib::Rectangle rect5(Point(200,200),100,100);
    rect5.set_fill_color(Color::white);
    win.attach(rect5);

    Graph_lib::Rectangle rect6(Point(300,200),100,100);
    rect6.set_fill_color(Color::red);
    win.attach(rect6);

    Graph_lib::Rectangle rect7(Point(100,300),100,100);
    rect7.set_fill_color(Color::white);
    win.attach(rect7);

    Graph_lib::Rectangle rect8(Point(200,300),100,100);
    rect8.set_fill_color(Color::red);
    win.attach(rect8);

    Graph_lib::Rectangle rect9(Point(300,300),100,100);
    rect9.set_fill_color(Color::white);
    win.attach(rect9);

    win.wait_for_button();
}

// draw a red 1/4-inch frame around a rectangle that is three-quarters
// of the height of your screen (675) and two-thirds of the width (1067)
void ex05(Simple_window& win)
{
    Graph_lib::Rectangle rect(Point(217,63),1067,675);
    rect.set_color(Color::red);
    rect.set_style(Line_style(Line_style::solid,15));
    win.attach(rect);

    win.wait_for_button();
}

// Shape that doesn't fit inside window, Window that doesn't fit on screen
void ex06(Simple_window& win)
{
    Graph_lib::Rectangle rect(Point(100,100),1500,800);
    win.attach(rect);
    win.wait_for_button();
}

// draw a 2D house with a door, two windows, a roof with a chimney
void ex07(Simple_window& win)
{
    Line_style house_style(Line_style::solid,4);

    Graph_lib::Rectangle house(Point(100,370),640,330);
    house.set_style(house_style);
    house.set_fill_color(Color::dark_red);
    win.attach(house);

    Graph_lib::Rectangle door(Point(370,500),100,200);
    door.set_style(house_style);
    door.set_fill_color(Color::dark_green);
    win.attach(door);

    Graph_lib::Rectangle win1(Point(210,525),50,75);
    win1.set_style(house_style);
    win1.set_fill_color(Color::cyan);
    win.attach(win1);

    Graph_lib::Rectangle win2(Point(580,525),50,75);
    win2.set_style(house_style);
    win2.set_fill_color(Color::cyan);
    win.attach(win2);

    Graph_lib::Polygon roof;
    roof.add(Point(50,370));
    roof.add(Point(420,270));
    roof.add(Point(790,370));
    roof.set_style(house_style);
    roof.set_fill_color(Color::dark_blue);
    win.attach(roof);

    Graph_lib::Polygon chimney;
    chimney.add(Point(590,250));
    chimney.add(Point(620,250));
    chimney.add(Point(620,324));
    chimney.add(Point(590,316));
    chimney.set_style(house_style);
    chimney.set_fill_color(Color::dark_magenta);
    win.attach(chimney);

    win.wait_for_button();
}

// draw the Olympic five rings
void ex08(Simple_window& win)
{
    Line_style oly_style(Line_style(Line_style::solid,40));

    Circle c1(Point(300,300),220);
    c1.set_style(oly_style);
    c1.set_color(Color::blue);
    win.attach(c1);

    Circle c2(Point(812,300),220);
    c2.set_style(oly_style);
    win.attach(c2);

    Circle c3(Point(1324,300),220);
    c3.set_style(oly_style);
    c3.set_color(Color::red);
    win.attach(c3);

    Circle c4(Point(556,540),220);
    c4.set_style(oly_style);
    c4.set_color(Color::yellow);
    win.attach(c4);

    Circle c5(Point(1068,540),220);
    c5.set_style(oly_style);
    c5.set_color(Color::green);
    win.attach(c5);

    win.wait_for_button();
}

// display an image on the screen, label with both a title and a caption
void ex09(Simple_window& win)
{
    win.resize(640,480);

    Image img(Point(50,50),"pics_and_txt/image.jpg");
    win.attach(img);
    win.set_label("Breaking the sound barrier");

    Text txt(Point(50,280),"Breaking the sound barrier");
    win.attach(txt);

    win.wait_for_button();
}

// draw the file diagram from §12.8
void ex10(Simple_window& win)
{
    Graph_lib::Rectangle fltk1(Point(400,10),120,40);
    fltk1.set_fill_color(Color::yellow);
    win.attach(fltk1);
    Graph_lib::Rectangle fltk2(Point(406,16),120,40);
    fltk2.set_fill_color(Color::yellow);
    win.attach(fltk2);
    Graph_lib::Rectangle fltk3(Point(412,22),120,40);
    fltk3.set_fill_color(Color::yellow);
    win.attach(fltk3);
    Text fltk_txt(Point(418,42),"FLTK headers");
    win.attach(fltk_txt);

    Graph_lib::Rectangle win_rect(Point(389,130),166,80);
    win_rect.set_fill_color(Color::yellow);
    win.attach(win_rect);
    Text win_txt0(Point(389,127),"Window.h:");
    win_txt0.set_font(Font::helvetica_bold);
    win.attach(win_txt0);
    Text win_txt1(Point(395,150),"// window interface:");
    win.attach(win_txt1);
    Text win_txt2(Point(395,170),"class Window {...};");
    win_txt2.set_font(Font::helvetica_bold);
    win.attach(win_txt2);
    Text win_txt3(Point(395,190),"...");
    win.attach(win_txt3);

    Open_polyline win_fltk;
    win_fltk.add(Point(472,130));
    win_fltk.add(Point(472,62));
    win.attach(win_fltk);
    Graph_lib::Polygon win_fltk_arw;
    win_fltk_arw.add(Point(472,62));
    win_fltk_arw.add(Point(474,67));
    win_fltk_arw.add(Point(470,67));
    win_fltk_arw.set_fill_color(Color::black);
    win.attach(win_fltk_arw);

    // add rest, would be much easier if not everything were passed by reference
    // and would thus stop existing when leaving a scope

    win.wait_for_button();
}

// draw a series of regular polygons one inside the other
void ex11(Simple_window& win)
{
    Graph_lib::Polygon tri;
    tri.add(Point(200,20));
    tri.add(Point(300,20));
    tri.add(Point(250,106));
    win.attach(tri);

    Open_polyline square;
    square.add(Point(200,20));
    square.add(Point(200,120));
    square.add(Point(300,120));
    square.add(Point(300,20));
    win.attach(square);

    Open_polyline pentagon;
    pentagon.add(Point(200,20));
    pentagon.add(Point(169,115));
    pentagon.add(Point(250,179));
    pentagon.add(Point(331,115));
    pentagon.add(Point(300,20));
    win.attach(pentagon);

    Open_polyline hexagon;
    hexagon.add(Point(200,20));
    hexagon.add(Point(150,107));
    hexagon.add(Point(200,194));
    hexagon.add(Point(300,194));
    hexagon.add(Point(350,107));
    hexagon.add(Point(300,20));
    win.attach(hexagon);

    win.wait_for_button();
}

// signum function
double sgn(double d)
{
    if (d>0) return 1;
    else if (d<0) return -1;
    else return 0;
}

// draw a superellipse, connect points
void ex12(int a, int b, double m, double n, int N)
{
    const double pi = 3.14159;
    a = 100 * a;    // a = 1 corresponds to -100px to +100px
    b = 100 * b;

    Point tl(300,25);
    Simple_window win(tl,a*2+20,b*2+20,"Superellipse");

    // get N points on superellipse - shift them all by Point(a,b)
    // to have them centered in the window

    vector<Point> points;

    for (double theta = 0; theta < 2*pi; theta += 2*pi/N) {
        double x = pow(abs(cos(theta)),2/m) * a * sgn(cos(theta)) + a + 10;
        double y = pow(abs(sin(theta)),2/n) * b * sgn(sin(theta)) + b + 10;
        points.push_back(Point(x,y));
    }

    Open_polyline interior1;
    for (int i = 0; i<points.size()/4; ++i) {
        interior1.add(points[i]);
        for (int j = i; j<points.size(); ++j) {
            if (i!=j) {
                interior1.add(points[j]);
                interior1.add(points[i]);
            }
        }
    }
    interior1.set_color(Color::red);
    win.attach(interior1);

    Open_polyline interior2;
    for (int i = points.size()/4; i<points.size()/2; ++i) {
        interior2.add(points[i]);
        for (int j = i; j<points.size(); ++j) {
            if (i!=j) {
                interior2.add(points[j]);
                interior2.add(points[i]);
            }
        }
    }
    interior2.set_color(Color::green);
    win.attach(interior2);

    Open_polyline interior3;
    for (int i = points.size()/2; i<3*points.size()/4; ++i) {
        interior3.add(points[i]);
        for (int j = i; j<points.size(); ++j) {
            if (i!=j) {
                interior3.add(points[j]);
                interior3.add(points[i]);
            }
        }
    }
    interior3.set_color(Color::blue);
    win.attach(interior3);

    Open_polyline interior4;
    for (int i = 3*points.size()/4; i<points.size(); ++i) {
        interior4.add(points[i]);
        for (int j = i; j<points.size(); ++j) {
            if (i!=j) {
                interior4.add(points[j]);
                interior4.add(points[i]);
            }
        }
    }
    interior4.set_color(Color::yellow);
    win.attach(interior4);

    // draw polyline
    Closed_polyline superell;
    for (int i = 0; i<points.size(); ++i)
        superell.add(points[i]);
    superell.set_style(Line_style(Line_style::solid,4));
    win.attach(superell);

    win.wait_for_button();
}

int main()
try {
//    Point p(100,100);
//    Simple_window win(p,1400,800,"My window");
//    ex11(win);

    int a = 4;
    int b = 4;
    double m = 0.5;
    double n = 0.5;
    int N = 50;

    ex12(a,b,m,n,N);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
