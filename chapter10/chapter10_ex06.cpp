// Chapter 10, exercise 06: define Roman_int class for Roman numerals, provide
// << and >> and an as_int() member

#include "chapter10_ex06.h"

Roman_int::Roman_int() :val(0) { }

Roman_int::Roman_int(int n) : val(n) { }

int Roman_int::as_int() const { return val; }

void Roman_int::set_val(int v) { val = v; }

Roman_int operator+(const Roman_int& r1, const Roman_int& r2)
{
    return Roman_int(r1.as_int()+r2.as_int());
}

Roman_int operator-(const Roman_int& r1, const Roman_int& r2)
{
    return Roman_int(r1.as_int()-r2.as_int());
}

Roman_int operator-(const Roman_int& r)
{
    return Roman_int(-r.as_int());
}

Roman_int operator*(const Roman_int& r1, const Roman_int& r2)
{
    return Roman_int(r1.as_int()*r2.as_int());
}

Roman_int operator/(const Roman_int& r1, const Roman_int& r2)
{
    if (r2.as_int()==0) error("division by zero");
    double d = double(r1.as_int()) / r2.as_int();
    int res = int(d);
    if (res!=d) error("division leads to non-integer result");
    return Roman_int(res);
}

Roman_int operator%(const Roman_int& r1, const Roman_int& r2)
{
    return Roman_int(r1.as_int()%r2.as_int());
}

bool operator==(const Roman_int& r1, const Roman_int& r2)
{
    return r1.as_int() == r2.as_int();
}

bool operator!=(const Roman_int& r1, const Roman_int& r2)
{
    return !(r1==r2);
}

bool operator<(const Roman_int& r1, const Roman_int& r2)
{
    return r1.as_int() < r2.as_int();
}

bool operator>(const Roman_int& r1, const Roman_int& r2)
{
    return r2 < r1;
}

bool operator<=(const Roman_int& r1, const Roman_int& r2)
{
    return !(r2 < r1);
}

bool operator>=(const Roman_int& r1, const Roman_int& r2)
{
    return !(r1 < r2);
}

// determines if a character can be part of a roman numeral
bool is_valid_char(char ch)
{
    return ch==N || ch==I || ch==V || ch==X || ch==L || ch==C || ch==D || ch==M;
}

ostream& operator<<(ostream& os, const Roman_int& r)
{
    int val = r.as_int();
    if (val == 0) return os << N;    // return 'N' for zero
    if (val < 0) {  // if negative, make positive until end
        os << '-';  // print negative sign
        val = -val;
    }

    // look at thousands
    while (val >= 1000) {
        os << M;
        val -= 1000;
    }
    // look at 900, 500 and 400
    if (val >= 900) {
        os << C << M;
        val -= 900;
    }
    else if (val >= 500) {
        os << D;
        val -= 500;
    }
    else if (val >= 400) {
        os << C << D;
        val -= 400;
    }
    // look at hundreds
    while (val >= 100) {
        os << C;
        val -= 100;
    }
    // look at 90, 50 and 40
    if (val >= 90) {
        os << X << C;
        val -= 90;
    }
    else if (val >= 50) {
        os << L;
        val -= 50;
    }
    else if (val >= 40) {
        os << X << L;
        val -= 40;
    }
    // look at tens
    while (val >= 10) {
        os << X;
        val -= 10;
    }
    // look at 9, 5 and 4
    if (val == 9) {
        os << I << X;
        val -= 9;
    }
    else if (val >= 5) {
        os << V;
        val -= 5;
    }
    else if (val == 4) {
        os << I << V;
        val -= 4;
    }
    // look at ones
    while (val >= 1) {
        os << I;
        --val;
    }
    return os;
}

// return value of single letter Roman numeral
int get_value(char ch)
{
    switch (ch) {
    case N:
        return 0;
    case I:
        return 1;
    case V:
        return 5;
    case X:
        return 10;
    case L:
        return 50;
    case C:
        return 100;
    case D:
        return 500;
    case M:
        return 1000;
    default:
        error("illegal letter used: ",string(1,ch));
    }
}

