
//
// This is example code from Chapter 17.4.6 "Free store deallocation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

double* calc(int res_size, int max)
// the caller is responsible for the memory allocated for res
{
    double* p = new double[max];
    double* res = new double[res_size];
    // use p to calculate results to be put in res
    delete[] p;    // we don't need that memory any more: free it
    return res;
}

//------------------------------------------------------------------------------

int main()
{
    double* r = calc(100,1000);
    // use r
    delete[] r;    // we don't need that memory any more: free it
}

//------------------------------------------------------------------------------
