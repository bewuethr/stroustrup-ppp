#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include "../lib_files/std_lib_facilities.h"

namespace Order {;

//------------------------------------------------------------------------------

struct Day {
    explicit Day(int d) :val(d) { }
    int val;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Day& d);

//------------------------------------------------------------------------------

struct Month {
    explicit Month(int m) :val(m) { }
    int val;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Month& m);

//------------------------------------------------------------------------------

struct Year {
    explicit Year(int y) :val(y) { }
    int val;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Year& y);

//------------------------------------------------------------------------------

class Date {
    Day d;
    Month m;
    Year y;
public:
    Date() :d(1), m(1), y(1970) { }
    Date(const Day& day, const Month& month, const Year& year)
        :d(day), m(month), y(year) { }
    Day day() const { return d; }
    Month month() const { return m; }
    Year year() const { return y; }
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& date);

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Date& date);

//------------------------------------------------------------------------------

class Purchase {
    string n;   // name of product
    double up;  // unit price
    int c;      // count
public:
    Purchase() :n(""), up(0.0), c(0) { }
    Purchase(const string& name, double unit_price, int count)
        :n(name), up(unit_price), c(count) { }
    string name() const { return n; }
    double unit_price() const { return up; }
    int count() const { return c; }
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Purchase& p);

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Purchase& p);

//------------------------------------------------------------------------------

class Order {
    string n;               // name of customer
    string addr;            // address of customer
    Date d;                 // date of order
    vector<Purchase> vp;    // purchases in order
public:
    Order() :n(), addr(), d(), vp() { }
    Order(const string& name, const string& address, const Date& date,
        const vector<Purchase>& vpurchases)
        :n(name), addr(address), d(date), vp(vpurchases) { }
    string name() const { return n; }
    string address() const { return addr; }
    Date date() const { return d; }
    int n_purchases() const { return vp.size(); }
    Purchase purchase(int i) const { return vp[i]; }
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Order& o);

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Order& o);

//------------------------------------------------------------------------------

// to sort any type that has a getter name() for which < is defined
template<class T>
struct Sort_by_name {
    bool operator()(const T& a, const T& b) const
    {
        return a.name() < b.name();
    }
};

//------------------------------------------------------------------------------

// to sort any type that has a getter address() for which < is defined
template<class T>
struct Sort_by_address {
    bool operator()(const T& a, const T& b) const
    {
        return a.address() < b.address();
    }
};

//------------------------------------------------------------------------------

// appends Orders in fname to container c
template<class Cont>
void read_orders_from_file(Cont& c, const string& fname)
{
    ifstream ifs(fname.c_str());
    if (!ifs) error("can't open file ",fname);
    Order o;
    while (ifs>>o) {
        c.push_back(o);
    }
}

//------------------------------------------------------------------------------

// writes orders in [first,last) to file fname
template<class Iter>
void write_orders_to_file(Iter first, Iter last, const string& fname)
{
    ofstream ofs(fname.c_str());
    if (!ofs) error("can't open file ",fname);
    while (first != last) {
        ofs << *first << '\n';
        ++first;
    }
}

//------------------------------------------------------------------------------

// return total value of orders in file
double get_value(const string& fname);

//------------------------------------------------------------------------------

bool file_check(const string& fname);

//------------------------------------------------------------------------------

}   // namespace Order

#endif // ORDER_H_INCLUDED
