
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef GRAPH_GUARD
#define GRAPH_GUARD 1

#include<FL/fl_draw.H>
#include<FL/Fl_Image.H>

#include "chapter19_ex14_Point.h"
#include "chapter19_ex14_wumpus.h"
#include "../lib_files/std_lib_facilities.h"

namespace Graph_lib {;

// defense against ill-behaved Linux macros:
#undef major
#undef minor

//------------------------------------------------------------------------------

const double pi = 3.1415926;

//------------------------------------------------------------------------------

// Color is the type we use to represent color. We can use Color like this:
//    grid.set_color(Color::red);
struct Color {
    enum Color_type {
        red=FL_RED,
        blue=FL_BLUE,
        green=FL_GREEN,
        yellow=FL_YELLOW,
        white=FL_WHITE,
        black=FL_BLACK,
        magenta=FL_MAGENTA,
        cyan=FL_CYAN,
        dark_red=FL_DARK_RED,
        dark_green=FL_DARK_GREEN,
        dark_yellow=FL_DARK_YELLOW,
        dark_blue=FL_DARK_BLUE,
        dark_magenta=FL_DARK_MAGENTA,
        dark_cyan=FL_DARK_CYAN
    };

    enum Transparency { invisible = 0, visible=255 };

    Color(Color_type cc) :c(Fl_Color(cc)), v(visible) { }
    Color(Color_type cc, Transparency vv) :c(Fl_Color(cc)), v(vv) { }
    Color(int cc) :c(Fl_Color(cc)), v(visible) { }
    Color(Transparency vv) :c(Fl_Color()), v(vv) { }    // default color

    int as_int() const { return c; }

    char visibility() const { return v; }
    void set_visibility(Transparency vv) { v=vv; }
private:
    char v;    // invisible and visible for now
    Fl_Color c;
};

//------------------------------------------------------------------------------

struct Line_style {
    enum Line_style_type {
        solid=FL_SOLID,            // -------
        dash=FL_DASH,              // - - - -
        dot=FL_DOT,                // .......
        dashdot=FL_DASHDOT,        // - . - .
        dashdotdot=FL_DASHDOTDOT,  // -..-..
    };

    Line_style(Line_style_type ss) :s(ss), w(0) { }
    Line_style(Line_style_type lst, int ww) :s(lst), w(ww) { }
    Line_style(int ss) :s(ss), w(0) { }

    int width() const { return w; }
    int style() const { return s; }
private:
    int s;
    int w;
};

//------------------------------------------------------------------------------

class Font {
public:
    enum Font_type {
        helvetica=FL_HELVETICA,
        helvetica_bold=FL_HELVETICA_BOLD,
        helvetica_italic=FL_HELVETICA_ITALIC,
        helvetica_bold_italic=FL_HELVETICA_BOLD_ITALIC,
        courier=FL_COURIER,
        courier_bold=FL_COURIER_BOLD,
        courier_italic=FL_COURIER_ITALIC,
        courier_bold_italic=FL_COURIER_BOLD_ITALIC,
        times=FL_TIMES,
        times_bold=FL_TIMES_BOLD,
        times_italic=FL_TIMES_ITALIC,
        times_bold_italic=FL_TIMES_BOLD_ITALIC,
        symbol=FL_SYMBOL,
        screen=FL_SCREEN,
        screen_bold=FL_SCREEN_BOLD,
        zapf_dingbats=FL_ZAPF_DINGBATS
    };

    Font(Font_type ff) :f(ff) { }
    Font(int ff) :f(ff) { }

