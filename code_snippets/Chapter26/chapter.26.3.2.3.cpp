
//
// This is example code from Chapter 26.3.2.3 "Random sequences" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

int rand_int(int max) { return rand()%max; }

//------------------------------------------------------------------------------

int rand_int(int min, int max) { return rand_int(max-min)+min; }

//------------------------------------------------------------------------------

template<class T>
string to_string(const T& t)
{
    ostringstream os;
    os << t;
    return os.str();
}

//------------------------------------------------------------------------------

void make_test(const string& lab, int n, int base, int spread)
// write a test description with the label lab to cout
// generate a sequence of n elements starting at base
// the average distance between elements is spread
{
    cout << "{ " << lab << " " << n << " { ";
    vector<int> v;
    int elem = base;
    for (int i = 0; i<n; ++i) {           // make elements
        elem+= rand_int(spread);
        v.push_back(elem);
    }

    int val = base+ rand_int(elem-base);  // make search value
    bool found = false;
    for (int i = 0; i<n; ++i) {           // print elements and see if val is found
        if (v[i]==val) found = true;
        cout << v[i] << " ";
    }
    cout << "} " << found << " }\n";
}

//------------------------------------------------------------------------------

int main()
{
    int no_of_tests = rand_int(10);       // make about 5 tests
    for (int i = 0; i<no_of_tests; ++i) {
        string lab = "rand_test_";
        make_test(lab+to_string(i),       // to_string from §23.2
            rand_int(500),                // number of elements
            0,                            // base
            rand_int(50));                // spread
    }
}

//------------------------------------------------------------------------------