// test if letter has been repeated too often
bool counter_illegal(int counter, char ch)
{
    switch (ch) {
    case N: case V: case L: case D:
        return counter > 1;
    case I: case X: case C: case M:
        return counter > 3;
    default:
        error("counter_illegal: invalid character ",string(1,ch));
    }
}

// test if string is valid roman numeral, calculate its value
int roman_int_to_int(const string& s)
{
    if (s.size()==0) error("roman_to_int: empty string");
    if (s.size()==1) return get_value(s[0]);

    int counter = 1;    // keep track of how often a letter is repeated
    int val = get_value(s[s.size()-1]);
    int min_val = val;  // keep track of smallest allowed value of letter

    // traverse string, starting at end
    for (int i = s.size()-2; i>=0; --i) {
        if (s[i]==s[i+1]) {
            ++counter;  // increase counter for repeated occurrence of letter
            if (counter_illegal(counter,s[i]))
                error("illegal repetition of letter: ",string(1,s[i]));
        }
        else counter = 1;

        // check if legal combination of smaller value to the left of larger value
        if (get_value(s[i])<get_value(s[i+1])) {
            if ((s[i]==I || s[i]==X || s[i]==C) && get_value(s[i+1]) <= 10*get_value(s[i]))
                val -= get_value(s[i]); // legal: subtract value
            else
                error("illegal use of ",string(1,s[i]));
        }
        else {  // normal case: add value
            val += get_value(s[i]);
            min_val = get_value(s[i]);
        }
    }
    return val;
}

istream& operator>>(istream& is, Roman_int& r)
{
    // throw exception if is.bad()
    is.exceptions(is.exceptions()|ios_base::badbit);

    string s;
    char ch;

    // add characters to s until space, newline, eof or invalid character
    while (is.get(ch)) {
        if (is_valid_char(ch)) s += ch;
        else {
            is.putback(ch);
            break;
        }
    }

    // s consists only of valid characters - is it a valid Roman numeral?
    int val = roman_int_to_int(s);
    r.set_val(val);
    return is;
}

void test_output()
{
    cout << Roman_int(0) << " equals " << Roman_int(0).as_int() << endl;
    cout << Roman_int(1) << " equals " << Roman_int(1).as_int() << endl;
    cout << Roman_int(4) << " equals " << Roman_int(3).as_int() << endl;
    cout << Roman_int(5) << " equals " << Roman_int(4).as_int() << endl;
    cout << Roman_int(8) << " equals " << Roman_int(8).as_int() << endl;
    cout << Roman_int(9) << " equals " << Roman_int(9).as_int() << endl;
    cout << Roman_int(10) << " equals " << Roman_int(10).as_int() << endl;
    cout << Roman_int(48) << " equals " << Roman_int(48).as_int() << endl;
    cout << Roman_int(81) << " equals " << Roman_int(81).as_int() << endl;
    cout << Roman_int(99) << " equals " << Roman_int(99).as_int() << endl;
    cout << Roman_int(105) << " equals " << Roman_int(105).as_int() << endl;
    cout << Roman_int(2014) << " equals " << Roman_int(2014).as_int() << endl;
    cout << Roman_int(-2014) << " equals " << Roman_int(-2014).as_int() << endl;
    cout << Roman_int(1499) << " equals " << Roman_int(1499).as_int() << endl << endl;
    cout << Roman_int(1) << " + " << Roman_int(3) << " = " << Roman_int(1)+Roman_int(3) << endl;
    cout << Roman_int(15) << " * " << Roman_int(37) << " = " << Roman_int(15)*Roman_int(37) << endl;
    cout << Roman_int(105) << " - " << Roman_int(207) << " = " << Roman_int(105)-Roman_int(207) << endl;
    cout << -Roman_int(7) << " * " << Roman_int(5) << " = " << -Roman_int(7)*Roman_int(5) << endl;
    cout << Roman_int(15) << " / " << Roman_int(5) << " = " << Roman_int(15)/Roman_int(5) << endl;
}

//int main()
//try {
//    test_output();
//}
//catch (exception& e) {
//    cerr << "exception: " << e.what() << endl;
//    keep_window_open();
//}
//catch (...) {
//    cerr << "exception\n";
//    keep_window_open();
//}
