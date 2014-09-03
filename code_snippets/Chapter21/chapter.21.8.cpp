
//
// This is example code from Chapter 21.8 "Sorting and searching" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

struct No_case {
    bool operator()(const string& x, const string& y) const
    {
        for (int i = 0; i<x.length(); ++i) {
            if (i == y.length()) return false; // y<x
            char xx = tolower(x[i]);
            char yy = tolower(y[i]);
            if (xx<yy) return true;            // x<y
            if (yy<xx) return false;           // y<x
        }
        return true;                           // x<y (fewer characters in x)
    }
};

//------------------------------------------------------------------------------

void sort_and_print(vector<string>& vc)
{
    sort(vc.begin(),vc.end(),No_case());

    for (vector<string>::const_iterator p = vc.begin(); p!=vc.end(); ++p)
        cout << *p << '\n';
}

//------------------------------------------------------------------------------

void f(vector<string>& vs)    // vs is sorted
{
    if (binary_search(vs.begin(),vs.end(),"starfruit")) {
        // we have a starfruit
    }

    // ...
}

//------------------------------------------------------------------------------

struct Fruit {
    string name;
    int count;
    double unit_price;
    // ...
    Fruit(const char* n, int c = 1, double p = 0.0) : name(n), count(c), unit_price(p) {}
};

//------------------------------------------------------------------------------

struct Fruit_order {
    bool operator()(const Fruit& a, const Fruit& b) const
    {
        return a.name<b.name;
    }
};

//------------------------------------------------------------------------------

void f(vector<Fruit>& vs)    // vs is sorted
{
    typedef vector<Fruit>::iterator FI;
    pair<FI,FI> ff =
        equal_range(vs.begin(), vs.end(), "pear", Fruit_order());
    for (FI p =ff.first;  p!=ff.second; ++p) { // iterate through all pears
        // we have a pear at p
    }
}

//------------------------------------------------------------------------------

int main()
{
    vector<Fruit> vs;
    f(vs);
}

//------------------------------------------------------------------------------
