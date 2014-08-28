// Chapter 11, exercise 14: read file of whitespace-separated numbers, output
// file of numbers using scientific format, precision 8 in four fields of 20
// characters per line
// Use pics_and_txt/chapter11_ex14_in.txt for input

#include "../lib_files/std_lib_facilities.h"

int main()
try {
    cout << "Enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ifs(iname.c_str());
    if (!ifs) error("can't open input file ",iname);

    // read numbers
    double d;
    vector<double> nums;
    while (ifs>>d)
        nums.push_back(d);

    // print numbers in given format
    cout << scientific << setprecision(8);
    for (int i = 0; i<nums.size(); ++i) {
        cout << setw(20) << nums[i];
        if (i+1%4 == 0) cout << endl;
    }

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
