// Chapter 10, exercise 04, first part: modify program from exercise 02 t0
// include temperature suffix c or f

#include "../lib_files/std_lib_facilities.h"

// type for a temperature reading
struct Reading {
    int hour;           // hour after midnight [0:23]
    double temperature; // in Fahrenheit or Celsius
    char temp_scale;    // 'f' for Fahrenheit, 'c' for Celsius
    Reading(int h, double t, char ts) :hour(h), temperature(t), temp_scale(ts) { }
};

ostream& operator<<(ostream& os,const Reading& r)
{
    return os << r.hour << ' ' << r.temperature << r.temp_scale;
}

const char fahr = 'f';
const char cels = 'c';

const int max_temp = 107;
const int min_temp = -43;

// create random reading
Reading create_reading()
{
    int h = randint(0,24);
    double t = randint(min_temp,max_temp) + randint(-10,10)/double(10);
    char ts;
    randint(0,10)>4 ? ts = fahr : ts = cels;
    return Reading(h,t,ts);
}

// write vector of readings to file
void write_to_file(const vector<Reading>& r, const string& name)
{
    ofstream ost(name.c_str());
    if (!ost) error("can't open output file ",name);
    for (int i = 0; i<r.size(); ++i)
        ost << r[i] << endl;
}

int main()
try {
    vector<Reading> readings;
    for (int i = 0; i<250; ++i)
        readings.push_back(create_reading());

    write_to_file(readings,"pics_and_txt/raw_temps.txt");
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
