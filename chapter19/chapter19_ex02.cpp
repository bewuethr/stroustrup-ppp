// Chapter 19, exercise 02: write a template function that takes a vector<T> vt
// and a vector<U> vu as arguments and returns the sum of all vt[i]*vu[i]s

// Requires either boost or the C++11 <type_traits> std::common_type facilities
// to determine the return type, so this doesn't compile in C++98

#include "../lib_files/std_lib_facilities.h"
#include<type_traits>

template<class T, class U>
typename std::common_type<T,U>::type f(const vector<T>& vt, const vector<U>& vu)
{
    typename std::common_type<T,U>::type sum = 0;
    int min_size = vt.size()<=vu.size() ? vt.size() : vu.size();
    for (int i = 0; i<min_size; ++i) {
            sum += vt[i]*vu[i];
    }
    return sum;
}

template<class T> ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "{";
    for (int i = 0; i<v.size()-1; ++i)
        os << ' ' << v[i] << ',';
    os << ' ' << v[v.size()-1] << " }";
    return os;
}

int main()
try {
    vector<int> v1;
    for (int i = 0; i<10; ++i)
        v1.push_back(i);
    cout << "v1: " << v1 << "\n";
    vector<double> v2;
    for (int i = 0; i<8; ++i)
        v2.push_back(i*1.6);
    cout << "f(v1,v2): " << f(v1,v2) << "\n";
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << "\n";
}
catch (...) {
    cerr << "Exception\n";
}
