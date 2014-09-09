// Chapter 19, exercise 13: Tracer class where constructor and destructor print
// strings (given as argument to constructor). Use it to see where RAII objects
// will do their job (local objects, member objects, global objects, objects
// allocated with new...), then add copy constructor and copy assignment to see
// when copying is done

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

class Tracer {
    string msg;
public:
    Tracer(const string& s) : msg(s) { cout << "Constructed " << msg << "\n"; }
    Tracer(const Tracer& t) : msg(t.msg)
    {
        cout << "Copy constructed from " << msg << "\n";
    }
    Tracer& operator=(const Tracer& t)
    {
        msg = t.msg;
        cout << "Copy assigned " << msg << "\n";
        return *this;
    }
    ~Tracer() { cout << "Destroyed " << msg << "\n"; }
    void set_msg(const string& s) { msg = s; }
};

//------------------------------------------------------------------------------

struct Test {
    Test(const string& s) : val(Tracer(s)) { }
    Tracer val;
};

//------------------------------------------------------------------------------

Tracer global("global");

//------------------------------------------------------------------------------

int main()
try {
    { Tracer t_scope("allocated in local scope"); } // immediately destroyed
    Tracer copy_global = global;
    cout << "and renamed to 'local copy of global'\n";
    copy_global.set_msg("local copy of global");
    Tracer local("local");
    Test member("as member object");
    Tracer* local_ptr = new Tracer("allocated with new");   // leaks!
    Tracer t_cpyassign = *local_ptr;
    cout << "and renamed to 'copy assigned from pointer'\n";
    t_cpyassign.set_msg("copy assigned from pointer");
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
