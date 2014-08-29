// Chapter 10, exercise 11: produce sum of all whitespace-separated integers in
// input text file
// Use pics_and_txt/chapter10_ex11_in.txt for input

#include "../lib_files/std_lib_facilities.h"

bool whitespace(char ch)
{
    return (ch==' ' || ch=='\t' || ch=='\n');
}

int main()
try {
    string ifname;
    cout << "Enter input file name: ";
    cin >> ifname;
    ifstream ifs(ifname.c_str());
    if (!ifs) error("can't open input file",ifname);

    int sum = 0;
    char ch = 0;
    int i = 0;
    int count = 0;
    string s;
    while (ifs>>ch) {
        if (isdigit(ch)) {
            ifs.unget();
            if (ifs>>i) {
                if (ifs.eof() || ifs.get(ch) && whitespace(ch)) {
                    ++count;
                    sum += i;
                    cout << i << endl;
                }
                else {
                    ifs.unget();
                    ifs >> s;   // read string, wasn't a separate integer
                }
            }
            else error("can't read integer");
        }
        else {
            ifs.unget();
            ifs >> s;
        }
    }
    cout << "Sum of " << count << " whitespace-separated integers in file: " << sum << endl;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
