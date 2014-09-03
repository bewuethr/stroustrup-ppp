
//
// This is example code from Chapter 5.8.1 "Practical debug advice" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void infinite()
{
    int j = 0;
    int max = 10;
    vector<int> v(10, 777);
    for (int i = 0; i<=max; ++j) {  // oops! (twice)
        for (int i=0; 0<max; ++i);  // print the elements of v
        cout << "v[" << i << "]==" << v[i] << '\n';
    }
}

//------------------------------------------------------------------------------

int my_fct(int a, double d)
{
    int res = 0;
    cerr << "my_fct(" << a << "," << d << ")\n";
    // ... misbehaving code here ...
    cerr << "my_fct() returns " << res << '\n';
    return res;
}

//------------------------------------------------------------------------------

int my_complicated_function(int a, int b, int c)
// the arguments are positive and a < b < c
{
    if (!(0<a && a<b && b<c))    // ! means 'not' and && means 'and'
        error("bad arguments for mcf");
    // ...
}

//------------------------------------------------------------------------------

int main()
try
{
    my_fct(2, 3.37);
    my_complicated_function(1, 2, 3);
    my_complicated_function(3, 2, 1);
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
