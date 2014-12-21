// Chapter 21, Exercise 3: implement count() yourself and test it

#include "../lib_files/std_lib_facilities.h"


//------------------------------------------------------------------------------

template<class In, class T>
int my_count(In first, In last, const T& val)
{
    int ctr = 0;
    while (first != last) {
        if (*first == val) ++ctr;
        ++first;
    }
    return ctr;
}

//------------------------------------------------------------------------------

int main()
try {
    vector<int> vi;
    for (int i = 0; i<50; ++i)
        vi.push_back(randint(50));
    cout << "vi:\n";
    for (vector<int>::iterator p = vi.begin(); p!=vi.end(); ++p)
        cout << *p << '\n';
    cout << "Enter value for which you want to know the count, -1 to exit: ";
    int val;
    while (cin>>val) {
        if (val==-1) break;
        int ctr = my_count(vi.begin(),vi.end(),val);
        cout << val << " is " << ctr << " time" << (ctr!=1 ? "s " : " ")
            << "in vi.\nNext value: ";
    }
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