
//
// This is example code from Chapter 19.5.1 "Potential resource management problems" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <stdexcept>
#include <vector>

using std::vector;

//------------------------------------------------------------------------------

namespace N1
{
    void suspicious(int s, int x)
    {
        int* q = new int[x]; // acquire memory
        int* p = new int[s]; // acquire memory
        // ...
        if (x) p = q;        // make p point to another object
        // ...
        delete[] p;          // release memory
    }
}

//------------------------------------------------------------------------------

namespace N2
{
    void suspicious(int s, int x)
    {
        int* p = new int[s]; // acquire memory
        // ...
        if (x) return;
        // ...
        delete[] p;          // release memory
    }
}

//------------------------------------------------------------------------------

namespace N3
{
    void suspicious(int s, int x)
    {
        int* p = new int[s]; // acquire memory
        vector<int> v;
        // ...
        if (x) p[x] = v.at(x);
        // ...
        delete[] p;          // release memory
    }
}

//------------------------------------------------------------------------------

namespace N4
{
    void suspicious(int s, int x)
    {
        int* p = new int[s]; // acquire memory
        vector<int> v;
        // ...
        try {
            if (x) p[x] = v.at(x);
            // ...
        } catch (...) {      // catch every exception
            delete[] p;      // release memory
            throw;           // re-throw the exception
        }
        // ...
        delete[] p;          // release memory
    }
}

//------------------------------------------------------------------------------

namespace N5
{
    void suspicious(vector<int>& v, int s)
    {
        int* p = new int[s];
        vector<int>v1;
        // ...
        int* q = new int[s];
        vector<double> v2;
        // ...
        delete[] p;
        delete[] q;
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    vector<int> v(100);

    N1::suspicious(4,4);
    N2::suspicious(4,4);
    N3::suspicious(4,4);
    N4::suspicious(4,4);
    N5::suspicious(v,4);
}
catch (std::exception& e) {
    std::cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    std::cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
