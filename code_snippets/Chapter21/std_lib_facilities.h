
//
// This is a standard library support code to the chapters of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef STD_LIB_FACILITIES_GUARD
#define STD_LIB_FACILITIES_GUARD 1

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include <string>

//------------------------------------------------------------------------------

#ifdef _MSC_VER
#include <hash_map>
using stdext::hash_map;
#else
#include <ext/hash_map>
using __gnu_cxx::hash_map;

namespace __gnu_cxx {

    template<> struct hash<std::string>
    {
        size_t operator()(const std::string& s) const
        {
            return hash<char*>()(s.c_str());
        }
    };

} // of namespace __gnu_cxx
#endif

//------------------------------------------------------------------------------

#define unordered_map hash_map

//------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------

#endif // STD_LIB_FACILITIES_GUARD
