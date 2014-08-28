
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"

//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
    button_pushed(false)
{
    attach(next_button);
}

//------------------------------------------------------------------------------

bool Simple_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
    show();
    button_pushed = false;
#if 1
    // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

void Simple_window::cb_next(Address, Address pw)
// call Simple_window::next() for the window located at pw
{
    reference_to<Simple_window>(pw).next();
}

//------------------------------------------------------------------------------

void Simple_window::next()
{
    button_pushed = true;
    hide();
}

//------------------------------------------------------------------------------

My_window::My_window(Point xy, int w, int h, const string& title)
    :Simple_window(xy,w,h,title),
    quit_button(Point(x_max()-70,30),70,20,"Quit",cb_quit)
{
    attach(quit_button);
}

//------------------------------------------------------------------------------

Button_window::Button_window(Point xy, int w, int h, const string& title)
    :My_window(xy,w,h,title),
    menu1(Point(0,0),100,100,Menu::vertical,"menu1"),
    menu2(Point(100,0),100,100,Menu::vertical,"menu2"),
    menu3(Point(200,0),100,100,Menu::vertical,"menu3"),
    menu4(Point(300,0),100,100,Menu::vertical,"menu4"),
    xy_out(Point(x_max()-70,60),70,20,"(x,y)")
{
    menu1.attach(new Button(Point(0,0),0,0,"1-1",cb_action11));
    menu1.attach(new Button(Point(0,0),0,0,"1-2",cb_action12));
    menu1.attach(new Button(Point(0,0),0,0,"1-3",cb_action13));
    menu1.attach(new Button(Point(0,0),0,0,"1-4",cb_action14));
    attach(menu1);
    menu2.attach(new Button(Point(0,0),0,0,"2-1",cb_action21));
    menu2.attach(new Button(Point(0,0),0,0,"2-2",cb_action22));
    menu2.attach(new Button(Point(0,0),0,0,"2-3",cb_action23));
    menu2.attach(new Button(Point(0,0),0,0,"2-4",cb_action24));
    attach(menu2);
    menu3.attach(new Button(Point(0,0),0,0,"3-1",cb_action31));
    menu3.attach(new Button(Point(0,0),0,0,"3-2",cb_action32));
    menu3.attach(new Button(Point(0,0),0,0,"3-3",cb_action33));
    menu3.attach(new Button(Point(0,0),0,0,"3-4",cb_action34));
    attach(menu3);
    menu4.attach(new Button(Point(0,0),0,0,"4-1",cb_action41));
    menu4.attach(new Button(Point(0,0),0,0,"4-2",cb_action42));
    menu4.attach(new Button(Point(0,0),0,0,"4-3",cb_action43));
    menu4.attach(new Button(Point(0,0),0,0,"4-4",cb_action44));
    attach(menu4);
    attach(xy_out);
    xy_out.put("no point");
}

//------------------------------------------------------------------------------

void Button_window::reset_labels()
{
    for (int i = 0; i<4; ++i) {
        menu1.selection[i].label = "1-" + to_string(i+1);
        menu2.selection[i].label = "2-" + to_string(i+1);
        menu3.selection[i].label = "3-" + to_string(i+1);
        menu4.selection[i].label = "4-" + to_string(i+1);
    }
    redraw();
}

//------------------------------------------------------------------------------

void Button_window::action(Button& b)
{
    reset_labels();
    b.label = "CLICKED";
    ostringstream os;
    os << '(' << b.loc.x << ',' << b.loc.y << ')';
    xy_out.put(os.str());
}

//------------------------------------------------------------------------------

int rint(int low, int high)
{
    return low + rand()%(high-low);
}

//------------------------------------------------------------------------------

Imagebutton_window::Imagebutton_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    quit_button(Point(x_max()-70,0),70,20,"Quit",cb_quit),
    image_button(Point(rint(0,x_max()-100),rint(0,y_max()-100)),100,100,"",cb_ibpushed),
    button_image(image_button.loc,"pics_and_txt/snow_cpp.gif")
{
    attach(quit_button);
    attach(image_button);
    button_image.set_mask(Point(110,70),100,100);
    attach(button_image);
}

