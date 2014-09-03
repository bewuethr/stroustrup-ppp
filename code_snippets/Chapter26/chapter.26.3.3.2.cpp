
//
// This is example code from Chapter 26.3.3.2 "Resource management" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

//------------------------------------------------------------------------------

struct Bad_arg {};

//------------------------------------------------------------------------------

void do_resources1(int a, int b, const string& s) // messy function
      // undisciplined resource use
{
    FILE* f = fopen(s.c_str(),"r");    // open file (C style)
    int* p = new int[a];               // allocate some memory
    if (b<=0) throw Bad_arg();         // maybe throw an exception
    int* q = new int[b];               // allocate some more memory
    delete[] p;                        // deallocate the memory pointed to by p
}

//------------------------------------------------------------------------------

void do_resources2(int a, int b, const string& s) // less messy function
{
    ifstream is(s.c_str(),ios_base::in); // open file
    vector<int>v1(a);                  // create vector (owning memory)
    if (b<=0) throw Bad_arg();         // maybe throw an exception
    vector<int> v2(b);                 // create another vector (owning memory)
}

//------------------------------------------------------------------------------

int* var = 0;

//------------------------------------------------------------------------------

FILE* do_resources3(int a, int* p, const string& s) // messy function
      // undisciplined resource passing
{
    FILE* f = fopen(s.c_str(),"r");
    delete p;
    delete var;
    var = new int[27];
    return f;
}

//------------------------------------------------------------------------------

int main()
try
{
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
