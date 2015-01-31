// Chapter 25, exercise 9: without using standard headers such as <limits>,
// compute the number of bits in an int and determine wether char is signed or
// unsigned

#include<iostream>

using namespace std;

int main()
{
    int n = 0;
    int i = 1;
    while (true) {
        cout << "1 at bit " << n << ": " << (i<<n) << '\n';
        if ((i<<n) < (i<<(n-1))) break;
        ++n;
    }
    cout << "int has " << n+1 << " bits (hitting the sign bit when shifting "
        << "by " << n << " positions).\n\n";
    char ch = -1;
    if (ch==-1)
        cout << "char is signed\n";
    else    // ch becomes 255
        cout << "char is unsigned\n";
}
