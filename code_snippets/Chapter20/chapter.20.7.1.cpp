
//
// This is example code from Chapter 20.7.1 "Insert and erase" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int initializer[7] = {1,2,3,4,5,6,7};
    int* first = initializer;
    int* last  = initializer+7;

    //To compare, we'll do exactly the same with a vector:
    {
        vector<int> v(first, last);
        vector<int>::iterator p = v.begin(); // take a vector
        ++p; ++p; ++p;                       // point to its 3rd element
        vector<int>::iterator q = p;
        ++q;                                 // point to it's 4th element

        p = v.insert(p,99);                  // p points at the inserted element
        p = v.erase(p);                      // p points at the element after the erased one
    }
    //To compare, we'll do exactly the same with a list:
    {
        list<int> v(first, last);
        list<int>::iterator p = v.begin();   // take a list
        ++p; ++p; ++p;                       // point to its 3rd element
        list<int>::iterator q = p;
        ++q;                                 // point to it's 4th element
    }
}

//------------------------------------------------------------------------------
