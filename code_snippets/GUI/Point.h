
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef POINT_GUARD
#define POINT_GUARD

//------------------------------------------------------------------------------

struct Point {
    int x, y;
    Point(int xx, int yy) : x(xx), y(yy) { }
    Point() :x(0), y(0) { }
};

//------------------------------------------------------------------------------

inline bool operator==(Point a, Point b) { return a.x==b.x && a.y==b.y; } 

//------------------------------------------------------------------------------

inline bool operator!=(Point a, Point b) { return !(a==b); }

//------------------------------------------------------------------------------

#endif // POINT_GUARD