    int as_int() const { return f; }
private:
    int f;
};

//------------------------------------------------------------------------------

template<class T> class Vector_ref {
    vector<T*> v;
    vector<T*> owned;
public:
    Vector_ref() {}
    Vector_ref(T& a) { push_back(a); }
    Vector_ref(T& a, T& b);
    Vector_ref(T& a, T& b, T& c);
    Vector_ref(T* a, T* b = 0, T* c = 0, T* d = 0)
    {
        if (a) push_back(a);
        if (b) push_back(b);
        if (c) push_back(c);
        if (d) push_back(d);
    }

    ~Vector_ref() { for (int i=0; i<owned.size(); ++i) delete owned[i]; }

    void push_back(T& s) { v.push_back(&s); }
    void push_back(T* p) { v.push_back(p); owned.push_back(p); }
/*
	void erase(int i)
	{
		if (i<0 || v.size()<=i) return;
		T* p = v[i];
		v.erase(v.begin()+i);
		for (int i=0; i<owned.size(); ++i)
				if (p==owned[i]) {
						delete p;
						owned.erase(owned.begin()+i);
				}
	}

	void erase(T* p)
	{
		for (int i=0; i<v.size(); ++i)
				if (p==v[i]) v.erase(&v[i]);
		for (int i=0; i<owned.size(); ++i)
				if (p==owned[i]) {
						delete p;
						owned.erase(&owned[i]);
				}
	}
*/
    T& operator[](int i) { return *v[i]; }
    const T& operator[](int i) const { return *v[i]; }

    int size() const { return v.size(); }

private:	// prevent copying
	Vector_ref(const Vector<T>&);
	Vector_ref& operator=(const Vector<T>&);
};

//------------------------------------------------------------------------------

typedef double Fct(double);

class Shape  {        // deals with color and style, and holds sequence of lines
public:
    void draw() const;                 // deal with color and draw lines
    virtual void move(int dx, int dy); // move the shape +=dx and +=dy

    void set_color(Color col) { lcolor = col; }
    Color color() const { return lcolor; }
    void set_style(Line_style sty) { ls = sty; }
    Line_style style() const { return ls; }
    void set_fill_color(Color col) { fcolor = col; }
    Color fill_color() const { return fcolor; }

    Point point(int i) const { return points[i]; } // read only access to points
    int number_of_points() const { return int(points.size()); }

    virtual ~Shape() { }
    void set_point(int i, Point p);     // points[i]=p;
protected:
    Shape();
    virtual void draw_lines() const;    // draw the appropriate lines
    void add(Point p);                  // add p to points
    void clear_points() { points.clear(); }
private:
    vector<Point> points;              // not used by all shapes
    Color lcolor;                      // color for lines and characters
    Line_style ls;
    Color fcolor;                      // fill color

    Shape(const Shape&);               // prevent copying
    Shape& operator=(const Shape&);
};

//------------------------------------------------------------------------------

struct Function : Shape {
    // the function parameters are not stored
    Function(Fct f, double r1, double r2, Point orig,
             int count = 100, double xscale = 25, double yscale = 25);
};

//------------------------------------------------------------------------------

// stores function parameters
struct Flex_function : Function {
    Flex_function(Fct f, double r1, double r2, Point orig, int count = 100,
                  double xscale = 25, double yscale = 25, double precision = 1);
    void reset_fct(Fct f) { fct = f; reset(); }
    void reset_range(double r1, double r2);
    void reset_orig(Point orig) { origin = orig; reset(); }
    void reset_count(int count);
    void reset_xscale(double xscale);
    void reset_yscale(double yscale);
    void reset_precision(double precision) { prec = precision; reset(); }
private:
    void reset();
    Fct* fct;
    double range1;
    double range2;
    Point origin;
    int c;
    double xsc;
    double ysc;
    double prec;
};

//------------------------------------------------------------------------------

struct Line : Shape {            // a Line is a Shape defined by two Points
    Line(Point p1, Point p2);    // construct a line from two points
};

//------------------------------------------------------------------------------

struct Rectangle : Shape {
    Rectangle(Point xy, int ww, int hh) : w(ww), h(hh)
    {
        add(xy);
        if (h<=0 || w<=0) error("Bad rectangle: non-positive side");
    }

    Rectangle(Point x, Point y) : w(y.x-x.x), h(y.y-x.y)
    {
        add(x);
        if (h<=0 || w<=0) error("Bad rectangle: non-positive width or height");
    }
    void draw_lines() const;

    int height() const { return h; }
    int width() const { return w; }
private:
    int h;    // height
    int w;    // width
};

//------------------------------------------------------------------------------

Point n(const Rectangle& rect);
Point s(const Rectangle& rect);
Point e(const Rectangle& rect);
Point w(const Rectangle& rect);
Point center(const Rectangle& rect);
Point ne(const Rectangle& rect);
Point se(const Rectangle& rect);
Point sw(const Rectangle& rect);
Point nw(const Rectangle& rect);

//------------------------------------------------------------------------------

struct Text : Shape {
    // the point is the bottom left of the first letter
    Text(Point x, const string& s) : lab(s), fnt(fl_font()), fnt_sz(fl_size()) { add(x); }

    void draw_lines() const;

    void set_label(const string& s) { lab = s; }
    string label() const { return lab; }

    void set_font(Font f) { fnt = f; }
    Font font() const { return Font(fnt); }

