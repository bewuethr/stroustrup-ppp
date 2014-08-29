// Chapter 04, exercise 02: fix program in §4.6.2 to always print out a median

#include "../lib_files/std_lib_facilities.h"

int main()
{
    vector<double> temps;
    double temp;
    while (cin>>temp)
        temps.push_back(temp);

    // compute median temperature
    sort(temps.begin(),temps.end());
    double median = 0;

    // if number of elements is odd, just take middle element
    if (temps.size()%2 == 1)
        median = temps[(temps.size()-1)/2];

    // if number of elements is even, calculate average of two middle elements
    else
        median = (temps[temps.size()/2] + temps[temps.size()/2 - 1]) / 2;
    cout << "Median temperature: " << median << endl;
    return 0;
}
