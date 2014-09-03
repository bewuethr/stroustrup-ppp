
//
// This is example code from Chapter 10.5 "Reading and writing a file" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <fstream>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

struct Reading {           // a temperature reading
    int hour;              // hour after midnight [0:23]
    double temperature;    // in Fahrenheit
    Reading(int h, double t) :hour(h), temperature(t) { }
};

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Please enter input file name: ";
    string name;
    cin >> name;
    ifstream ist(name.c_str());    // ist reads from the file named "name"
    if (!ist) error("can't open input file ",name);

    cout << "Please enter name of output file: ";
    cin >> name;
    ofstream ost(name.c_str());    // ost writes to a file named "name"
    if (!ost) error("can't open output file ",name);

    vector<Reading> temps;    // store the readings here
    int hour;
    double temperature;
    while (ist >> hour >> temperature) {
        if (hour < 0 || 23 <hour) error("hour out of range");
        temps.push_back(Reading(hour,temperature));
    }

    for (int i=0; i<temps.size(); ++i)
        ost << '(' << temps[i].hour << ','
            << temps[i].temperature << ")\n";
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
