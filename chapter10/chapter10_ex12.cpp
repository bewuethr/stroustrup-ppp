// Chapter 10, exercise 12: for a given file name and word: output each line of
// the file that contains the word
// Use pics_and_txt/chapter10_ex12_in.txt for input

// Produces range errors!

#include "../lib_files/std_lib_facilities.h"

int main()
try {
    string ifname;
    cout << "Enter input file name: ";
    cin >> ifname;
    ifstream ifs(ifname.c_str());
    if (!ifs) error("can't open input file",ifname);
    string word;
    cout << "Enter word to look for: ";
    cin >> word;

    int counter = 0;
    string current_line;
    while (getline(ifs,current_line)) {
        ++counter;
        for (int i = 0; i<current_line.size(); ++i) {
            if (current_line[i] == word[0] && current_line.size() >= i+word.size()-1) { // see if this is our word
                bool identical = true;
                for (int j = 1; j<word.size(); ++j) {
                    if (word[j] != current_line[i+j])
                        identical = false;
                }
                if (identical) {
                    cout << counter << ": " << current_line << endl;
                    break;
                }
            }
        }
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
