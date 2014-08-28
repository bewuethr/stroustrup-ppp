
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef GRAPH_GUARD
#define GRAPH_GUARD 1

#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include "Point.h"
#include "std_lib_facilities.h"

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

// Container of Shapes
struct Group : Shape {
    void add_shape(Shape& s) { shapes.push_back(s); }

    void draw() const;
    void move(int dx, int dy);

    void set_color(Color col);
    void set_style(Line_style sty);
    void set_fill_color(Color col);

    //void draw_lines() const;

private:
    Vector_ref<Shape> shapes;
    Shape::number_of_points;
    Shape::point;
    Shape::add;
    Shape::set_point;
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

struct Arrow : Line {
    Arrow(Point p1, Point p2) :Line(p1,p2) { }
    void draw_lines() const;
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

struct Striped_rectangle : Rectangle {
    Striped_rectangle(Point xy, int ww, int hh) : Rectangle(xy,ww,hh) { }
    Striped_rectangle(Point x, Point y) : Rectangle(x,y) { }

    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Box : Shape {
    Box(Point pp, int ww, int hh) :w(ww), h(hh)
    {
        if (h<=0 || w<=0) error("Bad rectangle: non-positive width or height");
        add(pp);
        rad = w<h ? w/4 : h/4;
    }
    Box(Point pp, int ww, int hh, int rr) :w(ww), h(hh), rad(rr)
    {
        if (h<=0 || w<=0) error("Bad rectangle: non-positive width or height");
        if (rad > (w>h?h:w)/2) error("box corner radius too large");
        add(pp);
    }
    void draw_lines() const;

    int height() const { return h; }
    int width() const { return w; }
private:
    int w;
    int h;
    int rad;
};

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
};

//------------------------------------------------------------------------------

Point n(const Box& box);
Point s(const Box& box);
Point e(const Box& box);
Point w(const Box& box);
Point center(const Box& box);
Point ne(const Box& box);
Point se(const Box& box);
Point sw(const Box& box);
Point nw(const Box& box);

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

struct Striped_closed_polyline : Closed_polyline {
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Polygon : Closed_polyline {    // closed sequence of non-intersecting lines
    void add(Point p);
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Poly : Polygon { // like Polygon, but check if Polygon in constructor
    Poly(vector<Point> ps);
    void add(Point p);
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Regular_hexagon : Shape {    // six-sided polygon with all sides of equal length
    Regular_hexagon(Point xy, int ss);

    void draw_lines() const;

    Point center() const { return Point(point(0).x+s,point(0).y); }
    int side() const { return s; }
    void set_side(int ss) { set_points(center(),ss); }
private:
    int s;  // length of one side
    void set_points(Point xy, int s);
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

struct Octagon : Regular_polygon {
    Octagon(Point cc, int rr) : Regular_polygon(cc,8,rr) { }
private:
    Regular_polygon::n_edges;
};

//------------------------------------------------------------------------------

struct Star : Regular_polygon {
    Star(Point cc, int nn, int rr);

    void draw_lines() const { Regular_polygon::draw_lines(); }
    Point center() const { return point(0); }
    int radius() const { return rad; }
    int n_arms() const { return n; }

    void set_radius(int rr) { set_points(center(),n,rr); }
private:
    int rad;    // distance from arm tip to center
    int n;      // number of arms;
    void set_points(Point xy, int nn, int rr);
    void move_points();
};

//------------------------------------------------------------------------------

struct Right_triangle : Shape {
    Right_triangle(Point cc, int ss_x, int ss_y, double pphi);

    void draw_lines() const;
    Point vertex() const { return point(0); }   // point at right angle
    int side_x() const { return s_x; }
    int side_y() const { return s_y; }
    double angle() const { return phi/pi*180; } // angle in degrees

    void rotate(double dphi);   // rotate clockwise by dphi in degrees
private:
    int s_x;    // length of edge along x-axis
    int s_y;    // length of edge along y-axis
    double phi; // angle (in degrees) by which triangle is rotated (cw)
};

//------------------------------------------------------------------------------

struct Textbox : Box {
    Textbox(Point xy, int ww, string s)
        :Box(xy,ww,h_tb), label(Point(xy.x+4,xy.y+17),s) { }

    void draw_lines() const;
    void move(int dx, int dy);
    void set_color(Color c);

    Text label;
private:
    static const int h_tb = 24;
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

struct Clock : Circle {
    Clock(Point p, int rr);
    void draw_lines() const;
    void increase_time();
    void update_hands();
private:
    Lines ticks;
    Vector_ref<Line> hands;
    int hh;
    int mm;
    int ss;
};

//------------------------------------------------------------------------------

struct Striped_circle : Circle {
    Striped_circle(Point p, int rr) : Circle(p,rr) { }

    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Immobile_circle : Circle {
    Immobile_circle(Point p, int rr) : Circle(p,rr) { }
private:
    Circle::move;
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

struct Ellipse : Shape {
	Ellipse(Point p, int ww, int hh)	// center, min, and max distance from center
		:w(ww), h(hh) { add(Point(p.x-ww,p.y-hh)); }

	void draw_lines() const;

	Point center() const { return Point(point(0).x+w,point(0).y+h); }
	Point focus1() const {
			if (h<=w)// foci are on the x-axis:
					return Point(center().x+int(sqrt(double(w*w-h*h))),center().y);
			else	// foci are on the y-axis:
					return Point(center().x,center().y+int(sqrt(double(h*h-w*w))));
	}

	Point focus2() const {
			if (h<=w)
					return Point(center().x-int(sqrt(double(w*w-h*h))),center().y);
			else
					return Point(center().x,center().y-int(sqrt(double(h*h-w*w))));
	}
	//Point focus2() const { return Point(center().x-int(sqrt(double(abs(w*w-h*h)))),center().y); }

	void set_major(int ww) { set_point(0,Point(center().x-ww,center().y-h)); w=ww; }
	int major() const { return w; }
	void set_minor(int hh) { set_point(0,Point(center().x-w,center().y-hh)); h=hh; }
	int minor() const { return h; }
private:
	int w;
	int h;
};

//------------------------------------------------------------------------------

Point n(const Ellipse& e);
Point s(const Ellipse& e);
Point e(const Ellipse& e);
Point w(const Ellipse& e);
Point center(const Ellipse& e);
Point ne(const Ellipse& e);
Point se(const Ellipse& e);
Point sw(const Ellipse& e);
Point nw(const Ellipse& e);

//------------------------------------------------------------------------------

struct Arc : Shape {
    Arc(Point p, int ww, int hh, double aa1, double aa2);

    void draw_lines() const;
    Point center() const { return Point(point(0).x+w,point(0).y+h); }
    void set_major(int ww) { set_point(0,Point(center().x-ww,center().y-h)); w=ww; }
	int major() const { return w; }
	void set_minor(int hh) { set_point(0,Point(center().x-w,center().y-hh)); h=hh; }
	int minor() const { return h; }

    void set_angle1(double d)
    {
        if (d >= a2) error("first arc angle cannot be bigger than second angle");
        a1 = d;
    }

    void set_angle2(double d)
    {
        if (d <= a1) error("second arc angle cannot be smaller than first angle");
        a2 = d;
    }

    void set_angles(double d1, double d2)
    {
        if (d2<=d1) error("second arc angle must be bigger than first angle");
        a1 = d1;
        a2 = d2;
    }
private:
    int w;
    int h;
    double a1;
    double a2;
};

//------------------------------------------------------------------------------

struct Circle_face : Circle {
    void draw_lines() const;

    void move(int dx, int dy);
    void set_color(Color c);
    void set_style(Line_style ls);
    void set_radius(int rr);
protected:
    Circle_face(Point p, int rr);
    Arc mouth;
private:
    Ellipse l_eye;
    Ellipse r_eye;
};

//------------------------------------------------------------------------------

struct Smiley : Circle_face {
    Smiley(Point p, int rr);
};

//------------------------------------------------------------------------------

struct Hat_smiley : Smiley {
    Hat_smiley(Point p, int rr);

    void draw_lines() const
    {
        Smiley::draw_lines();
        if (color().visibility())
            hat.draw();
    }

    void move(int dx, int dy) { Smiley::move(dy,dy); hat.move(dx,dy); }
    void set_color(Color c);
private:
    Polygon hat;
    Smiley::set_radius;    // shouldn't be used here, too annoying
};

//------------------------------------------------------------------------------

struct Frowny : Circle_face {
    Frowny(Point p, int rr);
private:
    Circle_face::set_radius;    // children of Frowny shouldn't be able to use it
};

//------------------------------------------------------------------------------

struct Hat_frowny : Frowny {
    Hat_frowny(Point p, int rr);

    void draw_lines() const {
        Frowny::draw_lines();
        if (color().visibility()) {
            rim.draw();
            bowl.draw();
        }
    }

    void move(int dx, int dy) { Frowny::move(dy,dy); rim.move(dx,dy); bowl.move(dx,dy); }
    void set_color(Color c);
private:
    Rectangle rim;
    Arc bowl;
//    Frowny::set_radius; // shouldn't be used here, too annoying
};

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

struct Pseudo_window : Box {
    Pseudo_window(Point xy, int ww, int hh, string lab);

    void draw_lines() const;
    void move(int dx, int dy);
private:
    Text win_name;
    Box ctrl;
    Lines x;
    Rectangle bg;
    Image content;
};

//------------------------------------------------------------------------------

struct Binary_tree : Shape {
    Binary_tree(Point xy, int levels, string edge_style);   // edge_style: "au" or
                                                            // "ad" for arrow up or
                                                            // down; else normal
    virtual void draw_lines() const;
    void move(int dx, int dy);
    int levels() const { return lvls; }
    void set_node_label(string n, string lbl);
protected:
    Vector_ref<Shape> edges;
    Vector_ref<Text> labels;
private:
    int lvls;   // 1 level: 1 node; 2 levels: 1 node, two childs, etc.
};

//------------------------------------------------------------------------------

struct Binary_tree_squares : Binary_tree {
    Binary_tree_squares(Point xy, int levels, string edge_style)
        : Binary_tree(xy,levels,edge_style) { }
    void draw_lines() const;
private:
};

//------------------------------------------------------------------------------

struct Bar_chart : Shape {
    Bar_chart(Point orig, double yscale = 25, int width = 10, int space = 5);

    void draw_lines() const;
    double value(int i) const { return values[i]; }
    string label(int i) const { return labels[i].label(); }

    void move(int dx, int dy);
    void add_val(double d);
    void set_label(int i, string s) { labels[i].set_label(s); }
private:
    vector<double> values;
    Vector_ref<Text> labels;
    double ysc; // scaling in y-direction
    int wd; // width of bars
    int sp; // space between bars
};

//------------------------------------------------------------------------------

} // of namespace Graph_lib

#endif
