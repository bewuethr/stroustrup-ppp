
//
// This is example code from Chapter 27.5.4 "A style issue" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

char* p1;      // p is a pointer to a char
char *p2;      /* p is something that you can dereference to get a char */
char c, *p, a[177], *f(); /* legal, but confusing */

//------------------------------------------------------------------------------

int main()
{
    char c = 'a';  /* termination character for input using f() */
    char* p = 0;   /* last char read by f() */
    char a[177];   /* input buffer */
    char* f();     /* read into buffer a; return pointer to first char read */
}

//------------------------------------------------------------------------------
