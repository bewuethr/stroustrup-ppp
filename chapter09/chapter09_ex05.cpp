// Chapter 10, exercise 05: book class
// Exercise 06: add ==, != and << operators
// Exercise 07: add Genre enum
// Exercise 08: create Patron class
// Exercise 09: create Library class
// Exercise 10: implement leapyear() from §9.8
// Exercise 11: skipped
// Exercise 12: represent Date as number of days since January 1, 1970

#include "Liber.h"

using Liber::Library;
using Liber::Book;
using Liber::ISBN;
using Liber::Patron;
using Chrono::Date;
using Chrono::leapyear;
using Chrono::day_in_year;
using Chrono::n_leapyears;
using Chrono::days_linear;
using Chrono::day_of_week;

void test_liber()
{
    // create library
    Library my_lib;

    // create and add books
    Book my_book(ISBN(9780,4390,2348,'1'),
        "Hunger Games, The",
        "Collins, Suzanne",
        2008,
        Book::fiction,
        false);

    Book fake_book(ISBN(1111,1111,1111,'x'),
        "Fake Book",
        "Nobody",
        2000,
        Book::fiction,
        false);

    my_lib.add_book(my_book);

    Book my_book2(ISBN(9780,4393,5807,'1'),
        "Harry Potter and the Order of the Phoenix",
        "Rowling, J.K.",
        2003,
        Book::children,
        false);
    my_lib.add_book(my_book2);

    my_lib.add_book(Book(ISBN(9781,4165,3932,'2'),
        "Einstein: His Life and Universe",
        "Isaacson, Walter",
        2007,
        Book::biography,
        false));

    my_lib.add_book(Book(ISBN(9780,3160,6760,'7'),
        "Lone Survivor",
        "Luttrell, Marcus",
        2008,
        Book::nonfiction,
        false));

    my_lib.add_book(Book(ISBN(1234,5678,1234,'x'),
        "Triathlete Issue 2/14",
        "Competitor Group",
        2014,
        Book::periodical,
        false));

    // try to add book that already exists
    //my_lib.add_book(my_book);

    // print list of books
    cout << "All my books:\n\n";
    vector<Book> books = my_lib.get_books();
    for (int i = 0; i<books.size(); ++i) {
        cout << books[i] << endl;
    }

    // create and add patrons
    Patron my_patron1 = Patron("Forrest, Kara",100,0);
    my_lib.add_patron(my_patron1);
    Patron my_patron2 = Patron("Wuethrich, Benjamin",101,0);
    my_lib.add_patron(my_patron2);
    my_lib.add_patron(Patron("Buehler, Catriona",102,0));
    my_lib.add_patron(Patron("Schaerli, Tobias",103,0));
    my_lib.add_patron(Patron("Bieler, Ueli",104,0));
    Patron fake_patron(Patron("Shmoe, Joe",999,0));

    // try to add patron that already exists
    //my_lib.add_patron(my_patron1);

    // print list of patrons
    cout << "List of patrons:\n\n";
    vector<Patron> patrons = my_lib.get_patrons();
    for (int i = 0; i<patrons.size(); ++i) {
        cout << patrons[i].get_name() << ", " <<
            patrons[i].get_number() << endl;
    }

    // set library fees of two patrons
    my_lib.set_fee(my_patron1,10);
    my_lib.set_fee(my_patron2,15);

    // try to set fee for non-existing patron
    //my_lib.set_fee(Patron("NoName",999,0),99);

    // get and print list of debtors
    cout << "\nList of debtors:\n\n";
    vector<Patron> debtors = my_lib.get_debtors();
    for (int i = 0; i<debtors.size(); ++i) {
        cout << debtors[i].get_name() << ", " <<
            debtors[i].get_fees() << endl;
    }

    // check out book
    my_lib.check_out(my_book,patrons[2],Date(2014,Date::jan,31));

    // print transaction vector
    cout << "\nTransactions:\n";
    vector<Library::Transaction> transactions = my_lib.get_transactions();
    for (int i = 0; i<transactions.size(); ++i) {
        cout << transactions[i].b <<
            transactions[i].d << endl <<
            transactions[i].p.get_name() << endl;
    }

    // try to check out book which is already checked out
    //my_lib.check_out(my_book,patrons[2],Date(2014,Date::Month::jan,31));

    // try to check out book which doesn't exist in library
    //my_lib.check_out(fake_book,patrons[2],Date());

    // try to check out book for patron who doesn't exist
    //my_lib.check_out(my_book2,fake_patron,Date());

    // try to check out book for patron who owes fees
    my_lib.check_out(my_book2,my_patron2,Date());
}

void test_leapyear()
{
    if (leapyear(2000)) cout << "2000 is a leap year\n";
    if (leapyear(2004)) cout << "2004 is a leap year\n";
    if (leapyear(2005)) cout << "2005 is a leap year\n";
    if (leapyear(2100)) cout << "2100 is a leap year\n";
}

void test_lineardate()
{
    cout << "Jan 1, 2000 is day #" <<
        day_in_year(Date(2000,Date::jan,1)) <<
        " of the year.\n";
    cout << "Feb 29, 2000 is day #" <<
        day_in_year(Date(2000,Date::feb,29)) <<
        " of the year.\n";
    cout << "Mar 1, 2000 is day #" <<
        day_in_year(Date(2000,Date::mar,1)) <<
        " of the year.\n";

    cout << "Number of leap years since 1970:\n" <<
        "1971: " << n_leapyears(1971) << endl <<
        "1972: " << n_leapyears(1972) << endl <<
        "1973: " << n_leapyears(1973) << endl <<
        "1974: " << n_leapyears(1974) << endl <<
        "2000: " << n_leapyears(2000) << endl <<
        "2001: " << n_leapyears(2001) << endl <<
        "2101: " << n_leapyears(2101) << endl;

    cout << "Days since Jan 1, 1970:\n" <<
        "Jan 1, 1970: " << days_linear(Date(1970,Date::jan,1)) << endl <<
        "Mar 1, 2001: " << days_linear(Date(2001,Date::mar,1)) << endl <<
        "Jan 31, 2014: " << days_linear(Date(2014,Date::jan,31)) << endl <<
        "Nov 30, 2111: " << days_linear(Date(2111,Date::nov,30)) << endl;

    cout << "Day of week:\n" <<
        "Jan 1, 1970: " << day_of_week(Date(1970,Date::jan,1)) << endl <<
        "Sep 11, 2001: " << day_of_week(Date(2001,Date::sep,11)) << endl <<
        "Jan 31, 2014: " << day_of_week(Date(2014,Date::jan,31)) << endl;
}

int main()
try {
//    test_liber();
//    test_leapyear();
    test_lineardate();
}
catch (Date::Invalid&) {
    cerr << "error: Invalid date\n";
    return 1;
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << endl;
}
catch (...) {
    cerr << "Exception\n";
}
