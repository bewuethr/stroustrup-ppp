// Chapter 24, Try This 1: replace 333 in example with 10

#include<iostream>
#include<iomanip>

int main()
{
    float x = 1.0/10;
    float sum = 0;
    for (int i = 0; i<10; ++i) sum += x;
    std::cout << std::setprecision(15) << sum << '\n';
}