//------------------------------------------------------------------------------

void Imagebutton_window::move()
{
    int dx = rint(0,x_max()-100) - image_button.loc.x;
    int dy = rint(0,y_max()-100) - image_button.loc.y;
    image_button.move(dx,dy);
    button_image.move(dx,dy);
}

//------------------------------------------------------------------------------

Shmenu_window::Shmenu_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    quit_button(Point(x_max()-70,0),70,20,"Quit",cb_qpushed),
    shapes_menu(Point(x_max()-70,30),70,20,Menu::vertical,"shapes"),
    x_in(Point(x_max()-70,120),70,20,"x:"),
    y_in(Point(x_max()-70,140),70,20,"y:"),
    x(0),
    y(0)
{
    attach(quit_button);
    shapes_menu.attach(new Button(Point(),0,0,"Circle",cb_circle));
    shapes_menu.attach(new Button(Point(),0,0,"Square",cb_square));
    shapes_menu.attach(new Button(Point(),0,0,"Triangle",cb_triangle));
    shapes_menu.attach(new Button(Point(),0,0,"Hexagon",cb_hexagon));
    attach(shapes_menu);
    attach(x_in);
    attach(y_in);
}

//------------------------------------------------------------------------------

void Shmenu_window::get_coordinates()
{
    x = x_in.get_int();
    if (x==-999999) error("x-coordinate invalid");
    y = y_in.get_int();
    if (y==-999999) error("y-coordinate invalid");
}

//------------------------------------------------------------------------------

void Shmenu_window::draw_circle()
{
    get_coordinates();
    shapes.push_back(new Circle(Point(x,y),100));
    attach(shapes[shapes.size()-1]);
    redraw();
}

//------------------------------------------------------------------------------

void Shmenu_window::draw_square()
{
    get_coordinates();
    shapes.push_back(new Regular_polygon(Point(x,y),4,100));
    attach(shapes[shapes.size()-1]);
    redraw();
}

//------------------------------------------------------------------------------

void Shmenu_window::draw_triangle()
{
    get_coordinates();
    shapes.push_back(new Regular_polygon(Point(x,y),3,100));
    attach(shapes[shapes.size()-1]);
    redraw();
}

//------------------------------------------------------------------------------

void Shmenu_window::draw_hexagon()
{
    get_coordinates();
    shapes.push_back(new Regular_polygon(Point(x,y),6,100));
    attach(shapes[shapes.size()-1]);
    redraw();
}

//------------------------------------------------------------------------------

Mvshape_window::Mvshape_window(Point xy,int w,int h,const string& title)
    :Shmenu_window(xy,w,h,title),
    next_button(Point(x_max()-70,170),70,20,"Next",cb_npushed)
{
    attach(next_button);
}

//------------------------------------------------------------------------------

void Mvshape_window::next()
{
    if (shapes.size()==0) error("No shapes available");
    get_coordinates();
    int dx = x - shapes[shapes.size()-1].point(0).x;
    int dy = y - shapes[shapes.size()-1].point(0).y;
    shapes[shapes.size()-1].move(dx,dy);
    redraw();
}

//------------------------------------------------------------------------------

Quit_window::Quit_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    quit_button(Point(x_max()-70,0),70,20,"Quit",cb_qpushed)
{
    attach(quit_button);
}

//------------------------------------------------------------------------------

