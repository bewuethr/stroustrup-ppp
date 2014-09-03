
//
// This is example code from Chapter 25.7 "Drill" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    // for int
    {
        int v = 1;

        for (int i = 0; i<sizeof(v)*8; ++i) 
        { 
            cout << v << ' '; v <<=1; 
        }
    }

    // for unsigned int
    {
        unsigned int v = 1;

        for (int i = 0; i<sizeof(v)*8; ++i) 
        { 
            cout << v << ' '; v <<=1; 
        }
    }
}

//------------------------------------------------------------------------------
