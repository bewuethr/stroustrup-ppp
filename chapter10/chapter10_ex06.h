// Chapter 10, exercise 06

#include "../lib_files/std_lib_facilities.h"

// type for Roman numerals
class Roman_int {
public:
    Roman_int();
    Roman_int(int n);
    int as_int() const;
    void set_val(int v);
private:
    int val;
};

ostream& operator<<(ostream& os, const Roman_int& r);
istream& operator>>(istream& is, Roman_int& r);
Roman_int operator+(const Roman_int& r1, const Roman_int& r2);
Roman_int operator-(const Roman_int& r1, const Roman_int& r2);
Roman_int operator-(const Roman_int& r);
Roman_int operator*(const Roman_int& r1, const Roman_int& r2);
Roman_int operator/(const Roman_int& r1, const Roman_int& r2);
Roman_int operator%(const Roman_int& r1, const Roman_int& r2);
bool operator==(const Roman_int& r1, const Roman_int& r2);
bool operator!=(const Roman_int& r1, const Roman_int& r2);
bool operator<(const Roman_int& r1, const Roman_int& r2);
bool operator>(const Roman_int& r1, const Roman_int& r2);
bool operator<=(const Roman_int& r1, const Roman_int& r2);
bool operator>=(const Roman_int& r1, const Roman_int& r2);

const char N = 'N';
const char I = 'I';
const char V = 'V';
const char X = 'X';
const char L = 'L';
const char C = 'C';
const char D = 'D';
const char M = 'M';

// determines if a character can be part of a roman numeral
bool is_valid_char(char ch);

// return value of single letter Roman numeral
int get_value(char ch);

// test if letter has been repeated too often
bool counter_illegal(int counter, char ch);

// test if string is valid roman numeral, calculate its value
int roman_int_to_int(const string& s);

// return value of single letter Roman numeral
int get_value(char ch);

// test if letter has been repeated too often
bool counter_illegal(int counter, char ch);

// test if string is valid roman numeral, calculate its value
int roman_int_to_int(const string& s);
