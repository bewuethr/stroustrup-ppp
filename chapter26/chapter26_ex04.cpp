// Chapter 26, exercise 4: devise a format for test data so that you can define
// a sequence once and run several tests against it
//
// format: sequence in double curly braces, tests in single curly braces
//  { { 1 2 3 5 } } where 1 2 3 5 is the sequence
//  { 1.1 2 1 }     where 1.1 is the label, 2 the value to be found and 1 or 0
//  { 1.2 6 0 }     the expected result (true of false)

#include<iostream>
#include<exception>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

//------------------------------------------------------------------------------

// check if value val is in the ordered sequence [first,last)
template<class Iter, class T>
bool binary_search(Iter first, Iter last, const T& val)
{
    if (first == last)  // empty sequence
        return false;
    Iter p = first;
    advance(p,distance(first,last)/2);
    if (*p == val)
        return true;
    else if (val < *p)
        return binary_search(first,p,val);
    else {  // *p < val
        if (distance(p,last) == 1)
            return false;   // sequence has only 1 element, smaller than value
        return binary_search(p,last,val);
    }
}

//------------------------------------------------------------------------------

template<class T>
struct Test {
    Test() : label(""), val(T()), seq(vector<T>()), res(false) { }
    string label;
    T val;
    vector<T> seq;
    bool res;
};

//------------------------------------------------------------------------------

// read sequence of format { { 1 2 3 4 } } into seq
template<class T>
istream& operator>>(istream& is, vector<T>& seq)
{
    char ch1;
    char ch2;
    char ch3;
    char ch4;
    is >> ch1 >> ch2;
    if (!is) return is;
    if (ch1!='{' || ch2!='{') {
        is.clear(ios_base::failbit);
        return is;
    }
    T i;
    while (is >> i)
        seq.push_back(i);
    is.clear();
    is >> ch3 >> ch4;
    if (!is) return is;
    if (ch3!='}' || ch4!='}') {
        is.clear(ios_base::failbit);
        return is;
    }
    return is;
}

//------------------------------------------------------------------------------

// read label, search value and expected result into t - sequence is added
// afterwards
template<class T>
istream& operator>>(istream& is, Test<T>& t)
{
    char ch1;
    char ch2;
    is >> ch1;
    if (!is) return is;
    if (ch1 != '{') {
        is.clear(ios_base::failbit);
        return is;
    }
    string lab;
    is >> lab;
    if (!is) return is;
    if (lab=="{") { // this is the next series of tests
        is.unget();
        is.putback(ch1);    // put both '{' back into the stream
        is.clear(ios_base::failbit);
        return is;
    }
    T val;
    bool res;
    is >> val >> res >> ch2;
    if (!is) return is;
    if (ch2 != '}') {
        is.clear(ios_base::failbit);
        return is;
    }
    t.label = lab;
    t.val = val;
    t.res = res;
    return is;
}

//------------------------------------------------------------------------------

template<class T>
vector<Test<T>> read_tests(istream& is)
{
    vector<Test<T>> tests;
    vector<T> seq;
    while (true) {
        is >> seq;
        if (!is) break;
        Test<T> t;
        while (is >> t) {
            t.seq = seq;
            tests.push_back(t);
        }
        is.clear();
        seq.clear();
    }
    return tests;
}

//------------------------------------------------------------------------------

template<class T>
int test_all(istream& is)
{
    int error_count = 0;
    vector<Test<T>> tests = read_tests<T>(is);
    for (int i = 0; i<tests.size(); ++i) {
        bool r = binary_search(tests[i].seq.begin(),
            tests[i].seq.end(),
            tests[i].val);
        if (r != tests[i].res) {
            cout << "failure: test " << tests[i].label << " binary_search: "
                << tests[i].seq.size() << " elements, val==" << tests[i].val
                << " -> " << tests[i].res << '\n';
            ++error_count;
        }
    }
    return error_count;
}

//------------------------------------------------------------------------------

int main()
try
{
    // sequences of integers
    string ifname1 = "pics_and_txt/chapter26_ex04_in.txt";
    ifstream ifs1(ifname1);
    if (!ifs1) throw runtime_error("can't open " + ifname1);
    int errors = test_all<int>(ifs1);
    cout << "number of errors in " << ifname1 << ": " << errors << '\n';
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "exception\n";
}
