//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "chapter22_GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "chapter22_Graph.h"

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

} // of namespace Graph_lib

#endif // SIMPLE_WINDOW_GUARD
