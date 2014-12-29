//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "chapter21_ex11_GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "chapter21_ex11_Graph.h"
#include "chapter21_ex11_Order.h"

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

struct Order_enter_window : Quit_window {
    Order_enter_window();
private:
    // widgets
    In_box ib_name;
    In_box ib_address;
    In_box ib_date;
    Text purch_label;
    In_box ib_pname1;
    In_box ib_price1;
    In_box ib_count1;
    In_box ib_pname2;
    In_box ib_price2;
    In_box ib_count2;
    In_box ib_pname3;
    In_box ib_price3;
    In_box ib_count3;
    In_box ib_fname;
    Button enter_button;
    Text status;

    // actions invoked by callbacks
    void enter_pressed();

    // other functions
    double string_to_double(string s);
    string gui_to_file();

    // callbacks
    static void cb_enterpushed(Address, Address pw) { reference_to<Order_enter_window>(pw).enter_pressed(); }
};

//------------------------------------------------------------------------------

struct File_query_window : Quit_window {
    File_query_window();
private:
    // widgets
    Multiline_out_box ob_list;  // where orders will be listed
    In_box ib_fname;            // file name
    In_box ib_cname;            // customer name
    Button list_button;         // list the orders
    Button value_button;        // display the total value
    Out_box ob_value;           // where value will be displayed
    Text status;                // status and error messages

    // other functions
    int fill_vector();

    // actions invoked by callbacks
    void list_pressed();
    void value_pressed();

    // callbacks
    static void cb_listpushed(Address, Address pw) { reference_to<File_query_window>(pw).list_pressed(); }
    static void cb_valuepushed(Address, Address pw) { reference_to<File_query_window>(pw).value_pressed(); }

    // data members
    string fname;   // input file name
    string cname;   // customer name for filter
    vector<Order::Order> vo;
};

//------------------------------------------------------------------------------

} // of namespace Graph_lib

#endif // SIMPLE_WINDOW_GUARD
