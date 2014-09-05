// Chapter 19, exercise 10: implement a simple auto_ptr supporting only a
// constructor, destructor, ->, * and release() - don't try assignment or copy
// constructor

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Tracer {
    Tracer() { cout << "Tracer()\n"; }
    ~Tracer() { cout << "~Tracer()\n"; }
};

//------------------------------------------------------------------------------

template<class T> class auto_pntr {
    T* val;
public:
    auto_pntr(T* arg) : val(arg) { }

    ~auto_pntr() { delete val; }

    T operator*() const { return *val; }
    T* operator->() const { return val; }

    T* release()
    {
        T* temp = val;
        val = 0;
        return temp;
    }
};

//------------------------------------------------------------------------------

// demonstrates how only destructor of object held by auto_pntr is called
Tracer* f()
{
    Tracer* p1 = new Tracer();          // destructor never called
    auto_pntr<Tracer> p2(new Tracer()); // destructor called when out of scope
    auto_pntr<Tracer> p3(new Tracer()); // released from auto_pntr
    return p3.release();
}

//------------------------------------------------------------------------------

int main()
try {
    Tracer* p = f();
    delete p;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
