
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "../chapter16/chapter16_ex09_calc.h"    // calculator facilities

using namespace Graph_lib;

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

struct My_window : Simple_window {
    My_window(Point xy, int w, int h, const string& title);
private:
    Button quit_button;

    static void cb_quit(Address, Address pw) { reference_to<My_window>(pw).quit(); }
    void quit() { hide(); }
};

//------------------------------------------------------------------------------

struct Button_window : My_window {
    Button_window(Point xy, int w, int h, const string& title);
private:
    // widgets
    Menu menu1;
    Menu menu2;
    Menu menu3;
    Menu menu4;
    Out_box xy_out;

    // actions invoked by callback: relabel button, print coordinates
    void reset_labels();    // helper function
    void action(Button& b);
    void action11() { action(menu1.selection[0]); }
    void action12() { action(menu1.selection[1]); }
    void action13() { action(menu1.selection[2]); }
    void action14() { action(menu1.selection[3]); }
    void action21() { action(menu2.selection[0]); }
    void action22() { action(menu2.selection[1]); }
    void action23() { action(menu2.selection[2]); }
    void action24() { action(menu2.selection[3]); }
    void action31() { action(menu3.selection[0]); }
    void action32() { action(menu3.selection[1]); }
    void action33() { action(menu3.selection[2]); }
    void action34() { action(menu3.selection[3]); }
    void action41() { action(menu4.selection[0]); }
    void action42() { action(menu4.selection[1]); }
    void action43() { action(menu4.selection[2]); }
    void action44() { action(menu4.selection[3]); }

    // callback functions
    static void cb_action11(Address, Address pw) { reference_to<Button_window>(pw).action11(); }
    static void cb_action12(Address, Address pw) { reference_to<Button_window>(pw).action12(); }
    static void cb_action13(Address, Address pw) { reference_to<Button_window>(pw).action13(); }
    static void cb_action14(Address, Address pw) { reference_to<Button_window>(pw).action14(); }
    static void cb_action21(Address, Address pw) { reference_to<Button_window>(pw).action21(); }
    static void cb_action22(Address, Address pw) { reference_to<Button_window>(pw).action22(); }
    static void cb_action23(Address, Address pw) { reference_to<Button_window>(pw).action23(); }
    static void cb_action24(Address, Address pw) { reference_to<Button_window>(pw).action24(); }
    static void cb_action31(Address, Address pw) { reference_to<Button_window>(pw).action31(); }
    static void cb_action32(Address, Address pw) { reference_to<Button_window>(pw).action32(); }
    static void cb_action33(Address, Address pw) { reference_to<Button_window>(pw).action33(); }
    static void cb_action34(Address, Address pw) { reference_to<Button_window>(pw).action34(); }
    static void cb_action41(Address, Address pw) { reference_to<Button_window>(pw).action41(); }
    static void cb_action42(Address, Address pw) { reference_to<Button_window>(pw).action42(); }
    static void cb_action43(Address, Address pw) { reference_to<Button_window>(pw).action43(); }
    static void cb_action44(Address, Address pw) { reference_to<Button_window>(pw).action44(); }
};

//------------------------------------------------------------------------------

struct Imagebutton_window : Graph_lib::Window {
        Imagebutton_window(Point xy, int w, int h, const string& title);
private:
    Button quit_button;
    Button image_button;
    Image button_image;

    static void cb_quit(Address, Address pw) { reference_to<Imagebutton_window>(pw).quit(); }
    static void cb_ibpushed(Address, Address pw) { reference_to<Imagebutton_window>(pw).move(); }

    void quit() { hide(); }
    void move();
};

//------------------------------------------------------------------------------

struct Shmenu_window : Graph_lib::Window {
    Shmenu_window(Point xy, int w, int h, const string& title);
protected:
    // data
    int x;
    int y;
    Vector_ref<Shape> shapes;
    void get_coordinates();
private:
    // widgets
    Button quit_button;
    Menu shapes_menu;
    In_box x_in;
    In_box y_in;

    // actions invoked by callbacks
    void quit() { hide(); }
    void draw_circle();
    void draw_square();
    void draw_triangle();
    void draw_hexagon();

    // callback functions
    static void cb_qpushed(Address, Address pw) { reference_to<Shmenu_window>(pw).quit(); }
    static void cb_circle(Address, Address pw) { reference_to<Shmenu_window>(pw).draw_circle(); }
    static void cb_square(Address, Address pw) { reference_to<Shmenu_window>(pw).draw_square(); }
    static void cb_triangle(Address, Address pw) { reference_to<Shmenu_window>(pw).draw_triangle(); }
    static void cb_hexagon(Address, Address pw) { reference_to<Shmenu_window>(pw).draw_hexagon(); }
};

//------------------------------------------------------------------------------

