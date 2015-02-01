// Chapter 25, exercise 10: write an example that initializes a PPN, then reads
// and prints each field value, then changes each field value (by assigning to
// the field) and prints the result. Repeat, but store the PPN information in a
// 32-bit unsigned integer and use bit manipulation operators to access the bits
// in the word.

#include<iostream>

using namespace std;
    
struct PPN {
    unsigned int PFN : 22;
    int : 3;
    unsigned int CCA : 3;
    bool nonreachable : 1;
    bool dirty : 1;
    bool valid : 1;
    bool global : 1;
};

int main()
{
    PPN pn;
    pn.PFN = 0;
    pn.CCA = 0;
    pn.nonreachable = 0;
    pn.dirty = 0;
    pn.valid = 0;
    pn.global = 0;
    cout << "PFN: " << pn.PFN << '\n'
        << "CCA: " << pn.CCA << '\n'
        << "nonreachable: " << pn.nonreachable << '\n'
        << "dirty: " << pn.dirty << '\n'
        << "valid: " << pn.valid << '\n'
        << "global: " << pn.global << '\n';
    pn.PFN = 15121;
    pn.CCA = 6;
    pn.nonreachable = 1;
    pn.dirty = 0;
    pn.valid = 0;
    pn.global = 1;
        cout << "\nAfter changing values:\n"
        << "PFN: " << pn.PFN << '\n'
        << "CCA: " << pn.CCA << '\n'
        << "nonreachable: " << pn.nonreachable << '\n'
        << "dirty: " << pn.dirty << '\n'
        << "valid: " << pn.valid << '\n'
        << "global: " << pn.global << '\n';

    unsigned int pni = 0;
    pni = 15121<<10;    // PFN
    pni |= 6<<4;        // CCA
    pni |= 1<<3;        // nonreachable
    pni |= 1;           // global
    cout << "\nUsing an unsigned int:\n"
        << "PFN: " << ((pni>>10)&0x3fffff) << '\n'
        << "CCA: " << ((pni>>4)&0x7) << '\n'
        << "nonreachable: " << ((pni>>3)&1) << '\n'
        << "dirty: " << ((pni>>2)&1) << '\n'
        << "valid: " << ((pni>>1)&1) << '\n'
        << "global: " << (pni&1) << '\n';
}
