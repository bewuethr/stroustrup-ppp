// Chapter 25, exercise 11: like exercise 10, but keep the bits in a bitset<32>

#include<iostream>
#include<bitset>

using namespace std;
    
int main()
{
    bitset<32> bs;
    bs = 15121<<10; // PFN
    bs |= 6<<4;     // CCA
    bs[3] = 1;      // nonreachable
    bs[0] = 1;      // global
    cout << "Using a bitset<32>:\n"
        << "PFN: " << ((bs>>10)&bitset<32>(0x3fffff)).to_ulong() << '\n'
        << "CCA: " << ((bs>>4)&bitset<32>(0x7)).to_ulong() << '\n'
        << "nonreachable: " << bs[3] << '\n'
        << "dirty: " << bs[2] << '\n'
        << "valid: " << bs[1] << '\n'
        << "global: " << bs[0] << '\n';
}
