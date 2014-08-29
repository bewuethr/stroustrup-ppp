// Chapter 10, exercise 03: read data from pics_and_txt/raw_temps.txt into a
// vector, calculate mean and median temperatures

#include "../lib_files/std_lib_facilities.h"

// type for a temperature reading
struct Reading {
    int hour;           // hour after midnight [0:23]
    double temperature; // in Fahrenheit
    Reading() :hour(0), temperature(0) { }
    Reading(int h, double t) :hour(h), temperature(t) { }
};

bool operator<(const Reading& r1, const Reading& r2)
{
    return r1.temperature < r2.temperature;
}

ostream& operator<<(ostream& os, const Reading& r)
{
    return os << r.hour << ' ' << r.temperature;
}

istream& operator>>(istream& is, Reading& r)
{
    int hour;
    double temperature;
    is >> hour >> temperature;
    if (!is) return is;
    r = Reading(hour,temperature);
    return is;
}

const int max_temp = 108;
const int min_temp = -44;

// read Readings into vector from file
void fill_from_file(vector<Reading>& readings, const string& name)
{
    ifstream ist(name.c_str());
    if (!ist) error("can't open input file ",name);
    Reading r;
    while (ist >> r) {
        if (r.hour<0 || r.hour>23) error("hour out of range");
        if (r.temperature<min_temp || r.temperature>max_temp)
            error("temperature out of range");
        readings.push_back(r);
    }
}

int main()
try {
    vector<Reading> readings;
    fill_from_file(readings,"pics_and_txt/raw_temps.txt");

    // calculate median temperature
    sort(readings.begin(),readings.end());
    double median = readings[readings.size()/2].temperature;

    // calculate average temperature
    double sum = 0;
    for (int i = 0; i<readings.size(); ++i) {
        sum += readings[i].temperature;
    }
    double avg = sum / readings.size();

    // output
    cout << "median temperature: " << median << " F" << endl;
    cout << "average temperature: " << avg << " F" << endl;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
