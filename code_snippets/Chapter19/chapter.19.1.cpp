
//
// This is example code from Chapter 19.1 "The problems" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void foo()
{
    vector<double> vd;             // elements of type double
    double d;
    while(cin>>d) vd.push_back(d); // grow vd to hold all the elements

    vector<char> vc(100);          // elements of type char
    int n;
    if (cin>>n)
        vc.resize(n);              // make vc have n elements
}

//------------------------------------------------------------------------------

void without_push_back()
{
    // read elements into a vector without using push_back:
    vector<double>* p = new vector<double>(10);
    int n = 0;                     // number of elements
    double d;
    while(cin >> d) {
        if (n==p->size()) {
            vector<double>* q = new vector<double>(p->size()*2);
            copy(p->begin(), p->end(), q->begin());
            delete p;
            p = q;
        }
        (*p)[n] = d;
        ++n;
    }
}

//------------------------------------------------------------------------------

void with_push_back()
{
    vector<double> vd;
    double d;
    while(cin>>d) vd.push_back(d);
}

//------------------------------------------------------------------------------

int main()
{
    foo();
    without_push_back();
    with_push_back();
}

//------------------------------------------------------------------------------
