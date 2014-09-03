
//
// This is example code from Chapter 10.11.2 "Reading structured values" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

const int not_a_reading = -7777;    // less than absolute zero
const int not_a_month = -1;

//------------------------------------------------------------------------------

struct Day {
    vector<double> hour;
    Day();    // initialize hours to "not a reading"
};

//------------------------------------------------------------------------------

Day::Day() : hour(24)
{
    for (int i = 0; i<hour.size(); ++i) hour[i]=not_a_reading;
}

//------------------------------------------------------------------------------

struct Month {        // a month of temperature readings
    int month;        // [0:11] January is 0
    vector<Day> day;  // [1:31] one vector of readings per day
    Month()           // at most 31 days in a month (day[0] wasted)
        :month(not_a_month), day(32) { }
};

//------------------------------------------------------------------------------

struct Year {             // a year of temperature readings, organized by month
    int year;             // positive == A.D.
    vector<Month> month;  // [0:11] January is 0
    Year() :month(12) { } // 12 months in a year
};

//------------------------------------------------------------------------------

struct Reading {
    int day;
    int hour;
    double temperature;
};

//------------------------------------------------------------------------------

int month_to_int(string s);
bool is_valid(const Reading& r);
void end_of_loop(istream& ist, char term, const string& message);

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Reading& r)
// read a temperature reading from is into r
// format: ( 3 4 9.7 )
// check format, but don't bother with data validity
{
    char ch1;
    if (is>>ch1 && ch1!='(') {    // could it be a Reading?
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2!=')') error("bad reading"); // messed up reading
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Month& m)
// read a month from is into m
// format: { month feb ... }
{
    char ch = 0;
    if (is >> ch && ch!='{') {
        is.unget();
        is.clear(ios_base::failbit);    // we failed to read a Month
        return is;
    }

    string month_marker;
    string mm;    
    is >> month_marker >> mm;
    if (!is || month_marker!="month") error("bad start of month");
    m.month = month_to_int(mm);

    Reading r;
    int no_of_duplicate_readings = 0;
    int no_invalid_readings = 0;

    while (is >> r)
        if (is_valid(r)) {
            if (m.day[r.day].hour[r.hour] != not_a_reading)
                ++no_of_duplicate_readings;
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else
            ++no_invalid_readings;
    end_of_loop(is,'}',"bad end of month");
    return is;
}

//------------------------------------------------------------------------------

const int implausible_min = -200;
const int implausible_max = 200;

bool is_valid(const Reading& r)
// a rough rest
{
    if (r.day<1 || 31<r.day) return false;
    if (r.hour<0 || 23<r.hour) return false;
    if (r.temperature<implausible_min|| implausible_max<r.temperature)
        return false;
    return true;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Year& y)
// read a year from is into y
// format: { year 1972 ... }
{
    char ch;
    is >> ch;
    if (ch!='{') {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }

    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker!="year") error("bad start of year");
    y.year = yy;

    while(true) {
        Month m;    // get a clean m each time around
        if(!(is >> m)) break;
        y.month[m.month] = m;
    }

    end_of_loop(is,'}',"bad end of year");
    return is;
}

//------------------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail()) { // use term as terminator and/or separator
        ist.clear();
        char ch;
        if (ist>>ch && ch==term) return;    // all is fine
        error(message);
    }
}

//------------------------------------------------------------------------------

vector<string> month_input_tbl;    // month_input_tbl[0]=="jan"

void init_input_tbl(vector<string>& tbl)
// initialize vector of input representations
{
    tbl.push_back("jan");
    tbl.push_back("feb");
    tbl.push_back("mar");
    tbl.push_back("apr");
    tbl.push_back("may");
    tbl.push_back("jun");
    tbl.push_back("jul");
    tbl.push_back("aug");
    tbl.push_back("sep");
    tbl.push_back("oct");
    tbl.push_back("nov");
    tbl.push_back("dec");
}

//------------------------------------------------------------------------------

int month_to_int(string s)
// is s the name of a month? If so return its index [0:11] otherwise -1
{
    for (int i=0; i<12; ++i) if (month_input_tbl[i]==s) return i;
    return -1;
}

//------------------------------------------------------------------------------

vector<string> month_print_tbl;    // month_print_tbl[0]=="January"

void init_print_tbl(vector<string>& tbl)
// initialize vector of output representations
{
    tbl.push_back("January");
    tbl.push_back("February");
    tbl.push_back("March");
    tbl.push_back("April");
    tbl.push_back("May");
    tbl.push_back("June");
    tbl.push_back("July");
    tbl.push_back("August");
    tbl.push_back("September");
    tbl.push_back("October");
    tbl.push_back("November");
    tbl.push_back("December");
}

//------------------------------------------------------------------------------

string int_to_month(int i)
// months [0:11]
{
    if (i<0 || 12<=i) error("bad month index");
    return month_print_tbl[i];
}

//------------------------------------------------------------------------------

void print_year(ostream& ost, const Year& y)
{
    ost << y.year << ' ';
}

//------------------------------------------------------------------------------

int main()
try
{
    // first initialize representation tables:
    init_print_tbl(month_print_tbl);
    init_input_tbl(month_input_tbl);

    // open an input file:
    cout << "Please enter input file name\n";
    string name;
    cin >> name;
    ifstream ifs(name.c_str());
    if (!ifs) error("can't open input file",name);

    ifs.exceptions(ifs.exceptions()|ios_base::badbit);    // throw for bad()

    // open an output file:
    cout << "Please enter output file name\n";
    cin >> name;
    ofstream ofs(name.c_str());
    if (!ofs) error("can't open output file",name);

    // read an arbitrary number of years:
    vector<Year> ys;
    while(true) {    
        Year y;        // get a freshly initialized Year each  time around
        if (!(ifs>>y)) break;
        ys.push_back(y);
    }
    cout << "read " << ys.size() << " years of readings\n";

    for (int i = 0; i<ys.size(); ++i) print_year(ofs,ys[i]);
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
