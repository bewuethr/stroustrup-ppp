
//
// This is example code from Chapter 26.3.2.2 "A simple test harness" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

void test1()
{
    int a1[] = { 1,2,3,5,8,13,21 };
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1), 1) == false) cout << "failed"; 
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1), 5) == false) cout << "failed";
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1), 8) == false) cout << "failed";
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1),21) == false) cout << "failed";
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1),-7) == true)  cout << "failed"; 
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1), 4) == true)  cout << "failed"; 
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1),22) == true)  cout << "failed";
}

//------------------------------------------------------------------------------

void test2()
{
    int a1[] = { 1,2,3,5,8,13,21 };
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1), 1) == false) cout << "1 failed"; 
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1), 5) == false) cout << "2 failed";
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1), 8) == false) cout << "3 failed";
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1),21) == false) cout << "4 failed";
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1),-7) == true)  cout << "5 failed"; 
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1), 4) == true)  cout << "6 failed"; 
    if (binary_search(a1,a1+sizeof(a1)/sizeof(*a1),22) == true)  cout << "7 failed";
}

//------------------------------------------------------------------------------

struct Test {
    string label;
    int val;
    vector<int> seq;
    bool res;
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Test& t) // use the described format
{
    // Example input: { 27 7 { 1 2 3 5 8 13 21} 0 }
    string a, b;

    if (is >> a >> t.label >> t.val >> b && (a != "{" || b != "{"))
    {
        std::cerr << "ERROR: Invalid test file format" << std::endl;
        return is;
    }

    //cout << a << '|' << t.label << '|'  << b << '|'  << t.val << '|' ;

    t.seq.clear();
    std::copy(
        std::istream_iterator<int>(is),
        std::istream_iterator<int>(),
        std::back_inserter(t.seq)
    );

    is.clear();

    //std::copy(t.seq.begin(), t.seq.end(), std::ostream_iterator<int>(cout," "));
    string c, d;
    int res = 0;

    if (is >> c >> res >> d && (c != "}" || d != "}"))
    {
        std::cerr << "ERROR: Invalid test file format" << std::endl;
        return is;
    }

    t.res = res;
    //cout << c << '|' << t.res << '|' << d << '|' ;

    return is;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Test& t)
{
    os << "{ " << t.label << ' ' << t.val << " { ";
    std::copy(t.seq.begin(), t.seq.end(), std::ostream_iterator<int>(os," "));
    return os << "} " << t.res << " }";
}

//------------------------------------------------------------------------------

int test_all() 
{
    int error_count = 0;
    Test t;
    while (cin>>t) {
        cout << t << endl;
        bool r = binary_search( t.seq.begin(), t.seq.end(), t.val);
        if (r !=t.res) {
            cout << "failure: test " << t.label
                 << " binary_search: "
                 << t.seq.size() << " elements, v==" << t.val
                 << " -> " << t.res << '\n';
            ++error_count;
        }
    }
    return error_count;
}

//------------------------------------------------------------------------------


int main()
{
    int errors = test_all();
    cout << "number of errors: " << errors << "\n";
}

//------------------------------------------------------------------------------
