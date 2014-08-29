// Chapter 05, exercise 06: Celsius/Fahrenheit converter

#include "../lib_files/std_lib_facilities.h"

double ctof(double c)
// converts Celsius to Fahrenheit, [°F] = [°C] * 9/5 + 32
{
    if (c<-273.15) error("Temperature below absolute zero!");
    double f = c * 9.0/5.0 + 32;
    return f;
}

double ftoc(double f)
// converts Fahrenheit to Celsius, [°C] = ([°F] - 32) * 5/9
{
    if (f<-459.67) error("Temperature below absolute zero!");
    double c = (f - 32) * 5.0/9.0;
    return c;
}

int main()
try {
    double temp = 0;   // declare input variable
    char unit = 0;  // unit (Fahrenheit or Celsius)
    double t_conv = 0;  // converted temperature
    char unit_conv = 0; // unit after conversion

    cout << "Enter temperature to be converted and unit (C or F)\n";
    cin >> temp >> unit;       // retrieve temperature to input variable
    if (unit=='c' || unit=='C') {
        t_conv = ctof(temp);    // convert temperature
        unit_conv = 'F';
    }
    else if (unit=='f' || unit=='F') {
        t_conv = ftoc(temp);    // convert temperature
        unit_conv = 'C';
    }
    else error("Illegal unit, must be C or F");
    cout << t_conv << ' ' << unit_conv << endl;      // print out converted temperature
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
