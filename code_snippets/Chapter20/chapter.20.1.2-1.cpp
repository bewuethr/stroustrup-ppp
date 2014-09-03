
//
// This is example code from Chapter 20.1.2 "Generalizing code" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double* get_from_jack(int* count);  // jack puts doubles into an array
// and returns the number of elements
// in *count
vector<double>* get_from_jill();    // Jill fills the vector

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);    
    vector<double>* jill_data = get_from_jill();    
    double h = -1;
    double* jack_high;    // jack_high will point to the element with the highest value
    double* jill_high;    // jill_high will point to the element with the highest value

    for (int i=0; i<jack_count; ++i)
        if (h< jack_data[i])
            jack_high = &jack_data [i];    // save address of largest element

    h = -1;
    vector<double>& v = *jill_data;
    for (int i=0; i<v.size(); ++i) 
        if (h<v[i])
            jill_high = &v[i];

    cout << "Jill's max: " << *jill_high
        << "; Jack's max: " << *jack_high;

    delete[] jack_data;
    delete jill_data;
}

//------------------------------------------------------------------------------

int main()
{
    fct();
}

//------------------------------------------------------------------------------

double* get_from_jack(int* count)
{
    if (!count)
        return 0;

    const int n = 10;

    double* arr = new double[n];

    if (arr)
    {
        *count = n;

        for (int i = 0; i < n; ++i)
            arr[i] = i;
    }

    return arr;
}

//------------------------------------------------------------------------------

vector<double>* get_from_jill()
{
    const int n = 10;

    vector<double>* arr = new vector<double>(n);

    if (arr)
    {
        for (int i = 0; i < n; ++i)
            (*arr)[i] = i;
    }

    return arr;
}

//------------------------------------------------------------------------------
