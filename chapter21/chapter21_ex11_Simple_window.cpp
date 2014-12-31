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

File_query_window::File_query_window()
    :Quit_window(Point(395,50),810,800,"Order file query"),
    ob_list(Point(20,20),510,y_max()-40,""),
    ib_fname(Point(x_max()-170,40),150,20,"File name"),
    ib_cname(Point(x_max()-170,75),150,20,"Customer name"),
    list_button(Point(x_max()-260,110),110,20,"List orders",cb_listpushed),
    value_button(Point(x_max()-130,110),110,20,"Get total value",cb_valuepushed),
    ob_value(Point(x_max()-170,160),150,20,"Total value"),
    status(Point(x_max()-260,210),""),
    vo()
{
    attach(ob_list);
    ob_list.set_textsize(10);
    attach(ib_fname);
    attach(ib_cname);
    attach(list_button);
    attach(value_button);
    attach(ob_value);
    status.set_color(Color::red);
    attach(status);
}

//------------------------------------------------------------------------------

// return -1 in case of problem, 0 otherwise
int File_query_window::fill_vector()
{
    fname = ib_fname.get_string();
    if (!Order::file_check(fname)) {
        status.set_label("Please enter name of existing file");
        redraw();
        return -1;
    }
    cname = ib_cname.get_string();

    vo.clear();
    Order::read_orders_from_file(vo,fname);
}

//------------------------------------------------------------------------------

void File_query_window::list_pressed()
{
    int i = fill_vector();
    if (i==-1) return;
    string output;
    ostringstream oss;
    for (int i = 0; i<vo.size(); ++i) {
        if (cname=="" || cname==vo[i].name())
            oss << vo[i] << '\n';
    }
    ob_list.put(oss.str());
    status.set_label("");
    redraw();
}

//------------------------------------------------------------------------------

void File_query_window::value_pressed()
{
    int i = fill_vector();
    if (i==-1) return;
    double val_t = 0;
    for (int i = 0; i<vo.size(); ++i) {
        if (cname=="" || cname==vo[i].name()) {
            for (int j = 0; j<vo[i].n_purchases(); ++j)
            val_t += vo[i].purchase(j).count() * vo[i].purchase(j).unit_price();
        }
    }
    ostringstream oss;
    oss << val_t;
    ob_value.put(oss.str());
}

//------------------------------------------------------------------------------

Text_query_window::Text_query_window()
    :Quit_window(Point(395,50),810,800,"Text query"),
    ob_list(Point(20,20),510,y_max()-40,""),
    ib_fname(Point(x_max()-190,40),75,20,"File name"),
    load_button(Point(x_max()-95,40),75,20,"Load file",cb_loadpushed),
    ib_word(Point(x_max()-190,75),75,20,"Word"),
    word_count_button(Point(x_max()-95,75),75,20,"Get count",cb_countpushed),
    ib_char(Point(x_max()-190,110),75,20,"First letter"),
    first_char_button(Point(x_max()-95,110),75,20,"Get words",cb_firstchpushed),
    ib_length(Point(x_max()-190,145),75,20,"Word length"),
    length_button(Point(x_max()-95,145),75,20,"Get words",cb_lengthpushed),
    most_freq_button(Point(x_max()-190,180),170,20,"Get most frequent word",cb_freqpushed),
    longest_button(Point(x_max()-190,215),170,20,"Get longest word",cb_longpushed),
    shortest_button(Point(x_max()-190,250),170,20,"Get shortest word",cb_shortpushed),
    fname(),
    msi()
{
    attach(ob_list);
    attach(ib_fname);
    attach(load_button);
    attach(ib_word);
    attach(word_count_button);
    attach(ib_char);
    attach(first_char_button);
    attach(ib_length);
    attach(length_button);
    attach(most_freq_button);
    attach(longest_button);
    attach(shortest_button);
}

//------------------------------------------------------------------------------

bool Text_query_window::file_loaded()
{
    if (msi.size() == 0) {
        ob_list.put("No text loaded!");
        redraw();
        return false;
    }
    return true;
}


//------------------------------------------------------------------------------

void Text_query_window::load_file()
{
    fname = ib_fname.get_string();
    if (fname=="") {
        ob_list.put("File name is empty!");
        redraw();
        return;
    }

    // test if file exists
    ifstream ifs(fname.c_str());
    if (!ifs) {
        ob_list.put("File '" + fname + "' doesn't exist!");
        redraw();
        return;
    }

    // load file
    msi = Text_query::clean_txt(fname);
    ob_list.put("File '" + fname + "' loaded");
    redraw();
}

//------------------------------------------------------------------------------

void Text_query_window::get_n_occurrences()
{
    if (!file_loaded())
        return;
    string s = ib_word.get_string();
    if (s == "") {
        ob_list.put("No word entered!");
        redraw();
        return;
    }
    int n = Text_query::num_of_occurrences(s,msi);
    ostringstream oss;
    oss << "'" << s << "' occurs " << n << " time" << (n==1?"":"s");
    ob_list.put(oss.str());
    redraw();
}

//------------------------------------------------------------------------------

void Text_query_window::get_start_with()
{
    if (!file_loaded())
        return;
    string s = ib_char.get_string();
    if (s == "") {
        ob_list.put("No character entered!");
        redraw();
        return;
    }
    char ch = s.front();
    vector<string> vs = Text_query::start_with(ch,msi);
    ostringstream oss;
    oss << "Words starting with '" << ch << "':\n";
    for (int i = 0; i<vs.size(); ++i)
        oss << vs[i] << '\n';
    ob_list.put(oss.str());
    redraw();
}

//------------------------------------------------------------------------------

void Text_query_window::get_has_length()
{
    if (!file_loaded())
        return;
    int n = ib_length.get_int();
    if (n == -999999) {
        ob_list.put("No number entered!");
        redraw();
        return;
    }
    vector<string> vs = Text_query::has_length(n,msi);
    ostringstream oss;
    oss << "Words with " << n << " characters:\n";
    for (int i = 0; i<vs.size(); ++i)
        oss << vs[i] << '\n';
    ob_list.put(oss.str());
    redraw();
}

//------------------------------------------------------------------------------

void Text_query_window::get_most_frequent()
{
    if (!file_loaded())
        return;
    string s = Text_query::most_frequent(msi);
    ob_list.put("The most frequent word is '" + s + "'.");
    redraw();
}

//------------------------------------------------------------------------------

void Text_query_window::get_longest()
{
    if (!file_loaded())
        return;
    string s = Text_query::longest(msi);
    ob_list.put("The longest word is '" + s + "'.");
    redraw();
}

//------------------------------------------------------------------------------

void Text_query_window::get_shortest()
{
    if (!file_loaded())
        return;
    string s = Text_query::shortest(msi);
    ob_list.put("The shortest word is '" + s + "'.");
    redraw();
}

//------------------------------------------------------------------------------

} // Graph_lib
