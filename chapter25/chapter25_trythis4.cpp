// Chapter 25, Try This 4: infinite loop example

#include<iostream>

using namespace std;

int main()
{
    unsigned char max = 160;
    for (signed char i = 0; i<max; ++i) // i will never reach max as after 127,
        cout << int(i) << '\n';         // it becomes -128
}