Currency_window::Currency_window(Point xy, int w, int h, const string& title)
    :Quit_window(xy,w,h,title),
    calc_button(Point(x_max()-140,0),70,20,"Calculate",cb_calc),
    amount_in(Point(15,35),70,20,""),
    from_cur_text(Point(95,52),"CAD"),
    from_cur_menu(Point(95,60),70,20,Menu::vertical,"Change"),
    from_cur_mbutton(Point(95,60),70,20,"Change",cb_from_mbutton),
    equals(Point(175,52),"equals"),
    amount_out(Point(250,35),70,20,""),
    to_cur_text(Point(325,52),"CHF"),
    to_cur_menu(Point(325,60),70,20,Menu::vertical,"Change"),
    to_cur_mbutton(Point(325,60),70,20,"Change",cb_to_mbutton),
    from_cur(CAD),
    to_cur(CHF)
{
    // Build GUI
    attach(calc_button);
    attach(amount_in);
    attach(from_cur_text);
    from_cur_menu.attach(new Button(Point(0,0),0,0,"CAD",cb_from_cur0));
    from_cur_menu.attach(new Button(Point(0,0),0,0,"CHF",cb_from_cur1));
    from_cur_menu.attach(new Button(Point(0,0),0,0,"KYD",cb_from_cur2));
    attach(from_cur_menu);
    from_cur_menu.hide();
    attach(from_cur_mbutton);
    attach(equals);
    attach(amount_out);
    attach(to_cur_text);
    to_cur_menu.attach(new Button(Point(0,0),0,0,"CAD",cb_to_cur0));
    to_cur_menu.attach(new Button(Point(0,0),0,0,"CHF",cb_to_cur1));
    to_cur_menu.attach(new Button(Point(0,0),0,0,"KYD",cb_to_cur2));
    attach(to_cur_menu);
    to_cur_menu.hide();
    attach(to_cur_mbutton);

    // Add currency names
    cur_labels.push_back("CAD");
    cur_labels.push_back("CHF");
    cur_labels.push_back("KYD");

    // Read data from text file
    get_conversion_rates();
}

//------------------------------------------------------------------------------

void Currency_window::get_conversion_rates()
{
    const string fname = "pics_and_txt/chapter16_ex08_in.txt";
    ifstream ifs(fname.c_str());
    if (!ifs) error("can't open ",fname);

    double rate;
    char c;
    while (ifs>>c && !isdigit(c));  // discard until first digit appears
    ifs.unget();
    for (int i = 0; i<3; ++i) {
        vector<double> dummy_vec;
        rates.push_back(dummy_vec);
        for (int j = 0; j<3; ++j) {
            ifs >> rate;
            if (!ifs) error("problem reading numbers from ",fname);
            rates[i].push_back(rate);
        }
    }
}

//------------------------------------------------------------------------------

void Currency_window::calculate_pressed()
{
    // get string from amount_in, check if empty or not a number
    string s_in = amount_in.get_string();
    if (s_in=="") return;   // do nothing
    istringstream iss(s_in);
    double in_val;
    iss >> in_val;
    if (!iss) return;    // do nothing, don't complain, shut up

    double out_val = in_val * rates[from_cur][to_cur];
    ostringstream oss;
    oss << fixed << setprecision(2) << out_val;
    amount_out.put(oss.str());
}

//------------------------------------------------------------------------------

void Currency_window::from_cur_pressed(int n) {
    hide_from_menu();
    from_cur = Currency(n);
    from_cur_text.set_label(cur_labels[n]);
    calculate_pressed();
}

//------------------------------------------------------------------------------

void Currency_window::to_cur_pressed(int n) {
    hide_to_menu();
    to_cur = Currency(n);
    to_cur_text.set_label(cur_labels[n]);
    calculate_pressed();
}

//------------------------------------------------------------------------------

Calc_window::Calc_window(Point xy, int w, int h, const string& title)
    :Quit_window(xy,w,h,title),
    help_button(Point(x_max()-210,0),70,20,"Help",cb_help_button),
    calc_button(Point(x_max()-140,0),70,20,"Calculate",cb_calc_button),
    input(Point(53,30),x_max()-68,20,"Input:"),
    output(Point(53,60),x_max()-68,20,"Output:")
{
    attach(help_button);
    attach(calc_button);
    attach(input);
    attach(output);
}

//------------------------------------------------------------------------------

// write help to output
void Calc_window::help_pressed()
{
    output.put(calc.print_help());
}

//------------------------------------------------------------------------------

// take string from input, feed to calculator, print result to output
void Calc_window::calc_pressed()
{
    string result = calc.calculate(input.get_string());
    output.put(result);
}

//------------------------------------------------------------------------------

