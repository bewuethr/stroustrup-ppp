// Chapter 20, Exercise 05: Define an input and an output operator (>> and <<)
// for vector.

#include "../lib_files/std_lib_facilities.h"

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i<v.size(); ++i) {
        os << v[i];
        if (i+1<v.size()) os << ',';
        os << ' ';
    }
    os << '}';
    return os;
}

template<class T>
istream& operator>>(istream& is, vector<T>& v)
{
    char ch;
    is >> ch;
    if (ch!='{') error("vector must start with '{'");
    T element;
    while (true) {
        is >> ch;
        if (is && ch=='}') return is;
        else is.unget();
        is >> element;
        if (is) v.push_back(element);
        else error("invalid element");
    }
    return is;
}

int main()
try {
    vector<double> vd;
    vector<int> vi;
    vector<string> vs;
    cout << "Enter vector of doubles: ";
    cin >> vd;
    cout << "Enter vector of integers: ";
    cin >> vi;
    cout << "Enter vector of strings: ";
    cin >> vs;


    cout << vd << "\n" << vi << "\n" << vs << "\n";
}
catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}





