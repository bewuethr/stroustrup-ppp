
//
// This is example code from Chapter 17.3 "Memory, addresses, and pointers" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int  var = 17;
    int* ptr = &var;    // ptr holds the address of var

    char  ch = 'c';
    char* pc = &ch;     // pointer to char

    int  ii = 17;
    int* pi =&ii;       // pointer to int

    cout << "pc==" << pc
        << "; contents of pc==" << *pc << "\n"; 
    cout << "pi==" << pi
        << "; contents of pi==" << *pi << "\n";

    *pc ='x';    // ok: you can assign 'x' to the char pointed to by pc
    *pi = 27;    // ok: an int* points to an int so *pi is an int
    *pi = *pc;   // ok: you can assign a char (pc) to an int (pi)


    //int i = pi;  // error: can't assign an int* to an int
    //pi = 7;      // error: can't assign an int to an int*

    //pc = pi;     // error: can't assign int* to char*
    //pi = pc;     // error: can't assign char* to int*

    {
        char ch1 = 'a';
        char ch2 = 'b';
        char ch3 = 'c';
        char ch4 = 'd';
        //int* pi = &ch3; // point to ch3, a char-sized piece of memory
                        // error: we cannot assign a char* to and int*
                        //           but let's pretend we could
        *pi = 12345;    // write to an int-sized piece of memory
        *pi = 67890;
    }
}

//------------------------------------------------------------------------------
