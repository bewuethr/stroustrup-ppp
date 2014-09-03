
//
// This is example code from Chapter 18.5.3 "Array initialization" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int strlen(const char* p)     // similar to the standard-library strlen()
{
    int n = 0;
    while (p[n]) ++n;
    return n;
}

//------------------------------------------------------------------------------

int main()
{
    char ac[ ] = "Beorn";                   // array of 6 chars
    char* pc = "Howdy";                     // pc points to an array of 6 chars
    int ai[ ] = { 1, 2, 3, 4, 5, 6 };       // array of 6 ints
    int ai2[100] = { 0,1,2,3,4,5,6,7,8,9 }; // the last 90 elements are initialized to 0
    double ad[100] = { };                   // all elements initialized to 0.0
    char chars[ ] = { 'a', 'b', 'c' };      // no terminating 0!
}

//------------------------------------------------------------------------------
