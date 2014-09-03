
//
// This is example code from Chapter 26.6.1 "Timing" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <ctime>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

void do_something()
{
    static int i = 0;
    ++i;
}

//------------------------------------------------------------------------------

int main()
{
    int n = 10000000;           // repeat do_somenting() n times

    clock_t t1 = clock();
    if (t1 == clock_t(-1)) {    // clock_t(-1) means "clock() didn't work"
        cerr << "sorry, no clock\n";
        exit(1);
    }

    for (int i = 0; i<n; i++) do_something();    // timing loop

    clock_t t2 = clock();
    if (t2 == clock_t(-1)) {
        cerr << "sorry, clock overflow\n";
        exit(2);
    }
    cout << "do_something() " << n << " times took "
         << double(t2-t1)/CLOCKS_PER_SEC << " seconds"
         << " (measurement granularity: "
         << CLOCKS_PER_SEC << " of a second)\n";
}

//------------------------------------------------------------------------------
