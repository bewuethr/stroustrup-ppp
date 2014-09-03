
//
// This is example code from Chapter 20.1 "Storing and processing data" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double* get_from_jack(int* count);  // jack puts doubles into an array
                                    // and returns the number of elements
                                    // in *count
vector<double>* get_from_jill();    // Jill fills the vector

//------------------------------------------------------------------------------

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);    
    vector<double>* jill_data = get_from_jill();    
    // ... process ...
    delete[] jack_data;
    delete jill_data;
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

int main()
{
    fct();
}

//------------------------------------------------------------------------------
