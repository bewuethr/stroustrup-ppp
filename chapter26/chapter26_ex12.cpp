// Chapter 26, exercise 12: generate random floating point numbers and sort them
// using std::sort(). Measure time used to sort 500,000 doubles and 5,000,000
// doubles.

#include<ctime>
#include<cstdlib>
#include<iostream>
#include<exception>
#include<vector>
#include<limits>
#include<algorithm>

using namespace std;

//------------------------------------------------------------------------------

inline double drand(double min, double max)
{
    double d = double(rand()) / RAND_MAX;
    return min + d * (max-min);
}

//------------------------------------------------------------------------------

int main()
try {
    srand(time(0));
    vector<int> sizes = {500000, 5000000, 10000000};

    for (int i = 0; i<sizes.size(); ++i) {
        cout << "Sorting " << sizes[i] << " doubles:\n";
        double t = 0;
        for (int j = 0; j<3; ++j) {
            vector<double> v(sizes[i]);
            for (int i = 0; i<v.size(); ++i)
                v[i] = drand(numeric_limits<double>::min()/2,
                             numeric_limits<double>::max()/2);
            clock_t t1 = clock();
            if (t1 == clock_t(-1))
                throw exception("sorry, no clock");
            sort(v.begin(),v.end());
            clock_t t2 = clock();
            if (t2 == clock_t(-1))
                throw exception("sorry, clock overflow");
            t += double(t2-t1)/CLOCKS_PER_SEC;
        }
        cout << "Time: " << t/3 << " seconds\n\n";
    }
}
catch (exception& e) {
    cerr << e.what() << endl;
}
catch (...) {
    cerr << "exception \n";
}

//------------------------------------------------------------------------------
