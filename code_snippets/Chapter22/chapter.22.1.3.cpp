
//
// This is example code from Chapter 22.1.3 "Styles/paradigms" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

class Point
{
public:
    Point(int x, int y) {}
};

//------------------------------------------------------------------------------

class Shape
{
public:
    virtual void draw() {}
};

//------------------------------------------------------------------------------

class Circle : public Shape
{
public:
    Circle(const Point& c, int r) {}
};

//------------------------------------------------------------------------------

class Triangle : public Shape 
{
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3) {}
};

//------------------------------------------------------------------------------

void draw_all(vector<Shape*>& v)
{
    for(int i = 0; i<v.size(); ++i) v[i]->draw();
}

//------------------------------------------------------------------------------

void draw_all_1(vector<Shape*>& v)
{
    for_each(v.begin(),v.end(),mem_fun(&Shape::draw));
}

//------------------------------------------------------------------------------

template<class Iter> void draw_all(Iter b, Iter e)
{
    for_each(b,e,mem_fun(&Shape::draw));
}

//------------------------------------------------------------------------------

int main()
{
    Point p(0,100);
    Point p2(50,50);
    Shape* a[ ] = { new Circle(p,50), new Triangle(p,p2,Point(25,25)) };
    draw_all(a,a+2);
}

//------------------------------------------------------------------------------
