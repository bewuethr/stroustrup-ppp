// Chapter 21, Exercise 9: define a class Order with members name (of customer),
// address, data and vector<Purchase>. Purchase is a class with members name
// (of product), unit_price and count. Define a mechanism for reading and
// writing Orders from and to a file and a mechanism to print Orders.
//
// Create a file of at least ten Orders, read it into a vector<Order>, sort it
// by name (of customer) and write it back out to file. Create another file of
// at least ten Orders of which about a third are the same as in the first file,
// read it into a list<Order>, sort it by address (of customer) and write it
// back out to file. Merge the two files into a third using std::merge().

// Remark: merge() requires two sorted ranges to work properly; also, it doesn't
// eliminate duplicates, which would make sense in this context. To do so, the
// Orders could either be added to a set<Order,Sort_by_name<Order>> first or
// they could be copied using unique_copy(). Most likely, operator== for Order
// would have to be defined for this to work.

// Exercise 10: compute the total value of the orders in the two files; the
// of an individual Purchase is unit_price * count.

#include "../lib_files/std_lib_facilities.h"
#include<set>

//------------------------------------------------------------------------------

struct Day {
    explicit Day(int d) :val(d) { }
    int val;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Day& d)
{
    os << d.val;
    return os;
}

//------------------------------------------------------------------------------

struct Month {
    explicit Month(int m) :val(m) { }
    int val;
};

//------------------------------------------------------------------------------


ostream& operator<<(ostream& os, const Month& m)
{
    os << m.val;
    return os;
}

//------------------------------------------------------------------------------

struct Year {
    explicit Year(int y) :val(y) { }
    int val;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Year& y)
{
    os << y.val;
    return os;
}

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

ostream& operator<<(ostream& os, const Date& date)
{
    os << date.day() << '.' << date.month() << '.' << date.year();
    return os;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Date& date)
{
    int d;
    int m;
    int y;
    char ch1;
    char ch2;
    is >> d >> ch1 >> m >> ch2 >> y;
    if (!is) return is;
    if (ch1!='.' || ch2!='.') {
        is.clear(ios_base::failbit);
        return is;
    }
    date = Date(Day(d),Month(m),Year(y));
    return is;
}

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

ostream& operator<<(ostream& os, const Purchase& p)
{
    os << p.name() << " | " << p.unit_price() << " | " << p.count();
    return os;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Purchase& p)
{
    string name;
    getline(is,name,'|');   // possibly spaces in product name
    if (!is || name.size()==0) return is;
    name.pop_back();        // remove last space
    double unit_price;
    char ch2;
    int count;
    is >> unit_price >> ch2 >> count;
    if (!is) return is;
    if (ch2!='|') {
        is.clear(ios_base::failbit);
        return is;
    }
    p = Purchase(name,unit_price,count);
    return is;
}

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

ostream& operator<<(ostream& os, const Order& o)
{
    os << o.name() << '\n' << o.address() << '\n' << o.date() << '\n';
    for (int i = 0; i<o.n_purchases(); ++i)
        os << o.purchase(i) << '\n';
    return os;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Order& o)
{
    char ch;
    while (is >> ch) {
        if (ch != '\n') {
            is.unget();
            break;
        }
    }
    string name;
    getline(is,name);
    if (!is) return is;
    string address;
    getline(is,address);
    if (!is) error("can't read address");
    Date date;
    is >> date;
    if (!is) error("can't read date");
    is.ignore();    // discard '\n' after date
    string line;
    vector<Purchase> purchases;
    while (getline(is,line) && line!="") {
        Purchase purchase;
        istringstream iss(line);
        iss >> purchase;
        purchases.push_back(purchase);
    }
    o = Order(name,address,date,purchases);
    return is;
}

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

int main()
try {
    // read first file
    const string ifname1 = "pics_and_txt/chapter21_ex09_in1.txt";
    vector<Order> vo;
    read_orders_from_file(vo,ifname1);

    // sort by customer name and print first file to cout
    sort(vo.begin(),vo.end(),Sort_by_name<Order>());
    for (int i = 0; i<vo.size(); ++i)
        cout << vo[i] << '\n';

    // print to file
    const string ofname1 = "pics_and_txt/chapter21_ex09_out1.txt";
    write_orders_to_file(vo.begin(),vo.end(),ofname1);

    // read second file
    const string ifname2 = "pics_and_txt/chapter21_ex09_in2.txt";
    list<Order> lo;
    read_orders_from_file(lo,ifname2);

    // sort by customer address and print second file out
    cout << "---------------------------------\n\n";
    lo.sort(Sort_by_address<Order>());
    typedef list<Order>::iterator Liter;
    for (Liter it = lo.begin(); it!=lo.end(); ++it)
        cout << *it << '\n';

    // print to file
    const string ofname2 = "pics_and_txt/chapter21_ex09_out2.txt";
    write_orders_to_file(lo.begin(),lo.end(),ofname2);

    // merge into third file, sort list by customer name first
    lo.sort(Sort_by_name<Order>());
    vector<Order> vo_merge(vo.size()+lo.size());
    merge(vo.begin(),vo.end(),lo.begin(),lo.end(),vo_merge.begin(),
        Sort_by_name<Order>());
    const string ofname3 = "pics_and_txt/chapter21_ex09_out3.txt";
    write_orders_to_file(vo_merge.begin(),vo_merge.end(),ofname3);

    // Exercise 10: total value of purchases; also eliminating duplicates
    set<Order,Sort_by_name<Order>> so;
    typedef vector<Order>::iterator Viter;
    for (Viter it = vo_merge.begin(); it!=vo_merge.end(); ++it)
        so.insert(*it);

    // Print to demonstrate how duplicates were eliminated; also calculate
    // total value of Purchases
    cout << "---------------------------------\n\n";
    double val_t = 0;
    for (set<Order>::iterator it = so.begin(); it != so.end(); ++it) {
        cout << *it << '\n';
        for (int i = 0; i<(*it).n_purchases(); ++i)
            val_t += (*it).purchase(i).count() * (*it).purchase(i).unit_price();
        cout << "Running total so far: " << val_t << "\n\n";
    }
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