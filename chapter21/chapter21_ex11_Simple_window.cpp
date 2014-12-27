//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "chapter21_ex11_Simple_window.h"

namespace Graph_lib {;

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

Quit_window::Quit_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    quit_button(Point(x_max()-70,0),70,20,"Quit",cb_qpushed)
{
    attach(quit_button);
}

//------------------------------------------------------------------------------

Order_enter_window::Order_enter_window()
    :Quit_window(Point(400,200),800,320,"Order entry"),
    ib_name(Point(70,15),450,20,"Name"),
    ib_address(Point(70,55),450,20,"Address"),
    ib_date(Point(70,95),450,20,"Date"),
    purch_label(Point(20,160),"Purchases"),
    ib_pname1(Point(70,175),200,20,"Name"),
    ib_price1(Point(360,175),60,20,"Price"),
    ib_count1(Point(470,175),50,20,"Count"),
    ib_pname2(Point(70,215),200,20,"Name"),
    ib_price2(Point(360,215),60,20,"Price"),
    ib_count2(Point(470,215),50,20,"Count"),
    ib_pname3(Point(70,255),200,20,"Name"),
    ib_price3(Point(360,255),60,20,"Price"),
    ib_count3(Point(470,255),50,20,"Count"),
    ib_fname(Point(605,50),160,20,"File"),
    enter_button(Point(605,85),160,25,"Enter order",cb_enterpushed),
    status(Point(70,305),"")
{
    attach(ib_name);
    attach(ib_address);
    attach(ib_date);
    attach(purch_label);
    attach(ib_pname1);
    attach(ib_price1);
    attach(ib_count1);
    attach(ib_pname2);
    attach(ib_price2);
    attach(ib_count2);
    attach(ib_pname3);
    attach(ib_price3);
    attach(ib_count3);
    attach(ib_fname);
    attach(enter_button);
    attach(status);
}

//------------------------------------------------------------------------------

double Order_enter_window::string_to_double(string s)
{
    if (s=="") return -999999;
    istringstream iss(s);
    double d;
    iss >> d;
    if (!iss) return -999999;
    return d;
}

//------------------------------------------------------------------------------

string Order_enter_window::gui_to_file()
{
    status.set_color(Color::red);
    string name = ib_name.get_string();
    if (name=="") return string("Please enter customer name");
    string address = ib_address.get_string();
    if (address=="") return string("Please enter address");
    string date_string = ib_date.get_string();
    if (date_string=="") return string("Please enter date (dd.mm.yyyy)");
    istringstream iss_date(date_string);
    Order::Date date;
    iss_date >> date;
    if (!iss_date) return string("Date not in dd.mm.yyyy format");

    // Purchases
    vector<Order::Purchase> purchases;

    string pname1 = ib_pname1.get_string();
    if (pname1=="") return string("Enter name of first purchase");
    double price1 = string_to_double(ib_price1.get_string());
    if (price1==-999999) return string("Problem with price of first purchase");
    int count1 = ib_count1.get_int();
    if (count1==-999999) return string("Problem with count of first purchase");
    purchases.push_back(Order::Purchase(pname1,price1,count1));

    string pname2 = ib_pname2.get_string();
    if (pname2!="") {
        double price2 = string_to_double(ib_price2.get_string());
        if (price2==-999999) return string("Problem with price of second purchase");
        int count2 = ib_count2.get_int();
        if (count2==-999999) return string("Problem with count of second purchase");
        purchases.push_back(Order::Purchase(pname2,price2,count2));
    }

    string pname3 = ib_pname3.get_string();
    if (pname3!="") {
        double price3 = string_to_double(ib_price3.get_string());
        if (price3==-999999) return string("Problem with price of third purchase");
        int count3 = ib_count3.get_int();
        if (count3==-999999) return string("Problem with count of third purchase");
        purchases.push_back(Order::Purchase(pname3,price3,count3));
    }

    Order::Order order(name,address,date,purchases);

    string fname = ib_fname.get_string();
    if (fname=="") return string("Please enter file name");
    ofstream ofs(fname.c_str(),ios_base::app);
    if (!ofs) error("Problem with file ",fname);
    ofs << order << '\n';
    status.set_color(Color::black);
    return string("Appended order to " + fname);
}

//------------------------------------------------------------------------------

void Order_enter_window::enter_pressed()
{
    string s = gui_to_file();
    status.set_label(s);
    redraw();
}

//------------------------------------------------------------------------------

} // Graph_lib
