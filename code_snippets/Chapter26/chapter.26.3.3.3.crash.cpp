
//
// This is example code from Chapter 26.3.3.3 "Loops" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

//------------------------------------------------------------------------------

int do_loop(vector<int>& vec) // messy function
// undisciplined loop
{
    int i;
    int sum;
    while(i<=vec.size()) sum+=vec[i];
    return sum;
}

//------------------------------------------------------------------------------

const int MAX=256;
char buf[MAX];         // fixed sized buffer

//------------------------------------------------------------------------------

char* read_line()      // dangerously sloppy
{
    int i = 0;
    char ch;
    while(cin.get(ch) && ch!='\n') buf[i++] = ch;
    buf[i+1] = 0;
    return  buf;
}

//------------------------------------------------------------------------------

int main()
{
    // dangerously sloppy:
    gets(buf);         // read a line into buf
    sprintf("%s",buf); // read a line into buf
}

//------------------------------------------------------------------------------
