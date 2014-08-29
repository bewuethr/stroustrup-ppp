// Chapter 08, exercise 06: same as exercise 5, but with strings

#include "../lib_files/std_lib_facilities.h"

void print(const string& label, const vector<string>& v)
{
    cout << label << " (" << v.size() << "): ( ";
    for (int i = 0; i<v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << ")\n";
}

// reverse and return copy
vector<string> reverse1(const vector<string>& v)
{
    vector<string> v_rev(v.size());
    for (int i = 0; i<v.size(); ++i) {
        v_rev[i] = v[v.size()-1-i];
    }
    return v_rev;
}

// reverse, operate on reference
void reverse2(vector<string>& v)
{
    for (int i = 0; i<v.size()/2; ++i) {
        swap(v[i],v[v.size()-1-i]);
    }
}

int main()
try
{
    vector<string> v1;
    vector<string> v2;
    v1.push_back("one");
    v1.push_back("three");
    v1.push_back("five");
    v1.push_back("seven");
    v1.push_back("nine");
    v2.push_back("two");
    v2.push_back("four");
    v2.push_back("six");
    v2.push_back("eight");
    print("v1_pre",v1);
    vector<string> v1_rev = reverse1(v1);
    print("v1_post_val",v1);
    print("v1_rev",v1_rev);
    reverse2(v1);
    print("v1_post_ref",v1);
    print("v2_pre",v2);
    vector<string> v2_rev = reverse1(v2);
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
