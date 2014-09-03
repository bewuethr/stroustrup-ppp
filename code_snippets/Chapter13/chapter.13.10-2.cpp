
//
// This is example code from Chapter 13.10 "Managing unnamed objects" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Simple_window win(Point(100,100),600,400,"16*16 color matrix");
    Vector_ref<Rectangle> vr;

    for (int i = 0; i<16; ++i)
        for (int j = 0; j<16; ++j) {
            vr.push_back(new Rectangle(Point(i*20,j*20),20,20));
            vr[vr.size()-1].set_fill_color(i*16+j);
            win.attach(vr[vr.size()-1]);
        }

    win.wait_for_button();       // Display!
}
catch(exception& e) {
    // some error reporting
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}

//------------------------------------------------------------------------------