struct Mvshape_window : Shmenu_window {
    Mvshape_window(Point xy, int w, int h, const string& title);
private:
    Button next_button;
    void next();    // move newest shape to given coordinates
    static void cb_npushed(Address, Address pw) { reference_to<Mvshape_window>(pw).next(); }
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

struct Currency_window : Quit_window {
    Currency_window(Point xy, int w, int h, const string& title);
private:
    //data
    enum Currency { CAD, CHF, KYD };
    Currency from_cur;
    Currency to_cur;
    // conversion rates; element (i,j) converts one unit of currency i to currency j
    vector<vector<double> > rates;
    vector<string> cur_labels;

    // initialisation: read conversion rates from text file
    void get_conversion_rates();

    // widgets and text
    Button calc_button;
    In_box amount_in;
    Text from_cur_text;
    Menu from_cur_menu;
    Button from_cur_mbutton;
    Text equals;
    Out_box amount_out;
    Text to_cur_text;
    Menu to_cur_menu;
    Button to_cur_mbutton;

    void hide_from_menu() { from_cur_menu.hide(); from_cur_mbutton.show(); }
    void hide_to_menu() { to_cur_menu.hide(); to_cur_mbutton.show(); }

    // actions invoked by callbacks
    void calculate_pressed();
    void from_cur_pressed(int n);
    void from_mbutton_pressed() { from_cur_mbutton.hide(); from_cur_menu.show(); }
    void to_cur_pressed(int n);
    void to_mbutton_pressed() { to_cur_mbutton.hide(); to_cur_menu.show(); }

    // callback functions
    static void cb_calc(Address, Address pw) { reference_to<Currency_window>(pw).calculate_pressed(); }
    static void cb_from_cur0(Address, Address pw) { reference_to<Currency_window>(pw).from_cur_pressed(0); }
    static void cb_from_cur1(Address, Address pw) { reference_to<Currency_window>(pw).from_cur_pressed(1); }
    static void cb_from_cur2(Address, Address pw) { reference_to<Currency_window>(pw).from_cur_pressed(2); }
    static void cb_from_mbutton(Address, Address pw) { reference_to<Currency_window>(pw).from_mbutton_pressed(); }
    static void cb_to_cur0(Address, Address pw) { reference_to<Currency_window>(pw).to_cur_pressed(0); }
    static void cb_to_cur1(Address, Address pw) { reference_to<Currency_window>(pw).to_cur_pressed(1); }
    static void cb_to_cur2(Address, Address pw) { reference_to<Currency_window>(pw).to_cur_pressed(2); }
    static void cb_to_mbutton(Address, Address pw) { reference_to<Currency_window>(pw).to_mbutton_pressed(); }
};

//------------------------------------------------------------------------------

struct Calc_window : Quit_window {
    Calc_window(Point xy, int w, int h, const string& title);
private:
    // widgets
    Button help_button;
    Button calc_button;
    In_box input;
    Out_box output;

    // actions invoked by callbacks
    void help_pressed();
    void calc_pressed();

    // callbacks
    static void cb_help_button(Address, Address pw) { reference_to<Calc_window>(pw).help_pressed(); }
    static void cb_calc_button(Address, Address pw) { reference_to<Calc_window>(pw).calc_pressed(); }

    // the actual calculator
    Calc_lib::Calculator calc;
};

//------------------------------------------------------------------------------

struct Fgraph_window : Quit_window {
    Fgraph_window(Point xy, int w, int h, const string& title);
private:
    // widgets
    Button draw_button;
    Out_box message_box;
    Menu fct_menu;
    Button fct_menu_button;
    In_box input_r1;
    In_box input_r2;
    In_box input_count;
    In_box input_xscale;
    In_box input_yscale;

    // graphical objects
    Axis x_axis;
    Axis y_axis;
    Flex_function fl_funct;

    void hide_fct_menu() { fct_menu.hide(); fct_menu_button.show(); }

    // actions invoked by callbacks;
    void draw_pressed();
    void fct_mbutton_pressed() { fct_menu_button.hide(); fct_menu.show(); }
    void fct_pressed(Fct f) { hide_fct_menu(); fct_pointer = f; }

    // callbacks
    static void cb_draw_button(Address, Address pw) { reference_to<Fgraph_window>(pw).draw_pressed(); }
    static void cb_sin_button(Address, Address pw) { reference_to<Fgraph_window>(pw).fct_pressed(sin); }
    static void cb_cos_button(Address, Address pw) { reference_to<Fgraph_window>(pw).fct_pressed(cos); }
    static void cb_log_button(Address, Address pw) { reference_to<Fgraph_window>(pw).fct_pressed(log); }
    static void cb_exp_button(Address, Address pw) { reference_to<Fgraph_window>(pw).fct_pressed(exp); }
    static void cb_fct_mbutton(Address, Address pw) { reference_to<Fgraph_window>(pw).fct_mbutton_pressed(); }

    // store function pointer
    Fct* fct_pointer;
};

//------------------------------------------------------------------------------

#endif // SIMPLE_WINDOW_GUARD