Fgraph_window::Fgraph_window(Point xy, int w, int h, const string& title)
    :Quit_window(xy,w,h,title),
    draw_button(Point(x_max()-140,0),70,20,"Draw",cb_draw_button),
    message_box(Point(15,15),x_max()-170,20,""),
    fct_menu(Point(x_max()-85,210),70,20,Menu::vertical,"Function"),
    fct_menu_button(Point(x_max()-85,210),70,20,"Function",cb_fct_mbutton),
    input_r1(Point(x_max()-85,35),70,20,"r1:"),
    input_r2(Point(x_max()-85,70),70,20,"r2:"),
    input_count(Point(x_max()-85,105),70,20,"Count:"),
    input_xscale(Point(x_max()-85,140),70,20,"xscale:"),
    input_yscale(Point(x_max()-85,175),70,20,"yscale:"),
    x_axis(Axis::x,Point(15,(y_max()-65)/2+50),x_max()-120,10,""),
    y_axis(Axis::y,Point(15,y_max()-15),y_max()-65,10,""),
    fl_funct(sin,0,10*pi,Point(15,(y_max()-65)/2+50)),
    fct_pointer(sin)
{
    attach(draw_button);
    attach(message_box);
    fct_menu.attach(new Button(Point(),0,0,"sin",cb_sin_button));
    fct_menu.attach(new Button(Point(),0,0,"cos",cb_cos_button));
    fct_menu.attach(new Button(Point(),0,0,"log",cb_log_button));
    fct_menu.attach(new Button(Point(),0,0,"exp",cb_exp_button));
    attach(fct_menu);
    fct_menu.hide();
    attach(fct_menu_button);
    attach(input_r1);
    attach(input_r2);
    attach(input_count);
    attach(input_xscale);
    attach(input_yscale);
    x_axis.label.set_color(Color::red);
    x_axis.label.move(-180,0);
    attach(x_axis);
    y_axis.label.set_color(Color::red);
    y_axis.label.move(30,20);
    attach(y_axis);
    fl_funct.set_color(Color::invisible);   // we don't want to see anything yet
    attach(fl_funct);
}

//------------------------------------------------------------------------------

double get_double(In_box& ib)
{
    string s;
    s = ib.get_string();
    if (s == "") error("No value in ",ib.label);
    istringstream iss(s);
    double d;
    iss >> d;
    if (!iss) error("Invalid value in ",ib.label);
    return d;
}

//------------------------------------------------------------------------------

int get_int(In_box& ib)
{
    int i = ib.get_int();
    if (i == -999999) error("Invalid value in ",ib.label);
    return i;
}

//------------------------------------------------------------------------------

void reset_label(int max, double scale, Axis& a, Axis::Orientation a_or)
{
    double notch = 0;
    int x = x_max();
    switch (a_or) {
    case Axis::x:
        notch = (max-115)/10.0/scale;
        break;
    case Axis::y:
        notch = (max-65)/10.0/scale;
        break;
    }
    ostringstream oss;
    oss << "1 notch = " << fixed << setprecision(2) << notch;
    a.label.set_label(oss.str());
}

//------------------------------------------------------------------------------

void Fgraph_window::draw_pressed()
try {
    // set range
    fl_funct.reset_range(get_double(input_r1),get_double(input_r2));

    // reset count
    fl_funct.reset_count(get_int(input_count));

    // reset xscale
    double xscale = get_double(input_xscale);
    fl_funct.reset_xscale(xscale);

    // reset axis label
    reset_label(x_max(),xscale,x_axis,Axis::x);

    // reset yscale
    double yscale = get_double(input_yscale);
    fl_funct.reset_yscale(yscale);

    // reset axis label
    reset_label(y_max(),yscale,y_axis,Axis::y);

    // set function
    fl_funct.reset_fct(fct_pointer);

    // clear message window
    message_box.put("");

    // finally, make function visible in case this was the first time
    fl_funct.set_color(Color::visible);
    fl_funct.set_color(Color::blue);
    redraw();
}
catch (exception& e) {
    message_box.put(e.what());
}

//------------------------------------------------------------------------------
