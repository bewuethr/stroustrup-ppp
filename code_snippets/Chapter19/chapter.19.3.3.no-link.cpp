
//
// This is example code from Chapter 19.3.3 "Containers and inheritance" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"
#include "../GUI/Graph.h" // get access to our graphics library facilities

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main()
{
    vector<Shape> vs;
    vector<Circle> vc;
    //vs = vc;       // error: vector<Shape> required
    void f(vector<Shape>&);
    //f(vc);         // error: vector<Shape> required

    vector<Shape*> vps;
    vector<Circle*> vpc;
    //vps = vpc;     // error: vector<Shape*> required
    void f(vector<Shape*>&);
    //f(vpc);        // error: vector<Shape*> required
}

//------------------------------------------------------------------------------

void f(vector<Shape*>& v)
{
    v.push_back(new Rectangle(Point(0,0),Point(100,100)));
}

//------------------------------------------------------------------------------
