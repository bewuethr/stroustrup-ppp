// Chapter 04, exercise 01: convert yen, euros and pounds into dollars (exchange
// rates as per Nov 14, 2013)

#include "../lib_files/std_lib_facilities.h"

int main()
{
    const double dollars_per_yen = 0.01;
    const double dollars_per_euro = 1.35;
    const double dollars_per_pound = 1.61;
    const double dollars_per_yuan = 0.16;
    const double dollars_per_kroner = 0.18;
    double amount = 0;
    char currency = ' ';
    cout << "Please enter an amount followed by a currency (Y, e, p, y or k):\n";
    cin >> amount >> currency;

    switch (currency) {
    case 'Y':
        cout << amount << " yen is " << dollars_per_yen*amount << " dollars\n";
        break;
    case 'e':
        cout << amount << " euro is " << dollars_per_euro*amount << " dollars\n";
        break;
    case 'p':
        cout << amount << " pound is " << dollars_per_pound*amount << " dollars\n";
        break;
    case 'y':
        cout << amount << " yuan is " << dollars_per_yuan*amount << " dollars\n";
        break;
    case 'k':
        cout << amount << " kroner is " << dollars_per_kroner*amount << " dollars\n";
        break;
    default:
        cout << "Sorry, I don't know the currency '" << currency << "'\n";
        break;
    }
	return 0;
}
