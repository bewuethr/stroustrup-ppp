// Chapter 03, exercise 09: convert spelled-out numbers to digits

#include "../lib_files/std_lib_facilities.h"

int main()
{
	cout << "Enter a spelled-out number\n";
	string number;
	int res = -1;
	while (cin >> number) {
		if (number == "zero") res = 0;
		else if (number == "one") res = 1;
		else if (number == "two") res = 2;
		else if (number == "three") res = 3;
		else if (number == "four") res = 4;
		else if (number == "Quit" || number == "quit") return 0;
		if (res != -1)
			cout << "You entered the number " << res << '\n';
		else
			cout << "Not a number I know!\n";
		cout << "Please enter another number or \"Quit\"\n";
		res = -1;
	}

	return 0;
}
