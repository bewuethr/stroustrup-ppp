// Chapter 26, exercise 12: generate random floating point numbers and sort them
// using std::sort(). Measure time used to sort 500,000 doubles and 5,000,000
// doubles.
//
// Exercise 13: repeat with random strings of lengths in the [0:100) range

#include<ctime>
#include<cstdlib>
#include<iostream>
#include<exception>
#include<vector>
#include<limits>
#include<algorithm>
#include<string>

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
            for (int i = 0; i<v.size(); ++i)
                v[i] = drand(numeric_limits<double>::min()/2,
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
            for (int i = 0; i<v.size(); ++i)
                v[i] = rand_string();
            sort(v.begin(),v.end());
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
