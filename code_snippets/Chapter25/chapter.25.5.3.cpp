
//
// This is example code from Chapter 25.5.3 "Signed and unsigned" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

void infinite()
{
    unsigned char max = 160;    // very large
    for (signed char i=0; i<max; ++i) cout << int(i) << endl;
}

//------------------------------------------------------------------------------

template<class T> void print(T i) { cout << i << '\t'; }

//------------------------------------------------------------------------------

void print(char i) { cout << int(i) << '\t'; }

//------------------------------------------------------------------------------

void print(signed char i) { cout << int(i) << '\t'; }

//------------------------------------------------------------------------------

void print(unsigned char i) { cout << int(i) << '\t'; }

//------------------------------------------------------------------------------

int main()
{
    vector<int> v;
    // ...
    for (int i = 0; i<v.size(); ++i) cout << i << endl;
    
    for (vector<int>::size_type i = 0; i<v.size(); ++i) cout << i << endl;
    
    for (vector<int>::iterator p = v.begin(); p!=v.end(); ++p) cout << p-v.begin() << endl;

    // ...
    {
        unsigned int ui = -1;
        int si = ui;
        int si2 = ui+2;
        unsigned ui2 = ui+2;
    }

    // What happens if an integer overflows? Consider:

    short int i = 0;
    while (++i) print(i); // print i as an integers followed by a space

    int si = 257;         // doesn't fit into a char
    char c = si;          // implicit conversion to char
    unsigned char uc = si;
    signed char sc = si;
    print(si); print(c); print(uc); print(sc); cout << endl;

    si = 129;             // doesn't fit into a signed char
    c = si;
    uc = si;
    sc = si;
    print(si); print(c); print(uc); print(sc);
}

//------------------------------------------------------------------------------
