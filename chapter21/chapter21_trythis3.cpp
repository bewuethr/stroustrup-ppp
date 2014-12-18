// Chapter 21, Try This 3: define a vector<Record>, initialise it with four
// records of your choice, and compute their total price using the functions
// given

#include "../lib_files/std_lib_facilities.h"
#include<numeric>

//------------------------------------------------------------------------------

struct Record {
    Record(double up, int un) : unit_price(up), units(un) { }
    double unit_price;
    int units;  // number of units sold
};

//------------------------------------------------------------------------------

double price(double v, const Record& r)
{
    return v + r.unit_price * r.units;  // calculate price and accumulate
}

//------------------------------------------------------------------------------

void f(const vector<Record>& vr)
{
    double total = accumulate(vr.begin(),vr.end(),0.0,price);
    cout << "Total is " << total << "\n";
}

//------------------------------------------------------------------------------

int main()
try {
    Record rec1 = Record(10.9,15);
    Record rec2 = Record(25.5,3);
    Record rec3 = Record(101,75);
    Record rec4 = Record(5.33,27);
    vector<Record> vr;
    vr.push_back(rec1);
    vr.push_back(rec2);
    vr.push_back(rec3);
    vr.push_back(rec4);
    f(vr);
}
catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

//------------------------------------------------------------------------------