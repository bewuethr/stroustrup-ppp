// Chapter 25, Try This 5: int, char, unsigned char and signed char example
// using si = 128

#include<iostream>

using namespace std;

template<class T> void print(T i) { cout << i << '\t'; }

void print(char i) { cout << int(i) << '\t'; }

void print(signed char i) { cout << int(i) << '\t'; }

void print(unsigned char i) { cout << int(i) << '\t'; }

int main()
{
    int si = 128;           // 00000000000000000000000010000000 is  128
    char c = si;            //                         10000000 is -128
    unsigned char uc = si;  //                         10000000 is  128
    signed char sc = si;    //                         10000000 is -128
    print(si);
    print(c);
    print(uc);
    print(sc);
    cout << '\n';
}
