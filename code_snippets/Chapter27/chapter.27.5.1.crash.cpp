
//
// This is example code from Chapter 27.5.1 "C-style strings and const" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

const char* p = "asdf";    // now you can't write to "asdf" through p

//------------------------------------------------------------------------------

extern "C" char* strchr(const char* s, int c); /* find c in constant s (not C++) */

//------------------------------------------------------------------------------

int main()
{
    char* p = "asdf";
    p[2] = 'x'; 

    const char aa[] = "asdf";    /* aa is an array of constants */
    char* q = strchr(aa, 'd');   /* finds d */
    *q = 'x';                    /* change 'd' in a to 'x' */
}

//------------------------------------------------------------------------------
