
//
// This is example code from Chapter 25.4.2 "A problem: Dysfunctional interfaces" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

class Point
{
public:
    Point(int x, int y);
};

//------------------------------------------------------------------------------

class Shape 
{
public:
    virtual void draw();
};

//------------------------------------------------------------------------------

class Circle : public Shape { /* ... */ };

//------------------------------------------------------------------------------

class Rectangle : public Shape 
{
public:
    Rectangle(const Point& p1, const Point& p2);
};

//------------------------------------------------------------------------------

class Polygon : public Shape {};

//------------------------------------------------------------------------------

void poor(Shape* p, int sz)    // poor interface design
{
    for (int  i = 0; i<sz; ++i) p[i].draw();
}

//------------------------------------------------------------------------------

void f(Shape* q, vector<Circle>& s0)    // very bad code
{
    const int max = 25;
    Polygon s1[10];
    Shape s2[10];
    // initialize
    Shape* p1 = new Rectangle(Point(0,0),Point(10,20)); 
    poor(&s0[0],s0.size());    // #1 (pass the array from the vector)
    poor(s1,10);               // #2
    poor(s2,20);               // #3
    poor(p1,1);                // #4
    delete p1;
    p1 = 0;
    poor(p1,1);                // #5
    poor(q,max);               // #6
}

//------------------------------------------------------------------------------

void fv(vector<Shape>&);

//------------------------------------------------------------------------------

void f(Shape &);

//------------------------------------------------------------------------------

void g(vector<Circle>& v, Circle & d)
{
    f(d);       // ok: implicit conversion from Circle to Shape
    //fv(v);    // error no conversion from vector< Circle > to vector< Shape >
}

//------------------------------------------------------------------------------

void poor(Shape* p, int sz);

//------------------------------------------------------------------------------

void general(vector<Shape>&);

//------------------------------------------------------------------------------
