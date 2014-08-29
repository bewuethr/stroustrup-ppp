// Chapter 08, exercise 08: write simple function randint() to produce random
// numbers
// Exercise 09: write function that produces random number in a given range

#include "../lib_files/std_lib_facilities.h"
#include<climits>

unsigned int X_n = 0;

// initialise seed with clock
void init_seed()
{
    X_n = 66779;
}

// produces a pseudo-random number in the range [0:INT_MAX]
int randint()
{
    X_n = (48271*X_n) % INT_MAX;
    return X_n;
}

// return pseudo-random int between a and b
int rand_in_range(int a, int b)
{
    if (b <= a) error("b must be larger than a");
    int r = randint();

    return a + double(r)/INT_MAX*(b-a);
}

int main()
try
{
    init_seed();
    for (int i = 0; i<1000; ++i)
        cout << rand_in_range(950,1000) << endl;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
