#include "Liber.h"

namespace Liber {
    // function definitions for ISBN struct
    ISBN::ISBN(int n1, int n2, int n3, char x)
        :n1(n1), n2(n2), n3(n3), x(x)
    {
        if (!is_isbn(n1,n2,n3,x)) error("is_isbn(): invalid number");
    }

    const ISBN& default_isbn()
    {
        static const ISBN in(0,0,0,'0');
        return in;
    }

    ISBN::ISBN()
        :n1(default_isbn().n1),
        n2(default_isbn().n2),
        n3(default_isbn().n2),
        x(default_isbn().x)
    {
    }

    // check if ISBN is valid
    bool is_isbn(int, int, int, char x)
    {
        return (isalpha(x) || isdigit(x));
    }

    bool operator==(const ISBN& i1, const ISBN& i2)
    {
        return (i1.n1==i2.n1 && i1.n2==i2.n2 && i1.n3==i2.n3 && i1.x==i2.x);
    }

    // function definitions for Book class
    Book::Book(ISBN inum, string title, string author, int c_date, Genre gen, bool checked_out)
        :in(inum), t(title), a(author), cd(c_date), g(gen), ch_out(checked_out)
    {
    }

    const Book& default_book()
    {
        static const Book b(ISBN(),"","",0,Book::fiction,false);
        return b;
    }

    Book::Book()
        :in(default_book().isbn()),
        t(default_book().title()),
        a(default_book().author()),
        cd(default_book().c_date()),
        g(default_book().genre()),
        ch_out(default_book().checked_out())
    {
    }

    void Book::check_out()
    {
        if (checked_out()) error("already checked out");
        ch_out = true;
    }

    void Book::check_in()
    {
        if (!checked_out()) error("already checked in");
        ch_out = false;
    }

    bool operator==(const Book& b1, const Book& b2)
    {
        return (b1.isbn() == b2.isbn());
    }

    bool operator!=(const Book& b1, const Book& b2)
    {
        return !(b1==b2);
    }

    ostream& operator<<(ostream& os, const Book& b)
    {
        return os << b.title() << endl
            << b.author() << endl
            << b.isbn().n1 << '-'
            << b.isbn().n2 << '-'
            << b.isbn().n3 << '-'
            << b.isbn().x << endl;
    }

    Patron::Patron(string n, int cn, double f)
        :name(n), card_number(cn), fees(f)
    {
    }

    const Patron& default_patron()
    {
        static const Patron p("",0,0);
        return p;
    }

    Patron::Patron()
        :name(default_patron().get_name()),
        card_number(default_patron().get_number()),
        fees(default_patron().get_fees())
    {
    }

    void Patron::set_fee(double f)
    {
        if (f < 0) error("set_fee(): fee cannot be smaller than zero");
        fees = f;
    }

    bool owes_fee(const Patron& p)
    {
        return p.get_fees() > 0;
    }

    bool operator==(const Patron& p1, const Patron& p2)
    {
        return p1.get_number() == p2.get_number();
    }

    bool operator!=(const Patron& p1, const Patron& p2)
    {
        return !(p1==p2);
    }

    Library::Transaction::Transaction(Book bb, Patron pp, Chrono::Date dd)
        :b(bb), p(pp), d(dd)
    {
    }

    const Library::Transaction& default_transaction()
    {
        static const Library::Transaction tt = Library::Transaction(Book(), Patron(), Chrono::Date());
        return tt;
    }

    Library::Transaction::Transaction()
        :b(default_transaction().b),
        p(default_transaction().p),
        d(default_transaction().d)
    {
    }

    Library::Library(vector<Book> b, vector<Patron> p, vector<Transaction> t)
        :books(b), patrons(p), transactions(t)
    {
    }

    const Library& default_library()
    {
        vector<Book> b;
        vector<Patron> p;
        vector<Library::Transaction> t;
        static const Library l(b,p,t);
        return l;
    }

    Library::Library()
        :books(default_library().get_books()),
        patrons(default_library().get_patrons()),
        transactions(default_library().get_transactions())
    {
    }

    void Library::add_book(const Book& b)
    {
        // check if book is already in library
        for (int i = 0; i<books.size(); ++i) {
            if (books[i] == b) error("add_book(): book is already in library");
        }
        books.push_back(b);
    }

    void Library::add_patron(const Patron& p)
    {
        // check if patron is already registered
        for (int i = 0; i<patrons.size(); ++i) {
            if (patrons[i] == p) error("add_patron(): patron is already registered");
        }
        patrons.push_back(p);
    }

    void Library::check_out(Book& b, const Patron& p, const Chrono::Date& d)
    {
        // check if book is in library
        bool b_exists = false;
        int b_idx = 0;
        for (int i = 0; i<books.size(); ++i) {
            if (books[i] == b) {
                b_exists = true;
                b_idx = i;
                break;  // no need to look any further
            }
        }
        if (!b_exists) error("check_out(): book is not in library");

        // check if book is checked out
        if (books[b_idx].checked_out()) error("check_out(): book is already checked out");

        // check if patron is registered
        bool p_exists = false;
        int p_idx = 0;
        for (int i = 0; i<patrons.size(); ++i) {
            if (patrons[i] == p) {
                p_exists = true;
                p_idx = i;
                break;  // no need to look any further
            }
        }
        if (!p_exists) error("check_out(): patron is not registered");

        // check if patron owes fees
        if (patrons[p_idx].get_fees() > 0) error("check_out(): patron owes library fees");

        // create Transaction
        transactions.push_back(Transaction(books[b_idx],patrons[p_idx],d));
        books[b_idx].check_out();
    }

    void Library::set_fee(const Patron& p, double f)
    {
        // find patron
        int idx = 0;
        bool exists = false;
        for (int i = 0; i<patrons.size(); ++i) {
            if (patrons[i] == p) {
                exists = true;
                idx = i;
                break;
            }
        }
        if (!exists) error("Library::set_fee(): patron does not exist");
        patrons[idx].set_fee(f);
    }

    vector<Patron> Library::get_debtors() const
    {
        vector<Patron> debtors;
        for (int i = 0; i<patrons.size(); ++i) {
            if (patrons[i].get_fees() > 0)
                debtors.push_back(patrons[i]);
        }
        return debtors;
    }
}   // Liber