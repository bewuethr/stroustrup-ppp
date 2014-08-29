// Chapter 04, exercise 08: grains of rice on a chess board
// Exercise 09: calculate value for 64 fields

#include "../lib_files/std_lib_facilities.h"

int main()
{
    double on_square = 1;
    double total = 0;
    cout << "Square" << '\t' << "Grains" << '\t' << "Total\n";
    for (int square = 1; square<=64; ++square) {
        total += on_square;
        cout << square << '\t' << on_square << '\t' << total << endl;
        on_square *= 2;
    }
    return 0;
}
