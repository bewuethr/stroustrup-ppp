// Chapter 11, exercise 03: prompt user to enter several integers in any
// combination of octal, decimal and hexadecimal using the 0 and 0x prefixes,
// interpret them correctly and convert the to decimal form. Output values
// properly spaced like this:
// 0x43 hexadecimal converts to     67 decimal
// 0123 octal       converts to     83 decimal
//   65 decimal     converts to     65 decimal

#include "../lib_files/std_lib_facilities.h"

// enumerator for number formats
enum num_format {
        decimal, octal, hexadecimal
    };

ostream& operator<<(ostream& os, num_format nf)
{
    switch (nf) {
    case decimal:
        return os << "decimal\t";
    case octal:
        return os << "octal\t";
    case hexadecimal:
        return os << "hexadecimal";
    default:
        error("illegal value of number_format");
    }
}

// print one line of the solution
void printnum(int n, num_format nf)
{
    cout << showbase;
    switch (nf) {
    case decimal:
        cout << dec << setw(6) << n;
        break;
    case octal:
        cout << oct << setw(6) << n;
        break;
    case hexadecimal:
        cout << hex << setw(6) << n;
        break;
    }
    cout << ' ' << nf << "\tconverts to " << dec << setw(6) << n << ' ' << decimal << endl;
}

int main()
try {
    cout << "Enter space-separated integers in decimal, octal or hexadecimal notation" << endl
        << "(using 0 and 0x prefixes), any letter to finish:" << endl;
    int n = 0;
    char ch;
    while (cin>>ch) {
        if (ch=='0') {
            cin.get(ch);
            if (ch=='x') {          // we have '0x' - hexadecimal
                cin >> hex >> n;
                printnum(n,hexadecimal);
            }
            else if (isdigit(ch)) { // we have '0' - octal
                cin.unget();
                cin >> oct >> n;
                printnum(n,octal);
            }
            else {                  // '0' without a number - octal 0
                cin.unget();
                printnum(0,octal);
            }
        }
        else if (isdigit(ch)) {     // decimal
            cin.unget();
            cin >> dec >> n;
            printnum(n,decimal);
        }
        else break; // not a number
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
