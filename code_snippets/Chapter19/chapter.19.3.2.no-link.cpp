
//
// This is example code from Chapter 19.3.2 "Generic programming" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "../GUI/Graph.h" // get access to our graphics library facilities

using namespace Graph_lib;

//------------------------------------------------------------------------------

void shape_test(vector<Shape*>& v, Shape* x, Shape& s)
{
    v.push_back(x);  // put x into the vector v
    s.draw();        // draw the shape s
}

//------------------------------------------------------------------------------

void draw_all(vector<Shape*>& v)
{
    for (int i=0; i<v.size(); ++i) v[i]->draw();
}

//------------------------------------------------------------------------------
