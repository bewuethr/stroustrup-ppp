
//
// This is example code from Chapter 21.6.5 "Set" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <set>
#include <string>

using namespace std;

//------------------------------------------------------------------------------

struct Date {
    int y;    // year
    int m;    // month in year
    int d;    // day of month
};

//------------------------------------------------------------------------------

// We can represent the set of fruits used in the map example (§21.6.2) like this:
struct Fruit {
    string name;
    int count;
    double unit_price;
    Date last_sale_date;
    // ...
    Fruit(const string& n, int c = 1, double p = 0.0) : name(n), count(c), unit_price(p) {}
};

//------------------------------------------------------------------------------

struct Fruit_order {
    bool operator()(const Fruit& a, const Fruit& b) const
    {
        return a.name<b.name;
    }
};

//------------------------------------------------------------------------------

int main()
{
    set<Fruit, Fruit_order> inventory;
    
    inventory.insert(Fruit("quince",5));
    inventory.insert(Fruit("apple", 200, 0.37));
}

//------------------------------------------------------------------------------
