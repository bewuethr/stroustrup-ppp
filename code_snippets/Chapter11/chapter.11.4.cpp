
//
// This is example code from Chapter 11.4 "String streams" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double str_to_double(string s)
// if possible, convert characters in s to floating-point value
{
    istringstream is(s);    // make a stream so that we can read from s
    double d;
    is >> d;
    if (!is) error("double format error: ",s);
    return d;
}

//------------------------------------------------------------------------------


void test()
try
{
    double d1 = str_to_double("12.4");               // testing
    double d2 = str_to_double("1.34e-3");
    double d3 = str_to_double("twelve point three"); // will call error()
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
}

//------------------------------------------------------------------------------

struct Temperature 
{
    double temp;
    string unit;
};

//------------------------------------------------------------------------------

void my_code(string label, Temperature temp)
{
    // ...
    ostringstream os;    // stream for composing a message
    os << setw(8) << label << ": "
       << fixed << setprecision(5) << temp.temp << temp.unit;
    //someobject.display(Point(100,100), os.str().c_str());
    // ...
}

//------------------------------------------------------------------------------

int get_next_number() // get the number of a log file
{
    static int n = 0;
    return n;
}

//------------------------------------------------------------------------------

int main()
try
{
    test();
    int seq_no = get_next_number();       // get the number of a log file
    ostringstream name;
    name << "myfile" << seq_no;           // e.g., myfile17
    ofstream logfile(name.str().c_str()); // e.g., open myfile17
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
