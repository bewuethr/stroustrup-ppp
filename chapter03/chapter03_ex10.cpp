// Chapter 03, exercise 10: take operation followed by operands, calculate

#include "../lib_files/std_lib_facilities.h"

int main()
{
	string operation;	// Can be + - * / plus minus mul div
	double d1 = 0;
	double d2 = 0;
	double res = 0;
	cout << "Please enter an operation (+, -, *, /, plus, minus, mul, div)\n"
        << "followed by two operands\n";
	while (cin >> operation >> d1 >> d2) {
		if (operation == "+" || operation == "plus") res = d1 + d2;
		else if (operation == "-" || operation == "minus") res = d1 - d2;
		else if (operation == "*" || operation == "mul") res = d1 * d2;
		else if (operation == "/" || operation == "div") {
			if (d2 == 0)
				operation = "divzero";
			else
				res = d1 / d2;
		}
		else operation = "unknown";
		if (operation == "unknown")
			cout << "I don't know this operator!\n";
		else if (operation == "divzero")
			cout << "No division by zero!\n";
		else
			cout << d1 << ' ' << operation << ' ' << d2 << " = " << res << '\n';
		cout << "Try again\n";
	}
	return 0;
}
