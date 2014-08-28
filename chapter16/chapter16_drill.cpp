// Chapter 16, drill
// GUI example: line drawing program

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title);
private:
    // data
    Open_polyline lines;

    // widgets
    Button next_button;
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button cmenu_button;
    Menu style_menu;
    Button smenu_button;

    void change(Color c) { lines.set_color(c); }
    void style_change(Line_style l) { lines.set_style(l); }

    void show_cmenu();  // and hide style menu
    void hide_cmenu();  // and hide style menu
    void hide_smenu() { style_menu.hide(); smenu_button.show(); }

    // actions invoked by callbacks
    void red_pressed() { change(Color::red); hide_cmenu(); }
    void blue_pressed() { change(Color::blue); hide_cmenu(); }
    void black_pressed() { change(Color::black); hide_cmenu(); }
    void cmenu_pressed() { cmenu_button.hide(); show_cmenu(); }
    void solid_pressed() { style_change(Line_style(Line_style::solid)); hide_smenu(); }
    void dash_pressed() { style_change(Line_style(Line_style::dash)); hide_smenu(); }
    void dot_pressed() { style_change(Line_style(Line_style::dot)); hide_smenu(); }
    void smenu_pressed() { smenu_button.hide(); style_menu.show(); }
    void next();
    void quit();

    // callback functions
    static void cb_red(Address,Address);
    static void cb_blue(Address,Address);
    static void cb_black(Address,Address);
    static void cb_cmenu(Address,Address);
    static void cb_solid(Address,Address);
    static void cb_dash(Address,Address);
    static void cb_dot(Address,Address);
    static void cb_smenu(Address,Address);
    static void cb_next(Address,Address);
    static void cb_quit(Address,Address);
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    next_button(Point(x_max()-150,0),70,20,"Next point",cb_next),
    quit_button(Point(x_max()-70,0),70,20,"Quit",cb_quit),
    next_x(Point(x_max()-310,0),50,20,"next x:"),
    next_y(Point(x_max()-210,0),50,20,"next y:"),
    xy_out(Point(100,0),100,20,"current (x,y):"),
    color_menu(Point(x_max()-70,30),70,20,Menu::vertical,"color"),
    cmenu_button(Point(x_max()-80,30),80,20,"color menu",cb_cmenu),
    style_menu(Point(x_max()-70,60),70,20,Menu::vertical,"style"),
    smenu_button(Point(x_max()-80,60),80,20,"style menu",cb_smenu)
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    color_menu.attach(new Button(Point(0,0),0,0,"red",cb_red));
    color_menu.attach(new Button(Point(0,0),0,0,"blue",cb_blue));
    color_menu.attach(new Button(Point(0,0),0,0,"black",cb_black));
    attach(color_menu);
    color_menu.hide();
    attach(cmenu_button);
    style_menu.attach(new Button(Point(0,0),0,0,"solid",cb_solid));
    style_menu.attach(new Button(Point(0,0),0,0,"dashed",cb_dash));
    style_menu.attach(new Button(Point(0,0),0,0,"dotted",cb_dot));
    attach(style_menu);
    style_menu.hide();
    attach(smenu_button);
    attach(lines);
}

void Lines_window::show_cmenu()
{
    int dy = (color_menu.selection.size()-1)*20;
    smenu_button.move(0,dy);
    for (int i = 0; i<style_menu.selection.size(); ++i)
        style_menu.selection[i].move(0,dy);
    hide_smenu();
    color_menu.show();
}

void Lines_window::hide_cmenu()
{
    color_menu.hide();
    cmenu_button.show();
    int dy = -(color_menu.selection.size()-1)*20;
    smenu_button.move(0,dy);
    for (int i = 0; i<style_menu.selection.size(); ++i)
        style_menu.selection[i].move(0,dy);
    hide_smenu();
}

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_cmenu(Address, Address pw)
{
    reference_to<Lines_window>(pw).cmenu_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_smenu(Address, Address pw)
{
    reference_to<Lines_window>(pw).smenu_pressed();
}

void Lines_window::cb_quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit();
}

void Lines_window::quit()
{
    hide(); // FLTK idiom to delete window
}

void Lines_window::cb_next(Address, Address pw)
{
    reference_to<Lines_window>(pw).next();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point(x,y));

    // update current position readout:
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

int main()
try {
    Lines_window win(Point(100,100),600,400,"lines");
    return gui_main();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
