
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "chapter19_ex14_GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "chapter19_ex14_Graph.h"
#include "chapter19_ex14_wumpus.h"

namespace Graph_lib {;

//------------------------------------------------------------------------------

struct Simple_window : Graph_lib::Window {
    Simple_window(Point xy, int w, int h, const string& title);

    bool wait_for_button(); // simple event loop

private:
    Button next_button;     // the "next" button
    bool button_pushed;     // implementation detail

    static void cb_next(Address, Address); // callback for next_button
    void next();            // action to be done when next_button is pressed

};

//------------------------------------------------------------------------------

struct Quit_window : Graph_lib::Window {
    Quit_window(Point xy, int w, int h, const string& title);
protected:
    Button quit_button;
private:
    virtual void quit() { hide(); }
    static void cb_qpushed(Address, Address pw) { reference_to<Quit_window>(pw).quit(); }
};

//------------------------------------------------------------------------------

struct Wumpus_window : Quit_window {
    Wumpus_window();
private:
    // widgets
    Multiline_out_box output;
    In_box input;
    Button ok_button;   // TODO (Benjamin#1#): Add keyboard binding to enter key
    // TODO (Benjamin#1#): Add instructions button

    // actions invoked by callbacks
    void ok_pressed();

    // other functions
    void get_s_or_m();      // get 's' or 'm' from input
    void move_player();     // move player to other room (with consequences)
    void get_n_of_rooms();  // get # of rooms for arrow route
    void fire_arrow();      // get route and fire arrow
    void restart();         // get 'y' or 'n' and restart/quit

    // callbacks
    static void cb_okpushed(Address, Address pw) { reference_to<Wumpus_window>(pw).ok_pressed(); }

    // Wumpus functionality
    Wumpus::Wumpus_engine* we;
    void reset_wumpus_engine(); // create new cave
};

//------------------------------------------------------------------------------

} // of namespace Graph_lib

#endif // SIMPLE_WINDOW_GUARD
