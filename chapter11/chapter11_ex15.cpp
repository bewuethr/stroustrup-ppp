// Chapter 11, exercise 15: read file of whitespace-separated numbers, output
// them in order, one value per line. if a value occurs more than once, write
// the count of its occurrences on its line.
//
// example: "7 5 5 7 3 117 5" should give
//  3
//  5   3
//  7   2
//  117
//
// Use pics_and_txt/chapter11_ex15_in.txt for input

#include "../lib_files/std_lib_facilities.h"

int main()
try {
    cout << "Enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ifs(iname.c_str());
    if (!ifs) error("can't open input file ",iname);

    // read numbers
    int n;
    vector<int> numbers;
    while (ifs>>n)
        numbers.push_back(n);

    // sort and print
    sort(numbers.begin(),numbers.end());
    int counter = 1;
    //cout << numbers[0];
    for (int i = 0; i<numbers.size(); ++i) {
        if (i==0 || numbers[i]!=numbers[i-1]) {
            if (counter>1) cout << "\t" << counter;
            cout << endl;
            counter = 1;
            cout << numbers[i];
        }
        else ++counter;
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
