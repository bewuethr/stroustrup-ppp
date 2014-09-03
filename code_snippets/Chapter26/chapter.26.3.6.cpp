
//
// This is example code from Chapter 26.3.6 "Finding assumptions that do not hold" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <algorithm>
#include <iostream>
#include <stdexcept>

//------------------------------------------------------------------------------

struct Bad_sequence {};

//------------------------------------------------------------------------------

struct Not_ordered {};

//------------------------------------------------------------------------------

template<class Iter, class T>
bool b2(Iter first, Iter last, const T& value)
{
    // check if [first:last) is a sequence:
    if (last<first) throw Bad_sequence();

    // check if the sequence is ordered:
    if (2<last-first) 
        for (Iter p = first+1; p<last; ++p)
            if (*p<*(p-1)) throw Not_ordered();

    // all's ok, call binary_search:
    return std::binary_search(first,last,value);
}

//------------------------------------------------------------------------------

/* Pseudo code

template<class Iter, class T>    // warning: contains pseudo code
bool binary_search (Iter first, Iter last, const T& value)
{
    if (test enabled) {
        if (Iter is a random access iterator) {
            // check if [first:last) is a sequence:
            if (last<first) throw Bad_sequence();
        }

        // check if the sequence is ordered:
        if (first!=last) {
            Iter prev = first;
            for (Iter p = ++first; p!=last; ++p, ++ prev)
                if (*p<*prev) throw Not_ordered();
        }

        //  now run binary_search
    }
}
*/

//------------------------------------------------------------------------------

int main()
try
{
    int a[] = {2,3,5,7,11,13,17,19};

    return b2(a, a+sizeof(a)/sizeof(a[0]), 7);
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
