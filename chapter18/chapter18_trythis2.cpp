// Chapter 18, Try This 2

// first try at using indexing for element access - not supposed to compile

#include "../lib_files/std_lib_facilities.h"

class my_vector {
    int sz;
    double* elem;
public:
    explicit my_vector(int s) : sz(s),elem(new double[s])
    {
        for (int i = 0; i<s; ++i) elem[i] = 0;
    }
    double operator[](int i) { return elem[i]; }
};

int main()
{
    string s = "test";
    s.length();
    my_vector v(10);
    int x = v[2];
    v[3] = x;
}
