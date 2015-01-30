// Chapter 25, exercise 7: write out the hexadecimal values from 0 to 400; write
// out the hexadecimal values from -200 to 200

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    cout << "0 to 400:\n\n";
    for (int i = 0; i<=400; ++i)
        cout << hex << i << (i%16 ? '\t' : '\n');

    cout << "\n\n-200 to 200:\n\n";
    for (int i = -200; i<=200; ++i)
        cout << hex << i << (i%8 ? '\t' : '\n');
}
