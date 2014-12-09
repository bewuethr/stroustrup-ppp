// Chapter 20, Exercise 11: Given a list<int> as a by-reference parameter, make
// a vector<double> and copy the elements of the list into it. Verify that the
// copy was complete and correct, then print the elements in order of increasing
// value.

#include "../lib_files/std_lib_facilities.h"

template<class Iter>
void print_ctr(Iter first, Iter last)
{
    cout << "{";
    while (first != last) {
        cout << " " << *first;
        ++first;
    }
    cout << " }\n";
}

void list_cpy(const list<int>& li)
{
    vector<double> vd;
    list<int>::const_iterator li_it = li.begin();
    while (li_it != li.end()) {
        vd.push_back(*li_it);
        ++li_it;
    }

    // verify copy
    cout << "Length of list:   " << li.size() << "\n";
    cout << "Length of vector: " << vd.size() << "\n";
    cout << "List:   ";
    print_ctr(li.begin(),li.end());
    cout << "Vector: ";
    print_ctr(vd.begin(),vd.end());
    vector<double> vd_sorted = vd;
    sort(vd_sorted.begin(),vd_sorted.end());
    cout << "Sorted: ";
    print_ctr(vd_sorted.begin(),vd_sorted.end());
}

int main()
try {
    list<int> li;
    for (int i = 0; i<10; ++i)
        li.push_back(randint(0,99));
    list_cpy(li);
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






