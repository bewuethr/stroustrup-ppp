
//
// This is example code from Chapter 17.4.3 "Ranges" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int main()
{
    double* pd = new double[3];
    pd[2] = 2.2;
    pd[4] = 4.4;
    pd[-3] = -3.3;

    double* p = new double;        // allocate a double
    double* q = new double[1000];  // allocate 1000 doubles

    q[700] = 7.7;                  // fine
    q = p;                         // let q point to the same as p
    double d = q[700];             // out-of-range access!
}

//------------------------------------------------------------------------------
