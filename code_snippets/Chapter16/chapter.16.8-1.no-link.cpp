
//
// This is example code from Chapter 16.8 "Debugging GUI code" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "GUI.h"
#include "Point.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

void cb_flood(Address, Address);
void cb_fire(Address, Address);

//------------------------------------------------------------------------------

// helper function for loading buttons into a menu
void load_disaster_menu(Menu& m)
{
    Point orig(0,0);
    Button b1(orig,0,0,"flood",cb_flood); 
    Button b2(orig,0,0,"fire",cb_fire);
    // ...
    m.attach(b1);
    m.attach(b2);
    // ...
}

//------------------------------------------------------------------------------

int main()
try
{
    Simple_window win(Point(100,100),600,400,"Disasters");
    // ...
    Menu disasters(Point(0,0),70,20,Menu::vertical,"color");
    load_disaster_menu(disasters);
    win.attach(disasters);
    // ...
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
