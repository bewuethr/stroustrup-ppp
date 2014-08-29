// Chapter 08, exercise 05: write two functions that reverse the order of
// elements in a vector<int>

#include "../lib_files/std_lib_facilities.h"

void print(const string& label, const vector<int>& v)
{
    cout << label << " (" << v.size() << "): {";
    for (int i = 0; i<v.size(); ++i) {
        if (i%8 == 0) cout << endl;
        cout << v[i];
        if (i<v.size()-1) cout << ", ";
    }
    cout << "\n}\n";
}

// reverse and return copy
vector<int> reverse1(const vector<int>& v)
{
    vector<int> v_rev(v.size());
    for (int i = 0; i<v.size(); ++i) {
        v_rev[i] = v[v.size()-1-i];
    }
    return v_rev;
}

// reverse, operate on reference
void reverse2(vector<int>& v)
{
    for (int i = 0; i<v.size()/2; ++i) {
        swap(v[i],v[v.size()-1-i]);
    }
}

int main()
try
{
    vector<int> v1;
    vector<int> v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    v1.push_back(9);
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);
    v2.push_back(8);
    print("v1_pre",v1);
    vector<int> v1_rev = reverse1(v1);
    print("v1_post_val",v1);
    print("v1_rev",v1_rev);
    reverse2(v1);
    print("v1_post_ref",v1);
    print("v2_pre",v2);
    vector<int> v2_rev = reverse1(v2);
    print("v2_post_val",v2);
    print("v2_rev",v2_rev);
    reverse2(v2);
    print("v2_post_ref",v2);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
