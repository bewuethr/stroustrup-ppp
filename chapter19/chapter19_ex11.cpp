// Chapter 19, exercise 11: design and implement a counted_ptr<T>: a type that
// holds a pointer to an object of type T and a pointer to a "user count" (an
// int) shared by all pointers to the same object of type T, holding the number
// of counted pointers pointing to a given T. The constructor should allocate a
// T and a use count on the heap and take an argument as initial value for the T
// elements. When the last counted_ptr for a T is destroyed, the destructor
// should delete the T.
// counted_ptr should have operations that allow us to use it as a pointer.
// Write a set of test cases.

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Tracer {
    Tracer() : val(0) { cout << "Def ctor\n"; }
    Tracer(int n) : val(n) { cout << "Arg ctor " << n << "\n"; }
    Tracer(const Tracer& t) : val(t.val) { cout << "Cpy ctor " << val << "\n"; }
    Tracer& operator=(const Tracer& t)
    {
        val = t.val;
        cout << "Cpy assgn " << val << "\n";;
        return *this;
    }
    ~Tracer() { cout << "Destor " << val << "\n";; }
    int val;
};

//------------------------------------------------------------------------------

template<class T> class counted_ptr {
    T* val;     // the wrapped pointer
    int* cnt;   // reference counter
public:
    counted_ptr(const T& arg);                  // constructor with argument
    counted_ptr(const counted_ptr&);            // copy constructor
    counted_ptr& operator=(const counted_ptr&); // copy assignment

    ~counted_ptr();

    T operator*() const { return *val; }
    T* operator->() const { return val; }

    int count() const { return *cnt; }
};

//------------------------------------------------------------------------------

template<class T> counted_ptr<T>::counted_ptr(const T& arg)
{
    val = new T(arg);
    cnt = new int(1);
}

//------------------------------------------------------------------------------

template<class T> counted_ptr<T>::counted_ptr(const counted_ptr& arg)
{
    val = arg.val;
    cnt = arg.cnt;
    ++(*cnt);       // parentheses only for clarity
}

//------------------------------------------------------------------------------

template<class T>
counted_ptr<T>& counted_ptr<T>::operator=(const counted_ptr& arg)
{
    if (&arg==this) return *this;
    --(*cnt);
    if (*cnt==0) {
        delete val;
        delete cnt;
    }
    val = arg.val;
    cnt = arg.cnt;
    ++(*cnt);       // parentheses only for clarity
    return *this;
}

//------------------------------------------------------------------------------

template<class T> counted_ptr<T>::~counted_ptr()
{
    --(*cnt);
    if (*cnt == 0) {
        cout << "Destructing counted pointer\n";
        delete val;
        delete cnt;
    }
}

//------------------------------------------------------------------------------

// test functions
template<class T> void f3(const counted_ptr<T>& cp2)
{
    counted_ptr<Tracer> cp3(Tracer(0));
    cp3 = cp2;
    cout << "cp3->val: " << cp3->val << "\n";
    cout << "cp3.cnt: " << cp3.count() << "\n";
    cout << "cp2.cnt: " << cp2.count() << "\n";
}

template<class T> void f2(const counted_ptr<T>& cp1)
{
    counted_ptr<T> cp2(cp1);
    cout << "cp2->val: " << cp2->val << "\n";
    cout << "cp2.cnt: " << cp2.count() << "\n";
    f3(cp2);
    cout << "cp2.cnt: " << cp2.count() << "\n";
}

void f1()
{
    Tracer t(99);
    counted_ptr<Tracer> cp1(t);
    cout << "(*cp1).val: " << (*cp1).val << "\n";
    cout << "cp1->val: " << cp1->val << "\n";
    cout << "cp1.cnt: " << cp1.count() << "\n";
    f2(cp1);
    cout << "cp1.cnt: " << cp1.count() << "\n";
}

//------------------------------------------------------------------------------

int main()
try {
    // test counted_ptr with destruction after scope ends
    f1();

    // test counted_ptr as container element
    vector<counted_ptr<string> > vcp;
    counted_ptr<string> cp("test");
    cout << "refcount: " << cp.count() << "\n";
    for (int i = 0; i<10; ++i) {
        vcp.push_back(counted_ptr<string>(cp));
        cout << "refcount[" << i << "]: " << vcp[i].count() << "\n";
    }
    for (int i = 0; i<10; ++i)
        cout << "refcount[" << i << "]: " << vcp[i].count() << "\n";
    vcp.resize(0,counted_ptr<String>(""));

    // redirecting counted_ptr
    counted_ptr<Tracer> cp1(Tracer(5));
    counted_ptr<Tracer> cp2(cp1);
    counted_ptr<Tracer> cp3(Tracer(6));
    counted_ptr<Tracer> cp4(cp3);
    cout << "cp1 refcount: " << cp1.count() << "\n";
    cout << "cp3 refcount: " << cp3.count() << "\n";
    cp3 = cp1;
    cout << "cp1 refcount: " << cp1.count() << "\n";
    cout << "cp4 refcount: " << cp4.count() << "\n";
    cp4 = cp1;  // destroys Tracer(6) object
    cout << "cp1 refcount: " << cp1.count() << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
