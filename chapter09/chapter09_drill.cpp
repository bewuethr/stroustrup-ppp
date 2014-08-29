// Chapter 09, drill

#include "../lib_files/std_lib_facilities.h"
#include "Chrono.h"

void chapter941()
{
    using namespace Chrono941;
    cout << "Chapter 9.4.1:\n";
    Date today;
    init_day(today,1978,6,25);
    Date tomorrow = today;
    add_day(tomorrow,1);
    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;
    Date invalid_date;
    init_day(invalid_date,2004,13,-5);
}

void chapter942()
{
    using namespace Chrono942;
    cout << "Chapter 9.4.2:\n";
    Date today(1978,6,25);  // colloquial style
    Date tomorrow = today;  // copy constructor
    tomorrow.add_day(1);
    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;
    Date invalid_date = Date(2004,13,-5);   // verbose style
}

void chapter943()
{
    using namespace Chrono943;
    cout << "Chapter 9.4.3:\n";
    Date today(1978,6,25);  // colloquial style
    Date tomorrow = today;  // copy constructor
    tomorrow.add_day(1);
    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;
    Date invalid_date = Date(2004,13,-5);   // verbose style
}

void chapter971()
{
    using namespace Chrono971;
    cout << "Chapter 9.7.1:\n";
    Date today(1978,Date::jun,25);  // colloquial style
    Date tomorrow = today;  // copy constructor
    tomorrow.add_day(1);
    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;
    Date invalid_date = Date(2004,Date::dec,-5);   // verbose style
}

void chapter974()
{
    using namespace Chrono974;
    cout << "Chapter 9.7.4:\n";
    Date default_d;
    cout << "Default date: " << default_d << endl;
    Date today(1978,Date::jun,25);  // colloquial style
    Date tomorrow = today;  // copy constructor
    tomorrow.add_day(1);
    Date next_year = today;
    next_year.add_year(1);
    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;
    cout << "Next year: " << next_year << endl;
    Date invalid_date = Date(2004,Date::dec,-5);   // verbose style
}

int main()
try
{
    chapter974();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
