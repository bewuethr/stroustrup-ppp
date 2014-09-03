
//
// This is example code from Chapter 8.5.6 "Call-by-value vs. call-by-reference" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void f(int a, int& r, const int& cr)
{
    ++a;    // change the local a
    ++r;    // change the object referred to by r
    //++cr; // error: cr is const
}

//------------------------------------------------------------------------------

void g(int a, int& r, const int& cr)
{
    ++a;        // change the local a
    ++r;        // change the object referred to by r
    int x = cr; // read the object referred to by r
}

//------------------------------------------------------------------------------

int main()
{
    int x = 0;
    int y = 0;
    int z = 0;

    g(x,y,z);   // x==0; y==1; z==0
    //g(1,2,3); // error: reference argument r needs a variable to refer to
    g(1,y,3);   // ok: since cr is const we can pass a literal
    // means: int __compiler_generated = 3; g(1,y,__compiler_generated) 
}

//------------------------------------------------------------------------------

int incr1(int a) { return a+1; } // return the new value as the result
void incr2(int& a) { ++a; }      // modify object passed as reference

void foo()
{
    int x = 7;
    x = incr1(x); // pretty obvious
    incr2(x);     // pretty obscure
}

//------------------------------------------------------------------------------

void larger(vector<int>& v1, vector<int>& v2)
// make each element in v1 the larger of  the corresponding elements in v1 and  v2
{
    for (int i=0; i<v1.size(); ++i)
        if (v1[i]<v2[i])
            swap(v1[i],v2[i]);
}

//------------------------------------------------------------------------------

void f()
{
    vector<int> vx;
    vector<int> vy;
    // read vx and vy from input
    larger(vx,vy);
    // ...
}

//------------------------------------------------------------------------------
