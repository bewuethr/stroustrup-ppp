
//
// This is example code from Chapter 24.2 "Size, precision, and overflow" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <iomanip>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    {
        float x = 1.0/333;
        float sum = 0;
        for (int i=0; i<333; ++i) sum+=x;
        cout << setprecision(15) << sum << "\n";
    }

    {
        short y = 40000;
        int i = 1000000;
        cout << y << "   " << i*i << "\n";
    }

    {
        cout << "sizes: " << sizeof(int) << ' ' << sizeof(float) << '\n';
        int x = 2100000009;    // large int
        float f = x;
        cout << x << ' ' << f << endl;
        cout << setprecision(15) << x << ' ' << f << '\n';
    }
    {
        float f = 2.8;
        int x = f;
        cout << x << ' ' << f << endl;
    }
}

//------------------------------------------------------------------------------

void f(int i, double fpd)
{
    char c = i;      // yes: chars really are very small integers
    short s = i;     // beware: a large int may not fit in a short
    i = i+1;         // what if i was the largest int?
    long lg = i*i;   // beware: a long may not be any larger than an int
    float fps = fpd; // beware: a large double may not fit in a float
    i = fpd;         // truncates: e.g. 5.7 -> 5
    fps = i;         // you can loose precision (for very large int values)
}

//------------------------------------------------------------------------------

void g()
{
    char ch = 0;
    for (int i = 0; i<500; ++i) 
        cout << int(ch++) << '\t';
}

//------------------------------------------------------------------------------
