
//
// This is example code from Chapter 8.5.7 "Argument checking and conversion" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

typedef double T;

void f(T x);

int main()
{
    T y = 3.1415;
    f(y);
    T x(y);        // initialize x with y (see §8.2.2)
}

//------------------------------------------------------------------------------

void f(double);

void g(int y)
{
    f(y);
    double x(y);
}

//------------------------------------------------------------------------------

void ff(int);

void gg(double x)
{
    ff(x);    // how would you know if this makes sense?
}

//------------------------------------------------------------------------------

void ggg(double x)
{
    int x1 = x;    // truncate x
    int x2 = int(x);

    ff(x1);
    ff(x2);

    ff(x);        // truncate x
    ff(int(x));
}

//------------------------------------------------------------------------------

void f(double) 
{
}

//------------------------------------------------------------------------------

void ff(int) 
{
}

//------------------------------------------------------------------------------
