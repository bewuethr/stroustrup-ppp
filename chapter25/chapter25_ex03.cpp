// Chapter 25, exercise 3: initialize a 32-bit signed int with the bit patterns
// and print the result:
// - all zeros
// - all ones
// - alternating ones and zeros (starting with leftmost one)
// - alternating zeros and ones (starting with leftomst zero)
// - 110011001100...
// - 001100110011...
// - all-one bytes and all-zero bytes starting with all-one byte
// - all-one bytes and all-zero bytes starting with all-zero byte
//
// Repeat with unsigned int.

#include<iostream>
#include<iomanip>
#include<bitset>

using namespace std;

template<class T>
void print(T s) { cout << bitset<32>(s) << " is " << s << '\n'; }

int main()
try
{
    cout << "Signed integer:\n";
    int s = 0x0;
    print(s);
    s = ~s;
    print(s);
    s = 0xaaaaaaaa;
    print(s);
    s = ~s;
    print(s);
    s = 0xcccccccc;
    print(s);
    s = ~s;
    print(s);
    s = 0xff00ff00;
    print(s);
    s = ~s;
    print(s);

    cout << "\nUnsigned integer:\n";
    unsigned int u = 0x0;
    print(u);
    u = ~u;
    print(u);
    u = 0xaaaaaaaa;
    print(u);
    u = ~u;
    print(u);
    u = 0xcccccccc;
    print(u);
    u = ~u;
    print(u);
    u = 0xff00ff00;
    print(u);
    u = ~u;
    print(u);
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