    void set_font_size(int s) { fnt_sz = s; }
    int font_size() const { return fnt_sz; }
private:
    string lab;    // label
    Font fnt;
    int fnt_sz;
};

//------------------------------------------------------------------------------

struct Lines : Shape {                 // related lines
    void draw_lines() const;
    void add(Point p1, Point p2);      // add a line defined by two points
    void clear_points() { Shape::clear_points(); }
};

//------------------------------------------------------------------------------

struct Open_polyline : Shape {         // open sequence of lines
    void add(Point p) { Shape::add(p); }
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Closed_polyline : Open_polyline { // closed sequence of lines
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Polygon : Closed_polyline {    // closed sequence of non-intersecting lines
    void add(Point p);
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Regular_polygon : Shape {
    Regular_polygon(Point cc, int nn, int rr);

    void draw_lines() const;
    Point center() const { return point(0); }
    int radius() const { return rad; }
    int n_edges() const { return n; }

    void set_radius(int rr) { set_points(center(),n,rr); }
protected:
    void set_points(Point xy, int nn, int rr);
private:
    int rad;    // distance from point to center
    int n;      // number of edges;
};

//------------------------------------------------------------------------------

struct Axis : Shape {
    enum Orientation { x, y, z };
    Axis(Orientation d, Point xy, int length,
        int number_of_notches=0, string label = "");

    void draw_lines() const;
    void move(int dx, int dy);
    void set_color(Color c);

    Text label;
    Lines notches;
};

//------------------------------------------------------------------------------

struct Circle : Shape {
	Circle(Point p, int rr);	// center and radius

	void draw_lines() const;

	Point center() const;

	void set_radius(int rr) { set_point(0,Point(center().x-rr,center().y-rr)); r=rr;  }
	int radius() const { return r; }
protected:
	int r;
};

//------------------------------------------------------------------------------

Point n(const Circle& c);
Point s(const Circle& c);
Point e(const Circle& c);
Point w(const Circle& c);
Point center(const Circle& c);
Point ne(const Circle& c);
Point se(const Circle& c);
Point sw(const Circle& c);
Point nw(const Circle& c);

//------------------------------------------------------------------------------

struct Marked_polyline : Open_polyline {
    Marked_polyline(const string& m) :mark(m) { }
    void draw_lines() const;
private:
    string mark;
};

//------------------------------------------------------------------------------

struct Marks : Marked_polyline {
    Marks(const string& m) :Marked_polyline(m)
    {
        set_color(Color(Color::invisible));
    }
};

//------------------------------------------------------------------------------

struct Mark : Marks {
    Mark(Point xy, char c) : Marks(string(1,c))
    {
        add(xy);
    }
};

//------------------------------------------------------------------------------

struct Suffix {
    enum Encoding { none, jpg, gif  };
};

Suffix::Encoding get_encoding(const string& s);

//------------------------------------------------------------------------------

struct Image : Shape {
    Image(Point xy, string file_name, Suffix::Encoding e = Suffix::none);
    ~Image() { delete p; }
    void draw_lines() const;
    void set_mask(Point xy, int ww, int hh) { w=ww; h=hh; cx=xy.x; cy=xy.y; }
private:
    int w,h;  // define "masking box" within image relative to position (cx,cy)
    int cx,cy;
    Fl_Image* p;
    Text fn;
};

//------------------------------------------------------------------------------

struct Bad_image : Fl_Image {
    Bad_image(int h, int w) : Fl_Image(h,w,0) { }
    void draw(int x,int y, int, int, int, int) { draw_empty(x,y); }
};

//------------------------------------------------------------------------------

struct Wumpus_map : Shape {
    Wumpus_map(Point cc, int rr, const vector<Wumpus::Room>& rooms);

    void draw_lines() const;
    void show(int idx); // show label idx and connecting tunnels
    void set_avatar(int idx);
    void hide_all();    // hide complete map (at restart)
    void reset_labels(const vector<Wumpus::Room>& rooms);
    void add_tunnel(Point p1, Point p2) { tunnels.add(p1,p2); }

    Point center() const { return point(0); }
    int radius() const { return rad; }
    int lbl_radius() const { return circles[0].radius(); }
    bool is_visible(int idx) const { return (*labels)[idx].color().visibility(); }
private:
    void set_points();
    void set_labels(const vector<Wumpus::Room>& rooms);
    Vector_ref<Text>* labels;
    Vector_ref<Circle> circles;
    Lines tunnels;
    int rad;
    Image avatar;
};

//------------------------------------------------------------------------------

} // of namespace Graph_lib

#endif
