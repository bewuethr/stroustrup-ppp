// Chapter 03, exercise 07: ask user to enter three strings, output the strings
// in alphabetical sequence separated by commas

#include "../lib_files/std_lib_facilities.h"

int main()
{
	string s1 = " ";
	string s2 = " ";
	string s3 = " ";
	string smallest = " ";
	string middle = " ";
	string largest = " ";
	cout << "Enter three strings separated by spaces\n";
	cin >> s1 >> s2 >> s3;
	if (s1 <= s2) {
		if (s1 <= s3) {
			smallest = s1;
			if (s2 <= s3) {
				middle = s2;
				largest = s3;
			}
			else {
				middle = s3;
				largest = s2;
			}
		}
		else {
			smallest = s3;
			middle = s1;
			largest = s2;
		}
	}
	else {
		if (s1 > s3) {
			largest = s1;
			if (s2 <= s3) {
				smallest = s2;
				middle = s3;
			}
			else {
				smallest = s3;
				middle = s2;
			}
		}
		else {
			largest = s3;
			middle = s1;
			smallest = s2;
		}
	}
	cout << smallest << ", " << middle << ", " << largest << '\n';
	return 0;
}
