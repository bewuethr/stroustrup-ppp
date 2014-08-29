// Chapter 04, exercise 03: read doubles into vector, print sum, smallest,
// largest and mean value

#include "../lib_files/std_lib_facilities.h"

int main()
{
    vector<double> distances;
    double distance;
    double total = 0;
    double smallest = 0;
    double greatest = 0;
    double mean = 0;
    while (cin>>distance) {
        if (distance>0) // only positive distances make sense
            distances.push_back(distance);
    }
    if (distances.size()==0)
        simple_error("No valid values entered");
    smallest = distances[0];
    greatest = distances[0];
    for (int i = 0; i<distances.size(); ++i) {
        total += distances[i];
        if (distances[i]<smallest)
            smallest = distances[i];
        if (distances[i]>greatest)
            greatest = distances[i];
    }
    mean = total / distances.size();
    cout << "Total distance: " << total << endl;
    cout << "Smallest distance: " << smallest << endl;
    cout << "Greatest distance: " << greatest << endl;
    cout << "Mean distance: " << mean << endl;
    return 0;
}
