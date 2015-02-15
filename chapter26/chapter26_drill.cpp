// Chapter 26, Drill: get test of binary_search to run
// 1: implement input operator for Test from 26.3.2.2
// 2: complete a file of tests for the sequences from 26.3:
//     a. { 1 2 3 5 8 13 21 }
//     b. { }
//     c. { 1 }
//     d. { 1 2 3 4 }
//     e. { 1 2 3 4 5 }
//     f. { 1 1 1 1 1 1 1 }
//     g. { 0 1 1 1 1 1 1 1 1 1 1 1 1 }
//     h. { 0 0 0 0 0 0 0 0 0 0 0 0 1 }
// 3: based on 26.3.2.3, complete a program that generates
//     a. a very large sequence
//     b. ten sequences with a random number of elements
//     c. ten sequences with 0, 1, 2, ..., 9 random elements (still ordered)
// 4: repeat these tests for sequences of strings

#include<cstdlib>
#include<iostream>
#include<exception>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<limits>

using namespace std;

//------------------------------------------------------------------------------

inline int randint(int max) { return max==0 ? 0 : rand()%max; }

//------------------------------------------------------------------------------

inline int randint(int min, int max) { return randint(max-min)+min; }

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

// write a test description with the label lab to os
// generate a sequence of n elements starting at base
// the average distance between elements is uniformly distributed in [0:spread)
ostream& make_test(const string& lab, int n, int base, int spread, ostream& os)
{
    os << "{ " << lab << " ";
    vector<int> v;
    int elem = base;
    for (int i = 0; i<n; ++i) {
        elem += randint(spread);
        v.push_back(elem);
    }

    int val = base + randint(elem-base);
    os << val << " { ";
    bool found = false;
    for (int i = 0; i<n; ++i) {
        if (v[i]==val) found = true;
        os << v[i] << " ";
    }
    os << "} " << found << " }\n";
    return os;
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
    srand(time(0));

    // sequences of integers
    string ifname1 = "pics_and_txt/chapter26_drill_in1.txt";
    ifstream ifs1(ifname1);
    if (!ifs1) throw runtime_error("can't open " + ifname1);
    int errors = test_all<int>(ifs1);
    cout << "number of errors in " << ifname1 << ": " << errors << '\n';

    // randomly generated sequences
    string ofname1 = "pics_and_txt/chapter26_drill_out1.txt";
    ofstream ofs1(ofname1);
    if (!ofs1) throw runtime_error("can't open " + ofname1);

    // very long sequence
    make_test("9",10000,0,3,ofs1);
    ofs1.close();

    // 10 sequences with random number of elements
    ofs1 = ofstream(ofname1,ios_base::app);
    for (int i = 0; i<10; ++i)
        make_test("10."+to_string(i+1),randint(50),0,5,ofs1);

    // 10 sequences with 0, 1, 2, ..., 9 random elements (still ordered)
    for (int i = 0; i<10; ++i)
        make_test("11."+to_string(i+1),i,0,10,ofs1);

    ofs1.close();

    // test generated sequences
    ifstream ifs2(ofname1);
    if (!ifs2) throw runtime_error("can't open " + ofname1);
    errors = test_all<int>(ifs2);
    cout << "number of errors in " << ofname1 << ": " << errors << '\n';

    // test with strings
    string ifname2 = "pics_and_txt/chapter26_drill_in2.txt";
    ifstream ifs3(ifname2);
    if (!ifs3) throw runtime_error("can't open " + ifname2);
    errors = test_all<string>(ifs3);
    cout << "number of errors in " << ifname2 << ": " << errors << '\n';
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "exception\n";
}
