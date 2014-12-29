#include "chapter21_ex11_Order.h"

namespace Order {;

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Day& d)
{
    os << d.val;
    return os;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Month& m)
{
    os << m.val;
    return os;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Year& y)
{
    os << y.val;
    return os;
}

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

double get_value(const string& fname)
{
    vector<Order> vo;
    read_orders_from_file(vo,fname);
    double val_t = 0;
    for (vector<Order>::iterator it = vo.begin(); it != vo.end(); ++it) {
        for (int i = 0; i<(*it).n_purchases(); ++i)
            val_t += (*it).purchase(i).count() * (*it).purchase(i).unit_price();
    }
    return val_t;
}

//------------------------------------------------------------------------------

bool file_check(const string& fname)
{
    if (fname=="") {
        cout << "\nFile name is empty!\n\n";
        return false;
    }

    // test if file exists
    ifstream ifs(fname.c_str());
    if (!ifs) {
        cout << "\nFile " << fname << " doesn't exist!\n\n";
        return false;
    }

    return true;
}

//------------------------------------------------------------------------------
    
}   // namespace Order
