// Chapter 18, Drill 2: std:vector drill

#include "../lib_files/std_lib_facilities.h"

vector<int> gv;

void print_vec(const vector<int>& v) {
    for (int i = 0; i<v.size(); ++i)
        cout << v[i] << " ";
}

void f(const vector<int>& v) {
    vector<int> lv(v.size());
    lv = gv;
    print_vec(lv);
    cout << "\n";
    vector<int> lv2(v);
    print_vec(lv2);
    cout << "\n";
}

void init_gv(vector<int>& v) {
    for (int i = 0; i<10; ++i)
        v.push_back(pow(2,i));
}

int main()
try {
    init_gv(gv);
    f(gv);
    vector<int> vv;
    vv.push_back(1);
    for (int i = 1; i<10; ++i)
        vv.push_back((i+1)*vv[i-1]);
    f(vv);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
