// Chapter 21, exercise 12: provide a GUI for querying a file of Orders, e.g.:
// "Find all orders from Joe", "Find the total value of orders in file Hardware"
// and "List all orders in file Clothing". Design non-GUI interface first.

#include "chapter21_ex11_Simple_window.h"

//------------------------------------------------------------------------------

void print_menu()
{
    cout << "What would you like to do?\n"
        << "1 - Enter input file name\n"
        << "2 - Find orders by customer name\n"
        << "3 - Get total value of orders in file\n"
        << "4 - List all orders in file\n"
        << "0 - Exit\n";
}

//------------------------------------------------------------------------------

string get_ifname()
{
    cout << "\nEnter input file name: ";
    string s;
    cin >> s;
    cout << '\n';
    return s;
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

void orders_by_name(const string& ifname)
{
    if (!file_check(ifname)) return;

    cout << "\nEnter customer name: ";
    cin.ignore();   // skip past \n from last entry
    string cname;
    getline(cin,cname);

    vector<Order::Order> vo;
    Order::read_orders_from_file(vo,ifname);
    cout << '\n';
    for (int i = 0; i<vo.size(); ++i) {
        if (vo[i].name() == cname)
            cout << vo[i] << '\n';
    }
}

//------------------------------------------------------------------------------

void total_value(const string& ifname)
{
    if (!file_check(ifname)) return;
    double val_t = Order::get_value(ifname);
    cout << "\nTotal value of orders in '" << ifname << "': " << val_t << "\n\n";
}

//------------------------------------------------------------------------------

void list_orders(const string& ifname)
{
    if (!file_check(ifname)) return;

    vector<Order::Order> vo;
    Order::read_orders_from_file(vo,ifname);
    cout << '\n';
    for (int i = 0; i<vo.size(); ++i)
        cout << vo[i] << '\n';
}

//------------------------------------------------------------------------------

int main()
try {
    string ifname;

    bool keep_running = true;
    while (keep_running) {
        print_menu();
        int n;
        cin >> n;
        if (!cin) {
            cout << "\nPlease enter a number\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        switch (n) {
        case 0:         // Exit
            keep_running = false;
            break;
        case 1:         // Get input file name
            ifname = get_ifname();
            break;
        case 2:         // Find orders by customer name
            orders_by_name(ifname);
            break;
        case 3:         // Get total value of orders
            total_value(ifname);
            break;
        case 4:         // List all orders in file
            list_orders(ifname);
            break;
        default:
            cout << "\nEnter a number between 1 and 4\n\n";
            break;
        }

    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}