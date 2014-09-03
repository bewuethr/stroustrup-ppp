
//
// This is example code from Chapter 27.6.1 "Output" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <stdio.h>

//------------------------------------------------------------------------------

void f(const char* p)
{
    printf("Hello, world\n");
    printf(p);
}

//------------------------------------------------------------------------------

int printf(const char* format, ...);

//------------------------------------------------------------------------------

void f1(double d, char* s, int i, char ch)
{
    printf("double %g string %s int %d char %c\n", d, s, i, ch);
}

//------------------------------------------------------------------------------

char a[] = { 'a', 'b' };        // no terminating 0

//------------------------------------------------------------------------------

void f2(char* s, int i) 
{
    printf("goof %s\n", i);     /* uncaught error */
    printf("goof %d: %s\n", i); /* uncaught error */
    printf("goof %s\n", a);     /* uncaught error */

}

//------------------------------------------------------------------------------

int fprintf(FILE* stream, const char* format, ...);

//------------------------------------------------------------------------------

int main()
{
    fprintf(stdout,"Hello, World!\n"); // exactly like printf("Hello, World!\n");
    FILE* ff = fopen("My_file","w");   // open My_file for writing
    fprintf(ff,"Hello, World!\n");     // write "Hello, World!\n" to My_file
    fclose(ff);
}

//------------------------------------------------------------------------------
