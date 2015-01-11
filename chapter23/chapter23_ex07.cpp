// Chapter 23, exercise 7: similar to exercise 6, but find credit card numbers
// in a file. Research the format of real credit card numbers.

#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include<regex>
#include<iomanip>

using namespace std;

int main()
try {
    cout << "Enter file name: ";
    string fname;
    cin >> fname;
    ifstream ifs(fname);
    if (!ifs) throw runtime_error("Can't open " + fname);

    // make sure numbers either are at the beginning of a line or preceded by a
    // non-digit, and either at the end of the line or followed by a non-digit
    // extract only the number, not the spaces (first capturing group)

    // amex: 15 digits, start with 34 or 37, grouping 4-6-5 digits
    // 3(4|7)\d{2}\s?\d{6}\s?\d{5}
    regex amex_num("(?:\\D|^)(3(?:4|7)\\d{2}\\s?\\d{6}\\s?\\d{5})(?:\\D|$)");

    // Visa: 13 or 16 digits, starts with 4
    // 4\d{3}(\s?\d{4}){2}\s?\d(\d{3})?
    regex visa_num("(?:\\D|^)(4\\d{3}(?:\\s?\\d{4}){2}\\s?\\d(?:\\d{3})?)(?:\\D|$)");

    // Mastercard: 16 digits, starts with 51-55
    // 5[1-5]\d{2}(\s?\d{4}){3}
    regex mc_num("(?:\\D|^)(5[1-5]\\d{2}(?:\\s?\\d{4}){3})(?:\\D|$)");

    // Discover: 16 digits, starts with 6011
    // 6011(\s?\d{4}){3}
    regex disc_num("(?:\\D|^)(6011(?:\\s?\\d{4}){3})(?:\\D|$)");

    // Diner's Club: 14 digits, starts with 300-305, 36 or 38, grouping 4-6-4 digits
    // 30[0-5]\d\s?\d{6}\s?\d{4}
    regex dc_num("(?:\\D|^)(30[0-5]\\d\\s?\\d{6}\\s?\\d{4})(?:\\D|$)");

    smatch matches;
    string line;
    int line_count = 0;
    while (getline(ifs,line)) {
        ++line_count;
        if (regex_search(line,matches,amex_num))
            cout << setw(3) << line_count << ": " << matches[1] << '\n';
        if (regex_search(line,matches,visa_num))
            cout << setw(3) << line_count << ": " << matches[1] << '\n';
        if (regex_search(line,matches,mc_num))
            cout << setw(3) << line_count << ": " << matches[1] << '\n';
        if (regex_search(line,matches,disc_num))
            cout << setw(3) << line_count << ": " << matches[1] << '\n';
        if (regex_search(line,matches,dc_num))
            cout << setw(3) << line_count << ": " << matches[1] << '\n';
    }
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}