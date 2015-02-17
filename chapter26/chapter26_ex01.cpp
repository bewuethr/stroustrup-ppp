// Chapter 26, exercise 1: test your binary_search from 26.1 with the tests in
// 26.3.2.1

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
    string label;
    T val;
    vector<T> seq;
    bool res;
};

//------------------------------------------------------------------------------

template<class T>
istream& operator>>(istream& is, Test<T>& t)
{
    char ch1;
    char ch2;
    char ch3;
    char ch4;
    string label;
    T val;
    vector<T> seq;
    bool res;
    is >> ch1 >> label >> val >> ch2;
    if (!is) return is;
    if (ch1!='{' || ch2!='{') {
        is.clear(ios_base::failbit);
        return is;
    }
    T i;
    while (is>>i)
        seq.push_back(i);
    is.clear();
    is >> ch3 >> res >> ch4;
    if (!is) return is;
    if (ch3!='}' || ch4!='}') {
        is.clear(ios_base::failbit);
        return is;
    }
    t.label = label;
    t.val = val;
    t.seq = seq;
    t.res = res;
    return is;
}

//------------------------------------------------------------------------------

template<class T>
int test_all(istream& is)
{
    int error_count = 0;
    Test<T> t;
    while (is >> t) {
        if (!is) throw runtime_error("problem reading from test file");
        bool r = binary_search(t.seq.begin(),t.seq.end(),t.val);
        if (r != t.res) {
            cout << "failure: test " << t.label << " binary_search: "
                << t.seq.size() << " elements, val==" << t.val
                << " -> " << t.res << '\n';
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
    string ifname1 = "pics_and_txt/chapter26_drill_in1.txt";
    ifstream ifs1(ifname1);
    if (!ifs1) throw runtime_error("can't open " + ifname1);
    int errors = test_all<int>(ifs1);
    cout << "number of errors in " << ifname1 << ": " << errors << '\n';

    // test generated sequences
    string ifname2 = "pics_and_txt/chapter26_drill_out1.txt";
    ifstream ifs2(ifname2);
    if (!ifs2) throw runtime_error("can't open " + ifname2);
    errors = test_all<int>(ifs2);
    cout << "number of errors in " << ifname2 << ": " << errors << '\n';

    // test with strings
    string ifname3 = "pics_and_txt/chapter26_drill_in2.txt";
    ifstream ifs3(ifname3);
    if (!ifs3) throw runtime_error("can't open " + ifname3);
    errors = test_all<string>(ifs3);
    cout << "number of errors in " << ifname3 << ": " << errors << '\n';
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "exception\n";
}
