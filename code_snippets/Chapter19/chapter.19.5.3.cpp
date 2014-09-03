
//
// This is example code from Chapter 19.5.3 "Guarantees" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <stdexcept>
#include <vector>

using std::vector;

//------------------------------------------------------------------------------

namespace N1
{
    vector<int>* make_vec()    // make a filled vector
    {
        vector<int>* p = new vector<int>;    // we allocate on free store
        // ... fill the vector with data; this may throw an exception ...
        return p;
    }
}

//------------------------------------------------------------------------------

namespace N2
{
    vector<int>* make_vec()    // make a filled vector
    {
        vector<int>* p = new vector<int>;    // we allocate on free store
        try {
            // fill the vector with data; this may throw an exception
            return p;
        }
        catch (...) {
            delete p;    // do our local cleanup
            throw;       // re-throw to allow our caller to deal with the fact
                         // that some_function() couldn't do what was
                         // required of it
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    vector<int>* p = N1::make_vec();
    vector<int>* q = N2::make_vec();
    delete q;
    delete p;
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
