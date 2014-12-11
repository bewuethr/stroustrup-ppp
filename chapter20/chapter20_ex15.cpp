// Chapter 20, Exercise 15: define a pvector to be like a vector of pointers
// except that it contains pointer to objects and its destructor deletes each
// object

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

template<class Elem>
class pvector : public vector<Elem*> {
public:
    ~pvector();
};

//------------------------------------------------------------------------------

template<class Elem>
pvector<Elem>::~pvector()
{
    for (typename pvector<Elem>::iterator it = this->begin(); it!=this->end(); ++it) {
        cout << "Deleting " << **it << "\n";
        delete *it;
    }
}

//------------------------------------------------------------------------------

void f()
{
    pvector<int> pv;
    for (int i = 0; i<10; ++i) {
        pv.push_back(new int(i));
    }
    for (pvector<int>::iterator it = pv.begin(); it!=pv.end(); ++it)
        cout << **it << "\n";
}

int main()
try {
    f();
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

