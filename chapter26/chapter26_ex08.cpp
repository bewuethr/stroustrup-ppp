// Chapter 26, exercise 8: write a text interface for the graphics interface
// library from Chapters 12 to 15; use it to make a "kid's drawing" of a 2D
// house with a roof, two windows and a door
//
// Support the following elements:
// Line(Point p1, Point p2)
// Rectangle(Point xy, int ww, int hh)
// Circle(Point p, int rr)

#include<iostream>
#include<fstream>
#include<exception>
#include<string>
#include<limits>
#include "../code_snippets/GUI/Simple_window.h"

//-----------------------------------------------------------------------------

using namespace Graph_lib;

//-----------------------------------------------------------------------------

// read a point of format "Point(int x, int y)"
istream& operator>>(istream& is, Point& p)
{
    string s;
    char ch;
    while (is >> ch) {
        if (ch=='(')
            break;
        s += ch;
    }
    is.unget();
    if (s != "Point")
        error("expected 'Point'");
    char ch1;
    char ch2;
    char ch3;
    int x;
    int y;
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (ch1!='(' || ch2!=',' || ch3!=')')
        error("expected '(', ',' or ')'");
    p = Point(x,y);
    return is;
}

//-----------------------------------------------------------------------------

// read contents of circle: "Point(int x, int y), int rad"
Circle* get_circle(istream& is)
{
    char ch1;
    Point p;
    char ch2;
    int rad;
    char ch3;
    is >> ch1 >> p >> ch2 >> rad >> ch3;
    if (ch1!='(' || ch2!=',' || ch3!=')')
        error("get_circle(): expected '(', ',' or ')'");
    is.ignore(numeric_limits<streamsize>::max(),'\n');  // ignore rest of line
    return new Circle(p,rad);
}

//-----------------------------------------------------------------------------

// read contents of line: "Point(int x1, int y1), Point(int x2, int y2)"
Line* get_line(istream& is)
{
    char ch1;
    char ch2;
    char ch3;
    Point p1;
    Point p2;
    is >> ch1 >> p1 >> ch2 >> p2 >> ch3;
    if (ch1!='(' || ch2!=',' || ch3!=')')
        error("get_line(): expected '(', ',' or ')'");
    is.ignore(numeric_limits<streamsize>::max(),'\n');
    return new Line(p1,p2);
}

//-----------------------------------------------------------------------------

// read contents of rectangle: "Point(int x, int y), int w, int h"
Graph_lib::Rectangle* get_rectangle(istream& is)
{
    char ch1;
    Point p;
    char ch2;
    int w;
    char ch3;
    int h;
    char ch4;
    is >> ch1 >> p >> ch2 >> w >> ch3 >> h >> ch4;
    if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')')
        error("get_rectangle(): expected '(', ',' or ')'");
    is.ignore(numeric_limits<streamsize>::max(),'\n');
    return new Graph_lib::Rectangle(p,w,h);
}

//-----------------------------------------------------------------------------

// returns a pointer to the next Shape extracted from is, null if no successful
Shape* get_shape(istream& is)
{
    string type;
    char ch;
    while (is >> ch) {
        if (ch == '(') {
            is.unget();
            break;
        }
        type += ch;
    }
    if (type == "Circle")
        return get_circle(is);
    if (type == "Line")
        return get_line(is);
    if (type == "Rectangle")
        return get_rectangle(is);
    else
        return 0;
}

//-----------------------------------------------------------------------------

int main()
try {
    Simple_window win(Point(400,100),800,700,"My window");
    string ifname = "pics_and_txt/chapter26_ex08_in.txt";
    ifstream ifs(ifname);
    if (!ifs)
        error("can't open ",ifname);
    Vector_ref<Shape> vec;
    while (true) {
        Shape* s = get_shape(ifs);
        if (s) {
            vec.push_back(s);
            win.attach(vec[vec.size()-1]);
        }
        else
            break;
    }
    win.wait_for_button();
}
catch (exception& e) {
    cerr << e.what() << endl;
}
catch (...) {
    cerr << "exception \n";
}

//------------------------------------------------------------------------------
