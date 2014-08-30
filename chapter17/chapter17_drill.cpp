// Chapter 17, drill

#include "../lib_files/std_lib_facilities.h"

// 4
void print_array10(ostream& os, int* a) {
    for (int i = 0; i<10; ++i)
        os << a[i] << "\n";
}

// 7
void print_array(ostream& os, int* a, int n) {
    for (int i = 0; i<n; ++i)
        os << a[i] << "\n";
}

// 10
void print_vector(ostream& os, vector<int> v) {
    for (int i = 0; i<v.size(); ++i)
        os << v[i] << "\n";
}

int main()
try {
    // 1
    int* ip = new int[10];

    // 2
    cout << "*** 2 ***\n";
    for (int i = 0; i<10; ++i)
        cout << ip[i] << "\n";

    // 3
    delete[] ip;

    // 5
    cout << "*** 5 ***\n";
    int* ip2 = new int[10];
    for (int i = 0; i<10; ++i)
        ip2[i] = 100 + i;
    print_array10(cout,ip2);
    delete[] ip2;

    // 6
    cout << "*** 6 ***\n";
    int* ip3 = new int[11];
    for (int i = 0; i<11; ++i)
        ip3[i] = 100 + i;
    print_array10(cout,ip3);
    cout << ip3[10] << "\n";
    delete[] ip3;

    // 8
    cout << "*** 8 ***\n";
    int* ip4 = new int[20];
    for (int i = 0; i<20; ++i)
        ip4[i] = 100 + i;
    print_array(cout,ip4,20);
    delete[] ip4;

    // 10
    cout << "*** 10 ***\n";
    vector<int> v;
    for (int i = 0; i<10; ++i)
        v.push_back(100+i);
    print_vector(cout,v);

    cout << "\n";
    vector<int> v2;
    for (int i = 0; i<11; ++i)
        v2.push_back(100+i);
    print_vector(cout,v2);

    cout << "\n";
    vector<int> v3;
    for (int i = 0; i<20; ++i)
        v3.push_back(100+i);
    print_vector(cout,v3);

    // second part
    // 1
    int i1 = 7;
    int* p1 = &i1;

    // 2
    cout << "*** 2 ***\n";
    cout << "p1: " << p1 << "\n";
    cout << "*p1: " << *p1 << "\n";

    // 3
    int* p2 = new int[7];
    for (int i = 0; i<7; ++i)
        p2[i] = pow(2,i);

    // 4
    cout << "*** 4 ***\n";
    cout << "p2: " << p2 << "\n";
    cout << "print_array(cout,p2,7):\n";
    print_array(cout,p2,7);

    // 5
    int* p3 = p2;

    // 6
    p2 = p1;

    // 7
    p2 = p3;

    // 8
    cout << "*** 8 ***\n";
    cout << "p1: " << p1 << "\n";
    cout << "*p1: " << *p1 << "\n";
    cout << "p2: " << p2 << "\n";
    cout << "*p2: " << *p2 << "\n";

    // 9
    delete[] p2;
    p3 = 0;

    // 10
    p1 = new int[10];
    for (int i = 0; i<10; ++i)
        p1[i] = pow(2,i);

    // 11
    p2 = new int[10];

    // 12
    cout << "*** 12 ***\n";
    for (int i = 0; i<10; ++i)
        p2[i] = p1[i];
    print_array(cout,p2,10);

    // 13
    cout << "*** 13 ***\n";
    vector<int> vec1;
    for (int i = 0; i<10; ++i)
        vec1.push_back(pow(2,i));
    vector<int> vec2;
    for (int i = 0; i<vec1.size(); ++i)
        vec2.push_back(vec1[i]);
    print_vector(cout,vec2);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
