
//
// This is example code from Chapter 17.4.2 "Access through pointers" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int main()
{
    double* p = new double[4]; // allocate 4 doubles on the free store
    double x = *p;       // read the (first) object pointed to by p
    double y = p[2];     // read the third object pointed to by p

    *p = 7.7;            // write to the (first) object pointed to by p
    p[2] = 9.9;          // write to the third object pointed to by p

    {
        double x = *p;   // read the object pointed to by p
        *p = 8.8;        // write to the object pointed to by p
    }

    {
        double x = p[3]; // read the fourth object pointed to by p
        p[3] = 4.4;      // write to the fourth object pointed to by p
        double y = p[0]; // p[0] is the same as *p
    }
}

//------------------------------------------------------------------------------
