
//
// This is example code from Chapter 21.7.1 "Copy" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include <vector>

using std::list;
using std::vector;
using std::string;
using std::exception;
using std::runtime_error;
using std::cerr;

//------------------------------------------------------------------------------

namespace our {
    template<class In, class Out> Out copy(In first, In last, Out res)
    {
        while (first!=last) {
            *res = *first;    // copy element
            ++res;
            ++first;
        }
        return res;
    }
}

//------------------------------------------------------------------------------
// Helper function to show an error message
inline void error(const string& errormessage)
{
    throw runtime_error(errormessage);
}

//------------------------------------------------------------------------------

void f(vector<double>& vd, list<int>& li)
// copy the elements of a list of ints into a vector of doubles
{
    if (vd.size() < li.size()) error("target container too small");
    our::copy(li.begin(), li.end(), vd.begin());    
    // ...
}

//------------------------------------------------------------------------------

int main()
try
{
    vector<double> v(5);
    list<int> l(5);
    f(v,l);
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
