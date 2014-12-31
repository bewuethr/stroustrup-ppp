//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "chapter21_ex11_GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "chapter21_ex11_Graph.h"
#include "chapter21_ex11_Order.h"
#include "chapter21_ex14_tq.h"

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

struct Text_query_window : Quit_window {
    Text_query_window();
private:
    // widgets
    Multiline_out_box ob_list;  // where words will be listed
    In_box ib_fname;            // file name
    Button load_button;         // load file
    In_box ib_word;             // word to look for
    Button word_count_button;   // get count for word in ib_word
    In_box ib_char;             // first character to look for
    Button first_char_button;   // get words starting character from ib_char
    In_box ib_length;           // length of word
    Button length_button;       // get words of length in ib_length
    Button most_freq_button;    // get most frequent word
    Button longest_button;      // get longest word
    Button shortest_button;     // get shortest word

    // other functions$
    bool file_loaded();

    // actions invoked by callbacks
    void load_file();
    void get_n_occurrences();
    void get_start_with();
    void get_has_length();
    void get_most_frequent();
    void get_longest();
    void get_shortest();

    // callbacks
    static void cb_loadpushed(Address, Address pw) { reference_to<Text_query_window>(pw).load_file(); }
    static void cb_countpushed(Address, Address pw) { reference_to<Text_query_window>(pw).get_n_occurrences(); }
    static void cb_firstchpushed(Address, Address pw) { reference_to<Text_query_window>(pw).get_start_with(); }
    static void cb_lengthpushed(Address, Address pw) { reference_to<Text_query_window>(pw).get_has_length(); }
    static void cb_freqpushed(Address, Address pw) { reference_to<Text_query_window>(pw).get_most_frequent(); }
    static void cb_longpushed(Address, Address pw) { reference_to<Text_query_window>(pw).get_longest(); }
    static void cb_shortpushed(Address, Address pw) { reference_to<Text_query_window>(pw).get_shortest(); }

    // data members
    string fname;           // input file name
    map<string,int> msi;    // map with words and word count
};

//------------------------------------------------------------------------------

} // of namespace Graph_lib

#endif // SIMPLE_WINDOW_GUARD
