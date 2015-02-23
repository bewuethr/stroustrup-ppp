// Chapter 26, exercise 12: generate random floating point numbers and sort them
// using std::sort(). Measure time used to sort 500,000 doubles and 5,000,000
// doubles.

// Exercise 13: repeat with random strings of lengths in the [0:100) range

// Exercise 14: repeat exercise 13 with map instead of vector - or set, as there
// are only key and no values

#include<ctime>
#include<cstdlib>
#include<iostream>
#include<exception>
#include<vector>
#include<limits>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

//------------------------------------------------------------------------------

inline int randint(int max) { return rand()%max; }

//------------------------------------------------------------------------------

inline double drand(double min, double max)
{
    double d = double(rand()) / RAND_MAX;
    return min + d * (max-min);
}

//------------------------------------------------------------------------------

string rand_string()
{
    int len = randint(100);
    string s;
    for (int i = 0; i<len; ++i)
        s += char(randint(numeric_limits<char>::max()));
    return s;
}

//------------------------------------------------------------------------------

int main()
try {
    srand(time(0));
    vector<int> sizes = {500000, 5000000};

    // use vector<double>
    for (int i = 0; i<sizes.size(); ++i) {
        cout << "vector<double>, " << sizes[i] << " elements: ";
        double t = 0;
        for (int j = 0; j<3; ++j) {
            clock_t t1 = clock();
            if (t1 == clock_t(-1))
                throw exception("sorry, no clock");
            vector<double> v(sizes[i]);
            for (int k = 0; k<v.size(); ++k)
                v[k] = drand(numeric_limits<double>::min()/2,
                             numeric_limits<double>::max()/2);
            sort(v.begin(),v.end());
            clock_t t2 = clock();
            if (t2 == clock_t(-1))
                throw exception("sorry, clock overflow");
            t += double(t2-t1)/CLOCKS_PER_SEC;
        }
        cout << t/3 << " seconds\n";
    }

    // use vector<string>
    for (int i = 0; i<sizes.size(); ++i) {
        cout << "vector<string>, " << sizes[i] << " elements: ";
        double t = 0;
        for (int j = 0; j<3; ++j) {
            clock_t t1 = clock();
            if (t1 == clock_t(-1))
                throw exception("sorry, no clock");
            vector<string> v(sizes[i]);
            for (int k = 0; k<v.size(); ++k)
                v[k] = rand_string();
            sort(v.begin(),v.end());
            clock_t t2 = clock();
            if (t2 == clock_t(-1))
                throw exception("sorry, clock overflow");
            t += double(t2-t1)/CLOCKS_PER_SEC;
        }
        cout << t/3 << " seconds\n";
    }

    // use set<string>
    for (int i = 0; i<sizes.size(); ++i) {
        cout << "set<string>, " << sizes[i] << " elements: ";
        double t = 0;
        for (int j = 0; j<3; ++j) {
            clock_t t1 = clock();
            if (t1 == clock_t(-1))
                throw exception("sorry, no clock");
            set<string> s;
            for (int k = 0; k<sizes[i]; ++k)
                s.insert(rand_string());
            clock_t t2 = clock();
            if (t2 == clock_t(-1))
                throw exception("sorry, clock overflow");
            t += double(t2-t1)/CLOCKS_PER_SEC;
        }
        cout << t/3 << " seconds\n";
    }
}
catch (exception& e) {
    cerr << e.what() << endl;
}
catch (...) {
    cerr << "exception \n";
}

//------------------------------------------------------------------------------
