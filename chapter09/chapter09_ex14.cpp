// Chapter 09, exercise 14: Money class for dollar/cent calculations
// Exercise 15: refine Money class by adding a currency

#include "../lib_files/std_lib_facilities.h"

// function for rounding a double to a long int
long int my_round(double d)
{
    return (d > 0.0) ? (d + 0.5) : (d - 0.5);
}

// type for money with 4/5 rounding rule
class Money {
public:
    enum Currency {
        USD, CHF, KYD
    };
    Money() :cents(0), cur(USD) { }
    Money(long int c) :cents(c), cur(USD) { }
    Money(int d, int c) :cents(d*100 + c), cur(USD)
    {
        if (c >= 100) error("cents must be between 0 and 99");
    }
    Money(long int c, Currency cur) :cents(c), cur(cur) { }
    Money(int d, int c, Currency cur)
        :cents(d*100 + c), cur(cur) { }
    int get_dollars() const { return cents/100; }
    int get_cents() const { return cents%100; }
    long int cents;
    Currency cur;
};

// one unit of c2 is worth how many units of c1?
double exch_rate(Money::Currency c1, Money::Currency c2)
{
    switch (c1) {
    case Money::USD:
        switch (c2) {
        case Money::CHF:
            return 1.11;
        case Money::KYD:
            return 1.22;
        default:
            error("exch_rate: illegal combination of currencies");
        }
    case Money::CHF:
        switch (c2) {
        case Money::USD:
            return 0.91;
        case Money::KYD:
            return 1.1;
        default:
            error("exch_rate: illegal combination of currencies");
        }
    case Money::KYD:
        switch (c2) {
        case Money::USD:
            return 0.82;
        case Money::CHF:
            return 0.91;
        default:
            error("exch_rate: illegal combination of currencies");
        }
    default:
        error("exch_rate: illegal combination of currencies");
    }
}

// result in the currency of the first summand
Money operator+(const Money& a, const Money& b)
{
    if (a.cur == b.cur) // just return same currency
        return Money(a.cents+b.cents,a.cur);

    double d = exch_rate(a.cur,b.cur);

    return Money(a.cents + my_round(d*double(b.cents)),a.cur);
}

Money operator-(const Money& a, const Money& b)
{
    if (a.cur == b.cur) // just return same currency
        return Money(a.cents-b.cents,a.cur);

    double d = exch_rate(a.cur,b.cur);

    return Money(a.cents - my_round(d*double(b.cents)),a.cur);
}

Money operator-(const Money& m)
{
    return Money(-m.cents,m.cur);
}

Money operator*(int n, const Money& m)
{
    return Money(n * m.cents,m.cur);
}

Money operator*(const Money& m, int n)
{
    return n*m;
}

Money operator/(const Money& m, int n)
{
    if (n == 0) error("division by zero");
    double d = double(m.cents) / n;
    long int c = my_round(d);
    return Money(c,m.cur);
}

ostream& operator<<(ostream& os, const Money::Currency& cur)
{
    switch (cur) {
    case Money::USD:
        return os << "USD";
    case Money::CHF:
        return os << "CHF";
    case Money::KYD:
        return os << "KYD";
    }
}

ostream& operator<<(ostream& os, const Money& m)
{
    os << m.cur << m.get_dollars() << '.';
    if (abs(m.get_cents()) < 10) os << '0';      // to get $1.05 instead of $1.5
    os << abs(m.get_cents());
    return os;
}

istream& operator>>(istream& is, Money& m)
{
    int d, c;
    string s;
    char ch;
    is >> s >> d >> ch >> c;
    if (!is) return is;
    if (!(s=="USD" || s=="CHF" || s=="KYD") || ch!='.') { // oops: format error
        is.clear(ios_base::failbit);                    // set the fail bit
        return is;
    }
    Money::Currency cur;
    if (s=="USD") cur = Money::USD;
    else if (s=="CHF") cur = Money::CHF;
    else if (s=="KYD") cur = Money::KYD;
    else error("illegal currency in input");
    m = Money(d,(c<10)?(10*c):c,cur);   // '123.1' means '123.10' and not '123.01'
    return is;
}

int main()
try {
    Money m1;
    Money m2(105);
    Money m3(5,12);

    cout << "m1: " << m1 << endl;
    cout << "m2(105): " << m2 << endl;
    cout << "m3(5,12): " << m3 << endl;
    cout << "-m3: " << -m3 << endl;

    //Money m5;
    //cout << "Enter amount as in CUR xxx.xx: ";
    //cin >> m5;
    //cout << "You entered " << m5 << endl;

    cout << m2 << " + " << m3 << " = " << m2+m3 << endl;
    cout << m2 << " - " << m3 << " = " << m2-m3 << endl;
    cout << "5 * " << m2 << " = " << 5*m2 << endl;
    cout << m2 << " * 5 = " << m2*5 << endl;

    cout << m3 << " - " << m2 << " = " << m3-m2 << endl;

    cout << Money(1,0) << " / 7 = " << Money(1,0)/7 << endl;
    cout << Money(0,9) << " / 6 = " << Money(0,9)/6 << endl << endl;

    m1 = Money(7,12,Money::USD);
    m2 = Money(100,5,Money::CHF);
    m3 = Money(55,12,Money::KYD);
    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;
    cout << "m3 = " << m3 << endl << endl;
    cout << m1 << " + " << m2 << " = " << m1+m2 << endl;
    cout << m1 << " + " << m3 << " = " << m1+m3 << endl;
    cout << m2 << " + " << m1 << " = " << m2+m1 << endl;
    cout << m2 << " + " << m3 << " = " << m2+m3 << endl;
    cout << m3 << " + " << m1 << " = " << m3+m1 << endl;
    cout << m3 << " + " << m2 << " = " << m3+m2 << endl;
    cout << m3 << " - " << m2 << " = " << m3-m2 << endl;
    cout << 3 << " * " << m2 << " = " << 3*m2 << endl;
    cout << m3 << " / " << 17 << " = " << m3/17 << endl;

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
