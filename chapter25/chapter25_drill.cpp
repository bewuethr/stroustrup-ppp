// Chapter 25, Drill

#include<iostream>
#include<iomanip>
#include<bitset>

using namespace std;

void ex1()
{
    int v = 1;
    for (int i = 0; i<sizeof(v)*8; ++i) {
        cout << v << '\n';
        v <<= 1;
    }
}

void ex2()
{
    unsigned int v = 1;
    for (int i = 0; i<sizeof(v)*8; ++i) {
        cout << v << '\n';
        v <<= 1;
    }
}

void print(short unsigned int sui)
{
    cout << dec << setw(5) << sui << ' ' << hex << setw(4) << sui << ' ' <<
        bitset<16>(sui) << '\n';
}

void ex3()
{
    short unsigned int sui = 0xffff;    // every bit set
    print(sui);
    sui = 0x0001;   // lowest bit set
    print(sui);
    sui = 0x8000;   // highest bit set
    print(sui);
    sui = 0x00ff;   // lowest byte set
    print(sui);
    sui = 0xff00;   // highest byte set
    print(sui);
    sui = 0x5555;   // every second bit set, lowest bit 1
    print(sui);
    sui = 0xaaaa;   // every second bit set, lowest bit 0
    print(sui);
}

void ex5()
{
    short unsigned int sui = 0;
    
    sui = ~0;       // set every bit
    print(sui);
    sui = 1;        // set lowest bit
    print(sui);
    sui = 1<<15;    // set highest bit
    print(sui);
    sui = (1 | 1<<1);   // set lowest byte
    sui |= sui<<2;
    sui |= sui<<4;
    print(sui);
    sui = ~sui;     // set highest byte
    print(sui);
    sui = 1;
    sui |= sui<<2;  // set every second bit, lowest bit 1
    sui |= sui<<4;
    sui |= sui<<8;
    print(sui);
    sui = ~sui;     // set every second bit, lowest bit 0
    print(sui);
}

int main()
try
{
    ex1();
    ex2();
    ex3();
    ex5();
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
