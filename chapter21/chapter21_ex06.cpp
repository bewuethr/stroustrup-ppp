// Chapter 21, Exercise 6: implement the Fruit example (set) using a
// set<Fruit*,Fruit_comparison> (pointers instead of copies), i.e., define a
// comparison operation for Fruit*

#include "../lib_files/std_lib_facilities.h"
#include<set>

//------------------------------------------------------------------------------

struct Fruit {
    string name;
    int count;
    double unit_price;
    Fruit(string n, int c, double up = 0.0)
        :name(n), count(c), unit_price(up) { }
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Fruit* f)
{
    os << setw(7) << left << f->name;
    os << f->count << '\t' << f->unit_price;
    return os;
}

//------------------------------------------------------------------------------

struct Fruit_comparison {
    bool operator()(const Fruit* a, const Fruit* b) const
    {
        return a->name < b->name;
    }
};

//------------------------------------------------------------------------------

int main()
try {
    set<Fruit*,Fruit_comparison> inventory;
    inventory.insert(new Fruit("Quince",5));    // test default parameter
    inventory.insert(new Fruit("Apple",200,0.37));
    inventory.insert(new Fruit("Orange",150,0.45));
    inventory.insert(new Fruit("Grape",13,0.99));
    inventory.insert(new Fruit("Kiwi",512,1.15));
    inventory.insert(new Fruit("Plum",750,2.33));

    typedef set<Fruit*,Fruit_comparison>::const_iterator Si;
    for (Si p = inventory.begin(); p!=inventory.end(); ++p) cout << *p << '\n';

    // Clean up
    for (Si p = inventory.begin(); p!=inventory.end(); ++p) delete *p;
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