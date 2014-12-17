// Chapter 21, Try This 1: test two different definitions of the find algorithm

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

template<class In, class T>
In find1(In first, In last, const T& val)
{
    while (first!=last && *first!=val) ++first;
    return first;
}

//------------------------------------------------------------------------------

template<class In, class T>
In find2(In first, In last, const T& val)
{
    for (In p = first; p!=last; ++p)
        if (*p==val) return p;
    return last;
}

//------------------------------------------------------------------------------

int main()
try {
    vector<int> vi;
    for (int i = 0; i<25; ++i) {
        vi.push_back(randint(50));
        cout << vi[i] << ' ';
    }
    cout << "\n";
    int idx = randint(vi.size());
    cout << "Looking for " << vi[idx] << ":\n";
    vector<int>::iterator v_iter1 = find1(vi.begin(),vi.end(),vi[idx]);
    vector<int>::iterator v_iter2 = find2(vi.begin(),vi.end(),vi[idx]);
    while (v_iter1!=vi.end()) {
        cout << *v_iter1 << '/' << *v_iter2 << ' ';
        ++v_iter1;
        ++v_iter2;
    }
    cout << "\n";

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

//------------------------------------------------------------------------------