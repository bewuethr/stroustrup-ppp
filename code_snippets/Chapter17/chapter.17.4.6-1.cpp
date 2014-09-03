
//
// This is example code from Chapter 17.4.6 "Free store deallocation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

double* calc(int res_size, int max)    // leaks memory
{
    double* p = new double[max];
    double* res = new double[res_size];
    // use p to calculate results to be put in res
    return res;
}

//------------------------------------------------------------------------------

int main()
{
    double* r = calc(100,1000);
}

//------------------------------------------------------------------------------
