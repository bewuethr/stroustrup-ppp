// Chapter 03, exercise 11: ask for change, list values

#include "../lib_files/std_lib_facilities.h"

int main()
{
	int pennies = 0;
	int nickels = 0;
	int dimes = 0;
	int quarters = 0;
	int half_dollars = 0;
	int dollars = 0;
	cout << "How many pennies do you have?\n";
	cin >> pennies;
	cout << "How many nickels do you have?\n";
	cin >> nickels;
	cout << "How many dimes do you have?\n";
	cin >> dimes;
	cout << "How many quarters do you have?\n";
	cin >> quarters;
	cout << "How many half dollars do you have?\n";
	cin >> half_dollars;
	cout << "How many dollar coins do you have?\n";
	cin >> dollars;
	if (pennies > 0) {
		cout << "You have " << pennies;
		if (pennies == 1)
			cout << " penny.\n";
		else
			cout << " pennies.\n";
	}
	if (nickels > 0) {
		cout << "You have " << nickels;
		if (nickels == 1)
			cout << " nickel.\n";
		else
			cout << " nickels.\n";
	}
	if (dimes > 0) {
		cout << "You have " << dimes;
		if (dimes == 1)
			cout << " dime.\n";
		else
			cout << " dimes.\n";
	}
	if (quarters > 0) {
		cout << "You have " << quarters;
		if (quarters == 1)
			cout << " quarter.\n";
		else
			cout << " quarters.\n";
	}
	if (half_dollars > 0) {
		cout << "You have " << half_dollars;
		if (half_dollars == 1)
			cout << " half dollar.\n";
		else
			cout << " half dollars.\n";
	}
	if (dollars > 0) {
		cout << "You have " << dollars;
		if (dollars == 1)
			cout << " dollar.\n";
		else
			cout << " dollars.\n";
	}
	double val = pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * half_dollars + 100 * dollars;
	cout << "The value of all your coins is " << val << " cents ($" << val/100 << ").\n";
	return 0;
}
