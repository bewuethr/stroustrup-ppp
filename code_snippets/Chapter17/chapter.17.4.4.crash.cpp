
//
// This is example code from Chapter 17.4.4 "Initialization" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

class X
{
public:
    X() {}          // default constructor
};

//------------------------------------------------------------------------------

class Y
{
public:
    Y(int) {}       // one argument constructor
                    // there is no default constructor
};

//------------------------------------------------------------------------------

int main()
{
    double* p0;                    // uninitialized: likely trouble
    double* p1 = new double;       // get (allocate) an uninitialized double
    double* p2 = new double(5.5);  // get a double initialized to 5.5
    double* p3 = new double[5];    // get (allocate) 5 uninitialized doubles

    //Obviously, declaring p0 without initializing it is asking for trouble. Consider:
    *p0 = 7.0;

    double* p4 = new double[5];
    for (int i = 0; i<5; ++i) p4[i] = i;

    X* px1 = new X;                // one default initialized X
    X* px2 = new X[17];            // 17 default initialized Xs

    //Y* py1 = new Y;                // error: no default constructor
    //Y* py2 = new Y[17];            // error: no default constructor
    Y* py3 = new Y(13);            // ok: initialized to Y(13)
}

//------------------------------------------------------------------------------
