
//
// This is example code from Chapter 17.5.2 "Destructors and free store" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"
#include "../GUI/Graph.h" // get access to our graphics library facilities

using namespace Graph_lib;

//------------------------------------------------------------------------------

Shape* fct()
{
    Text tt(Point(200,200),"Annemarie");
    // ...
    Shape* p = new Text(Point(100,100),"Nicholas");
    return p;
}

//------------------------------------------------------------------------------

void f()
{
    Shape* q = fct();
    // ...
    delete q;
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
