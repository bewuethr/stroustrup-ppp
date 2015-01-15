// Chapter 24, Try This 2: run conversion test functions, modify f() to print
// the variables

#include<iostream>
#include<iomanip>

using std::cout;

void f(int i, double fpd)
{
    cout << std::setprecision(15);
    char c = i;
    cout << "c = i: " << int(c) << '\n';
    short s = i;
    cout << "s = i: " << s << '\n';
    i = i+1;
    cout << "i + 1: " << i << '\n';
    long lg = i*i;
    cout << "lg = i*i: " << lg << '\n';
    float fps = fpd;
    cout << "fps = fpd: " << fps << '\n';
    i = fpd;
    cout << "i = pfd: " << i << '\n';
    fps = i;
    cout << "fps = i: " << fps << '\n';
}

void g()
{
    char ch = 0;
    for (int i = 0; i<500; ++i)
        cout << int(ch++) << '\t';
}

int main()
{
    g();
    cout << "\n\n";
    f(127,5.7);
    cout << '\n';
    f(33000,3.4e39);
    cout << '\n';
    f(2147483647,21.00000009e8);
}
