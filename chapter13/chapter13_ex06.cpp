// Chapter 13, exercise 06: Draw a diagram like in 12.6, add Textbox for
// rectangle with text label

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Textbox tb_win(Point(100,50),70,"Window");
    tb_win.set_fill_color(Color::dark_green);
    tb_win.label.set_font(Font::helvetica_bold);
    win.attach(tb_win);

    Textbox tb_s_win(Point(70,135),130,"Simple_window");
    tb_s_win.set_fill_color(Color::dark_green);
    tb_s_win.label.set_font(Font::helvetica_bold);
    win.attach(tb_s_win);

    Arrow a1(n(tb_s_win),s(tb_win));
    win.attach(a1);

    Textbox tb_ls(Point(200,50),85,"Line_style");
    tb_ls.set_fill_color(Color::dark_green);
    tb_ls.label.set_font(Font::helvetica_bold);
    win.attach(tb_ls);

    Textbox tb_col(Point(315,50),55,"Color");
    tb_col.set_fill_color(Color::dark_green);
    tb_col.label.set_font(Font::helvetica_bold);
    win.attach(tb_col);

    Textbox tb_pt(Point(340,135),52,"Point");
    tb_pt.set_fill_color(Color::dark_green);
    tb_pt.label.set_font(Font::helvetica_bold);
    win.attach(tb_pt);

    Textbox tb_shp(Point(240,120),58,"Shape");
    tb_shp.set_fill_color(Color::dark_green);
    tb_shp.label.set_font(Font::helvetica_bold);
    win.attach(tb_shp);

    Textbox tb_ln(Point(50,210),50,"Line");
    tb_ln.set_fill_color(Color::dark_green);
    tb_ln.label.set_font(Font::helvetica_bold);
    win.attach(tb_ln);

    Textbox tb_lns(Point(110,210),50,"Lines");
    tb_lns.set_fill_color(Color::dark_green);
    tb_lns.label.set_font(Font::helvetica_bold);
    win.attach(tb_lns);

    Textbox tb_plg(Point(170,210),70,"Polygon");
    tb_plg.set_fill_color(Color::dark_green);
    tb_plg.label.set_font(Font::helvetica_bold);
    win.attach(tb_plg);

    Textbox tb_ax(Point(250,210),40,"Axis");
    tb_ax.set_fill_color(Color::dark_green);
    tb_ax.label.set_font(Font::helvetica_bold);
    win.attach(tb_ax);

    Textbox tb_rect(Point(300,210),85,"Rectangle");
    tb_rect.set_fill_color(Color::dark_green);
    tb_rect.label.set_font(Font::helvetica_bold);
    win.attach(tb_rect);

    Textbox tb_txt(Point(395,210),45,"Text");
    tb_txt.set_fill_color(Color::dark_green);
    tb_txt.label.set_font(Font::helvetica_bold);
    win.attach(tb_txt);

    Textbox tb_img(Point(450,210),55,"Image");
    tb_img.set_fill_color(Color::dark_green);
    tb_img.label.set_font(Font::helvetica_bold);
    win.attach(tb_img);

    Arrow a_ln(n(tb_ln),sw(tb_shp));
    win.attach(a_ln);
    Arrow a_lns(n(tb_lns),Point(sw(tb_shp).x+10,sw(tb_shp).y));
    win.attach(a_lns);
    Arrow a_plg(n(tb_plg),Point(sw(tb_shp).x+20,sw(tb_shp).y));
    win.attach(a_plg);
    Arrow a_ax(n(tb_ax),s(tb_shp));
    win.attach(a_ax);
    Arrow a_rect(n(tb_rect),Point(se(tb_shp).x-20,se(tb_shp).y));
    win.attach(a_rect);
    Arrow a_txt(n(tb_txt),Point(se(tb_shp).x-10,se(tb_shp).y));
    win.attach(a_txt);
    Arrow a_img(n(tb_img),se(tb_shp));
    win.attach(a_img);

    win.wait_for_button();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
