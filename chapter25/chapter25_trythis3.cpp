// Chapter 25, Try This 3: get bits example to work, try a few values

#include<iostream>
#include<iomanip>
#include<bitset>

using namespace std;

int main()
{
    int i;
    while (cin>>i)
        cout << dec << i << " == "
        << hex << "0x" << setw(8) << setfill('0') << i << " == "
        << bitset<8*sizeof(int)>(i) << '\n';
}
