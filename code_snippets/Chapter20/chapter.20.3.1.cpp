
//
// This is example code from Chapter 20.3.1 "Back to the example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

template<class Iterator >
Iterator high(Iterator first, Iterator last)
// return an iterator to the element in [first:last) that has the highest value
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

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

    double* jack_high = high(jack_data,jack_data+jack_count);
    vector<double>& v = *jill_data;
    double* jill_high = high(&v[0],&v[0]+v.size());
    cout << "Jill's high " << *jill_high << "; Jack's high " << *jack_high;
    // ... 
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
