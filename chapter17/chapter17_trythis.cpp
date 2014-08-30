// Chapter 17: Try This

#include "../lib_files/std_lib_facilities.h"

class A {
public:
    A() { cout << "A()\n"; }
    ~A() { cout << "~A()\n"; }
};

class B {
public:
    B() { cout << "B()\n"; }
    ~B() { cout << "~B()\n"; }
};

class C {
    A a;
    B b;
public:
    C() { cout << "C()\n"; }
    ~C() { cout << "~C()\n"; }
};

void f() {
    cout << "f() called\n";
    A a;
    B b;
    C c;
    cout << "End of f()\n";
}

int main()
try {
    cout << "the size of char is " << sizeof(char) << ' ' << sizeof('a') << endl;
    cout << "the size of int is " << sizeof(int) << ' ' << sizeof(2+2) << endl;
    int* p = 0;
    cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << endl;
    cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(1==1) << endl;
    cout << "the size of double is " << sizeof(double) << ' ' << sizeof(1.0) << endl;
    cout << "the size of float is " << sizeof(float) << ' ' << sizeof(float(1.0)) << endl;
    double* pd = 0;
    cout << "the size of double* is " << sizeof(double*) << ' ' << sizeof(pd) << endl;
    vector<int> v(10000);
    cout << "the size of vector<int>(10000) is " << sizeof(v) << endl;

    cout << "A a:\n";
    A a;

    cout << "B b:\n";
    B b;

    cout << "C c:\n";
    C c;

    f();

    for (int i = 0; i<3; ++i) {
        cout << "A a in for-loop:\n";
        A a;
        cout << "End of for-loop:\n";
    }

    cout << "End of main():\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
