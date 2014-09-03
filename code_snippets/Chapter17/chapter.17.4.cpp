
//
// This is example code from Chapter 17.4 "Free store and pointers" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int main()
{
    double* p = new double[4];    // allocate 4 doubles on the free store
    //char*   q = new double[4];    // error: double* assigned to char*
}

//------------------------------------------------------------------------------
