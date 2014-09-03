
//
// This is example code from Chapter 17.4.1 "Free store allocation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int main()
{
    int  n  = 7;
    int* pi = new int;          // allocate one int
    int* qi = new int[4];       // allocate four ints (an array of 4 ints)

    double* pd = new double;    // allocate one double
    double* qd = new double[n]; // allocate n doubles (an array of n doubles)

    //Pointers to objects of different types are different types. For example:

    //pi = pd;    // error: can't assign a double* to an int*
    //pd = pi;    // error: can't assign an int* to a double*
}

//------------------------------------------------------------------------------
