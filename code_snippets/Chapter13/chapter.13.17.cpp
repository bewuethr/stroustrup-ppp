
//
// This is example code from Chapter 13.17 "Images" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Simple_window win(Point(100,100),600,400,"Images");

    Image rita(Point(0,0),"rita.jpg");
    Image path(Point(0,0),"rita_path.gif");
    path.set_mask(Point(50,250),600,400); // select likely landfall

    win.attach(path);
    win.attach(rita);

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
