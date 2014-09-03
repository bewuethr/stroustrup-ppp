
//
// This is example code from Chapter 5.7 "Logic Errors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    vector<double> temps; // temperatures 

    double temp = 0;
    double sum = 0;
    double high_temp = 0;
    double low_temp  = 0;

    while (cin>>temp)         // read and put into temps
        temps.push_back(temp);

    for (int i = 0; i<temps.size(); ++i)
    {
        if(temps[i] > high_temp) high_temp = temps[i];  // find high
        if(temps[i] < low_temp)  low_temp  = temps[i];  // find low
        sum += temps[i];      // compute sum
    }

    cout << "High temperature: "    << high_temp        << endl;
    cout << "Low temperature: "     << low_temp         << endl;
    cout << "Average temperature: " << sum/temps.size() << endl;
}

//------------------------------------------------------------------------------
