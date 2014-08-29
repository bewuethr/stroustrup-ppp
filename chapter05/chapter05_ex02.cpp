// Chapter 05, exercise 02: find errors in given code, correct them
// Exercise 03: throw error when given temperature is below absolute zero
// Exercise 04: Handle error inside ctok()
// Exercise 05: add Kelvin to Celsius conversion

#include "../lib_files/std_lib_facilities.h"

double ctok(double c)
// converts Celsius to Kelvin
{
    if (c<-273.15) error("Temperature below absolute zero!");
    double k = c + 273.15;
    return k;
}

double ktoc(double k)
// converts Kelvin to Celsius
{
    if (k<0) error("Temperature below absolute zero!");
    double c = k - 273.15;
    return c;
}

int main()
try {
    double temp = 0;   // declare input variable
    char unit = 0;  // unit (Kelvin or Celsius)
    double t_conv = 0;  // converted temperature
    char unit_conv = 0; // unit after conversion

    cout << "Enter temperature to be converted and unit (C or K)\n";
    cin >> temp >> unit;       // retrieve temperature to input variable
    if (unit=='c' || unit=='C') {
        t_conv = ctok(temp);    // convert temperature
        unit_conv = 'K';
    }
    else if (unit=='k' || unit=='K') {
        t_conv = ktoc(temp);    // convert temperature
        unit_conv = 'C';
    }
    else error("Illegal unit, must be C or K");
    cout << t_conv << ' ' << unit_conv << endl;      // print out temperature
    return 0;
}
catch (exception& e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Unknown exception!\n";
    return 2;
}
