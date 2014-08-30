// Chapter 17, exercise 01: output format of pointer value

// Exercise 02: how many bytes in an int, double, bool? Don't use sizeof()

#include "../lib_files/std_lib_facilities.h"

// take a pointer and return its address as an int
int ptr_to_int(void* ptr) {
    ostringstream oss;
    oss << ptr;
    istringstream iss(oss.str());
    int adr_int;
    iss >> hex >> adr_int;
    if (!iss) error("problem reading address");
    return adr_int;
}

struct X { int a, b, c; };

struct V {
    int a, b, c;
    virtual void f() { }
};

int main()
try {
    // 1
    cout << "Output format of a pointer:\n";
    int* pi = new int(0);
    cout << "int* pi is " << pi << "\n";
    cout << "&*pi is " << &*pi << "\n";
    cout << "&pi[1] is " << &pi[1] << "\n";
    delete pi;

    // 2
    cout << "\nNumber of bytes of different types:\n";
    pi = new int[2];
    pi[0] = 0;
    pi[1] = 0;
    // subtract pointers from each other to get size
    int var_size = ptr_to_int(&pi[1]) - ptr_to_int(pi);
    cout << "int: " << &pi[1] << " - " << pi << " = " << var_size << " bytes.\n";
    cout << "sizeof(int): " << sizeof(int) << "\n";
    delete[] pi;

    char* pc = new char[2];
    pc[0] = 0;
    pc[1] = 0;
    var_size = ptr_to_int(&pc[1]) - ptr_to_int(pc);
    cout << "char: " << (void*)&pc[1] << " - " << (void*)pc << " = " << var_size << " bytes.\n";
    cout << "sizeof(char): " << sizeof(char) << "\n";
    delete[] pc;

    double* pd = new double[2];
    pd[0] = 0;
    pd[1] = 0;
    var_size = ptr_to_int(&pd[1]) - ptr_to_int(pd);
    cout << "double: " << &pd[1] << " - " << pd << " = " << var_size << " bytes.\n";
    cout << "sizeof(double): " << sizeof(double) << "\n";
    delete[] pd;

    bool* pb = new bool[2];
    pb[0] = 0;
    pb[1] = 0;
    var_size = ptr_to_int(&pb[1]) - ptr_to_int(pb);
    cout << "bool: " << &pb[1] << " - " << pb << " = " << var_size << " bytes.\n";
    cout << "sizeof(bool): " << sizeof(bool) << "\n";
    delete[] pb;

    X* pX = new X[2];
    var_size = ptr_to_int(&pX[1]) - ptr_to_int(pX);
    cout << "struct X: " << &pX[1] << " - " << pX << " = " << var_size << " bytes.\n";
    cout << "sizeof(X): " << sizeof(X) << "\n";

    V* pV = new V[2];
    var_size = ptr_to_int(&pV[1]) - ptr_to_int(pV);
    cout << "struct V: " << &pV[1] << " - " << pV << " = " << var_size << " bytes.\n";
    cout << "sizeof(V): " << sizeof(V) << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
