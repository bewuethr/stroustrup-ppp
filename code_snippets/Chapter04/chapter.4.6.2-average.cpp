
//
// This is example code from Chapter 4.6.2 "A numeric example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// compute mean and median temperatures
int main()
{
    vector<double> temps;        // temperatures
    double temp;
    while (cin>>temp)            // read 
        temps.push_back(temp);   // put into vector

    // compute mean temperature:
    double sum = 0;
    for (int i = 0; i< temps.size(); ++i) sum += temps[i];
    cout << "Average temperature: " << sum/temps.size() << endl;

    // compute median temperature:
    sort(temps.begin(),temps.end()); // sort temps
    // "from the beginning to the end."
    cout << "Median temperature: " << temps[temps.size()/2] << endl;
}

//------------------------------------------------------------------------------
