
//
// This is example code from Chapter 19.5.4 "Auto_ptr" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

using std::auto_ptr;
using std::vector;

//------------------------------------------------------------------------------

vector<int>* make_vec()    // make a filled vector
{
    auto_ptr< vector<int> > p(new vector<int>); // allocate on free store
    // fill the vector with data; this may throw an exception
    return p.release(); // return the pointer held by p
}

//------------------------------------------------------------------------------

int main()
try
{
    auto_ptr< vector<int> > p(make_vec());
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
