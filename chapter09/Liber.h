#include "../lib_files/std_lib_facilities.h"
#include "Chrono.h"

namespace Liber {;
// type for ISBN of the form n-n-n-x
struct ISBN {
    int n1;
    int n2;
    int n3;
    char x; // digit or letter

    // constructors
    ISBN(int n1, int n2, int n3, char x);
    ISBN(); // default constructor
};

bool is_isbn(int, int, int, char x);  // true for valid ISBN number

bool operator==(const ISBN& i1, const ISBN& i2);

// simple Book type
class Book {
public:
    enum Genre {
        fiction = 0, nonfiction, periodical, biography, children
    };

    // constructors
    Book(ISBN isbnum, string title, string author, int c_date, Genre gen, bool checked_out);
    Book(); // default constructor

    // nonmodifying operations
    ISBN isbn() const { return in; }
    string title() const { return t; }
    string author() const { return a; }
    int c_date() const { return cd; }
    Genre genre() const { return g; }
    bool checked_out() const { return ch_out; }

    // modifying operations
    void check_out();
    void check_in();

private:
    ISBN in;        // ISBN number
    string t;       // title of book
    string a;       // name of author
    int cd;         // copyright date
    Genre g;        // Genre of book
    bool ch_out;    // is the book checked out?
};

bool operator==(const Book& b1, const Book& b2);
bool operator!=(const Book& b1, const Book& b2);
ostream& operator<<(ostream& os, const Book& b);

// type for customers
class Patron {
public:
    // constructors
    Patron(string name, int card_number, double fees);
    Patron();

    // nonmodifying operations
    string get_name() const { return name; }
    int get_number() const { return card_number; }
    double get_fees() const { return fees; }

    // modifying operations
    void set_fee(double f); // set library fee
private:
    string name;        // name of customers
    int card_number;    // library card number
    double fees;        // library fees (if owed)
};

bool owes_fee(const Patron& p); // does the customer owe a library fee?

bool operator==(const Patron& p1, const Patron& p2);
bool operator!=(const Patron& p1, const Patron& p2);

// library type
class Library {
public:
    // type for transaction, combining Book, Customer and Date types
    struct Transaction {
        Book b;
        Patron p;
        Chrono::Date d;

        Transaction(Book bb,Patron pp,Chrono::Date dd);
        Transaction();
    };

    // constructors
    Library(vector<Book> books, vector<Patron> patrons, vector<Transaction> transactions);
    Library();

    // modifying operations:
    void add_book(const Book& b);
    void add_patron(const Patron& p);
    void check_out(Book& b, const Patron& p, const Chrono::Date& d);
    void set_fee(const Patron& p, double f);

    // nonmodifying operations:
    vector<Book> get_books() const { return books; }
    vector<Patron> get_patrons() const { return patrons; }
    vector<Transaction> get_transactions() const { return transactions; }
    vector<Patron> get_debtors() const; // list of patrons who owe fees

private:
    vector<Book> books;
    vector<Patron> patrons;
    vector<Transaction> transactions;
};
}   // Liber
