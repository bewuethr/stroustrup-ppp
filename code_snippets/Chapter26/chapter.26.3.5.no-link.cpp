
//
// This is example code from Chapter 26.3.5 "Testing classes" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

class Color 
{
public:
    Color(int =0);
};

//------------------------------------------------------------------------------

class Line_style 
{
public:
    Line_style(int =0);
    bool operator!=(const Line_style&) const;
};

//------------------------------------------------------------------------------

class Point 
{
public:
    Point(int, int);
    bool operator!=(const Point&) const;
};

//------------------------------------------------------------------------------

class Shape  {        // deals with color and style, and holds sequence of lines 
public:
    void draw() const;            // deal with color and draw lines
    virtual void move(int dx, int dy);    // move the shape +=dx and +=dy

    void set_color(Color col);
    int color() const;

    void set_style(Line_style sty);
    Line_style style() const;

    void set_fill_color(Color col);
    Color fill_color() const;

    Point point(int i) const;        // readonly access to points
    int number_of_points() const;

    virtual ~Shape() { }
protected:
    Shape();    
    virtual void draw_lines() const;    // draw the appropriate lines
    void add(Point p);            // add p to points
    void set_point(int i,Point p);        // points[i]=p;
private:
    vector<Point> points;        // not used by all shapes
    Color lcolor;        // color for lines and characters
        Line_style ls; 
    Color fcolor;        // fill color

    Shape(const Shape*);        // prevent copying
    Shape& operator=(const Shape*);
};

//------------------------------------------------------------------------------

class Line : public Shape 
{
public:
    Line(const Point&, const Point&);
};

//------------------------------------------------------------------------------

int main()
{
    Line ln(Point(10,10), Point(100, 100));
    ln.draw();             // see if it appears
    
    // check the points:
    if (ln.number_of_points() != 2) cerr << "wrong number of points";
    if (ln.point(0)!=Point(10,10)) cerr<< "wrong point 1";
    if (ln.point(1)!=Point(100,100)) cerr<< "wrong point 2";
    
    for (int i=0; i<10; ++i) {    // see if it moves
          ln.move(i+5,i+5);
          ln.draw();
        }
    for (int i=0; i<10; ++i) {    // see if it moves back to where it started
          ln.move(i-5,i-5); 
          ln.draw();
        }
    if (ln.point(0)!=Point(10,10)) cerr<< "wrong point 1 after move";
    if (ln.point(1)!=Point(100,100)) cerr<< "wrong point 2 after move";

    for (int i = 0; i<100; ++i) {    // see if the color changes correctly
          ln.set_color(Color(i*100));
        if (ln.color() != i*100) cerr << "bad set_color";
        ln.draw();
    }
    
    for (int i = 0; i<100; ++i) {    // see if the style changes correctly
          ln.set_style(Line_style(i*5));
        if (ln.style() != i*5) cerr << "bad set_style";
        ln.draw();
    }
}

//------------------------------------------------------------------------------
