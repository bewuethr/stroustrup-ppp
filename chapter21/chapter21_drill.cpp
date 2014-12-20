// Chapter 21, drill

#include "../lib_files/std_lib_facilities.h"
#include<map>
#include<numeric>

//------------------------------------------------------------------------------

struct Item {
    string name;
    int iid;
    double value;
    Item() :name(), iid(0), value(0) { }
    Item(string n, int i, double v) :name(n), iid(i), value(v) { }
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Item& it)
{
    string name;
    int iid;
    double value;
    is >> name >> iid >> value;
    if (!is) return is;
    it = Item(name,iid,value);
    return is;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Item& it)
{
    return os << it.name << '\t' << it.iid << '\t' << it.value;
}

//------------------------------------------------------------------------------

struct  Comp_by_name {
    bool operator()(const Item& a, const Item& b) const
    {
        return a.name < b.name;
    }
};

//------------------------------------------------------------------------------

struct Comp_by_iid {
    bool operator()(const Item& a, const Item& b) const
    {
        return a.iid < b.iid;
    }
};

//------------------------------------------------------------------------------

bool comp_by_value(const Item& a, const Item& b)
{
    return a.value < b.value;
}

//------------------------------------------------------------------------------

class Find_by_name {
    string name;
public:
    Find_by_name(const string& s) :name(s) { }
    bool operator()(const Item& it) const
    {
        return it.name == name;
    }
};

//------------------------------------------------------------------------------

class Find_by_iid {
    int iid;
public:
    Find_by_iid(int i) :iid(i) { }
    bool operator()(const Item& it) const
    {
        return it.iid == iid;
    }
};

//------------------------------------------------------------------------------

template<class iter>
void print(iter first, iter last)
{
    while (first!=last) {
        cout << *first << '\n';
        ++first;
    }
}

//------------------------------------------------------------------------------

void f1()
{
    cout << "First round: vector\n";
    vector<Item> vi;
    const string ifname = "pics_and_txt/chapter21_drill_in.txt";

    // 1.1
    cout << "1.1: fill with ten items from file\n";
    {
        ifstream ifs(ifname.c_str());
        if (!ifs) error("can't open ",ifname);
        Item i;
        while (ifs>>i) vi.insert(vi.end(),i);
    }
    print(vi.begin(),vi.end());

    // 1.2
    cout << "\n1.2: sort by name\n";
    sort(vi.begin(),vi.end(),Comp_by_name());
    print(vi.begin(),vi.end());

    // 1.3
    cout << "\n1.3: sort by iid\n";
    sort(vi.begin(),vi.end(),Comp_by_iid());
    print(vi.begin(),vi.end());

    // 1.4 - use function instead of function object
    cout << "\n1.4: sort by value, print in decreasing order\n";
    sort(vi.begin(),vi.end(),comp_by_value);
    reverse(vi.begin(),vi.end());
    print(vi.begin(),vi.end());

    // 1.5 - use function instead of function object
    cout << "\n1.5: insert two items\n";
    vi.insert(vi.end(),Item("Horsesh",99,12.34));
    vi.insert(vi.end(),Item("C S400",9988,499.95));
    sort(vi.begin(),vi.end(),comp_by_value);
    reverse(vi.begin(),vi.end());
    print(vi.begin(),vi.end());

    // 1.6
    cout << "\n1.6: remove two items identified by name\n";
    vector<Item>::iterator vi_it =
        find_if(vi.begin(),vi.end(),Find_by_name("GoPro"));
    vi.erase(vi_it);
    vi_it = find_if(vi.begin(),vi.end(),Find_by_name("Xbox"));
    vi.erase(vi_it);
    print(vi.begin(),vi.end());

    // 1.7
    cout << "\n1.7: remove two tems identified by iid\n";
    vi_it = find_if(vi.begin(),vi.end(),Find_by_iid(14910));
    vi.erase(vi_it);
    vi_it = find_if(vi.begin(),vi.end(),Find_by_iid(754));
    vi.erase(vi_it);
    print(vi.begin(),vi.end());
}

//------------------------------------------------------------------------------

void f2()
{
    cout << "\nSecond round: list\n";
    list<Item> li;
    const string ifname = "pics_and_txt/chapter21_drill_in.txt";

    // 1.1
    cout << "1.1: fill with ten items from file\n";
    {
        ifstream ifs(ifname.c_str());
        if (!ifs) error("can't open ",ifname);
        Item i;
        while (ifs>>i) li.insert(li.end(),i);
    }
    print(li.begin(),li.end());

    // 1.2
    cout << "\n1.2: sort by name\n";
    li.sort(Comp_by_name());
    print(li.begin(),li.end());

    // 1.3
    cout << "\n1.3: sort by iid\n";
    li.sort(Comp_by_iid());
    print(li.begin(),li.end());

    // 1.4 - use function instead of function object
    cout << "\n1.4: sort by value, print in decreasing order\n";
    li.sort(comp_by_value);
    reverse(li.begin(),li.end());
    print(li.begin(),li.end());

    // 1.5 - use function instead of function object
    cout << "\n1.5: insert two items\n";
    li.insert(li.end(),Item("Horsesh",99,12.34));
    li.insert(li.end(),Item("C S400",9988,499.95));
    li.sort(comp_by_value);
    reverse(li.begin(),li.end());
    print(li.begin(),li.end());

    // 1.6
    cout << "\n1.6: remove two items identified by name\n";
    list<Item>::iterator li_it =
        find_if(li.begin(),li.end(),Find_by_name("GoPro"));
    li.erase(li_it);
    li_it = find_if(li.begin(),li.end(),Find_by_name("Xbox"));
    li.erase(li_it);
    print(li.begin(),li.end());

    // 1.7
    cout << "\n1.7: remove two tems identified by iid\n";
    li_it = find_if(li.begin(),li.end(),Find_by_iid(14910));
    li.erase(li_it);
    li_it = find_if(li.begin(),li.end(),Find_by_iid(754));
    li.erase(li_it);
    print(li.begin(),li.end());
}

//------------------------------------------------------------------------------

// 2.5
void read_pair(map<string,int>& msi)
{
    string s;
    int i;
    cin >> s >> i;
    if (!cin) error("Problem reading from cin");
    msi[s] = i;
}

//------------------------------------------------------------------------------

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T,U>& p)
{
    os << setw(12) << left << p.first << '\t' << p.second;
    return os;
}

//------------------------------------------------------------------------------

template<class T>
struct Map_add {
    T operator()(T v, const pair<string,T>& p)
    {
        return v + p.second;
    }
};

//------------------------------------------------------------------------------

void f3()
{
    // 2.1
    map<string,int> msi;

    // 2.2
    msi["lecture"] = 21;
    msi["university"] = 35;
    msi["education"] = 15;
    msi["school"] = 99;
    msi["kindergarten"] = 105;
    msi["river"] = 5;
    msi["city"] = 10;
    msi["capital"] = 70;
    msi["software"] = 88;
    msi["hardware"] = 43;

    // 2.3
    print(msi.begin(),msi.end());

    // 2.4
    typedef map<string,int>::const_iterator MI;
    MI p = msi.begin();
    while (p!=msi.end()) p = msi.erase(p);
    cout << "Size of map after deleting: " << msi.size() << '\n';

    // 2.6
    cout << "Enter 10 (string,int) pairs, separated by space:\n";
    for (int i = 0; i<10; ++i)
        read_pair(msi);

    // 2.7
    cout << '\n';
    print(msi.begin(),msi.end());

    // 2.8
    int msi_sum = 0;
    msi_sum = accumulate(msi.begin(),msi.end(),msi_sum,Map_add<int>());
    cout << "\nSum of all ints in msi: " << msi_sum << '\n';

    // 2.9
    map<int,string> mis;

    // 2.10
    for (p = msi.begin(); p!=msi.end(); ++p)
        mis[p->second] = p->first;

    // 2.11
    cout << "\nContents of mis:\n";
    print(mis.begin(),mis.end());
}

//------------------------------------------------------------------------------

template<class T>
class Less_than {
    T v;
public:
    Less_than(T val) :v(val) { }
    bool operator()(T x) const { return x < v; }
};

//class Less_than {
//    double v;
//public:
//    Less_than(double val) :v(val) { }
//    bool operator()(double x) const { return x < v; }
//};

//------------------------------------------------------------------------------

void f4()
{
    // 3.1
    const string fname = "pics_and_txt/chapter21_drill_in2.txt";
    ifstream ifs(fname.c_str());
    if (!ifs) error("can't open ",fname);
    vector<double> vd;
    double d;
    while (ifs>>d) vd.push_back(d);

    // 3.2
    cout << "vd:\n";
    print(vd.begin(),vd.end());

    // 3.3
    vector<int> vi(vd.size());
    copy(vd.begin(),vd.end(),vi.begin());

    // 3.4
    cout << "\n(vd,vi) pairs:\n";
    for (int i = 0; i<vd.size(); ++i) {
        cout << '(' << vd[i] << ',' << vi[i] << ")\n";
    }

    // 3.5
    double sum_vd = 0;
    sum_vd = accumulate(vd.begin(),vd.end(),sum_vd);
    cout << "\nSum of the elements of vd: " << sum_vd << '\n';

    // 3.6
    int sum_vi = 0;
    sum_vi = accumulate(vi.begin(),vi.end(),sum_vi);
    cout << "Difference of sum_vd and sum_vi: " << sum_vd - sum_vi << '\n';

    // 3.7
    reverse(vd.begin(),vd.end());
    cout << "\nvd after reverse:\n";
    print(vd.begin(),vd.end());

    // 3.8
    double vd_mean = sum_vd / vd.size();
    cout << "\nMean value of elements in vd: " << vd_mean << '\n';

    // 3.9
    vector<double> vd2(count_if(vd.begin(),vd.end(),Less_than<double>(vd_mean)));
    copy_if(vd.begin(),vd.end(),vd2.begin(),Less_than<double>(vd_mean));
    cout << "\nvd2:\n";
    print(vd2.begin(),vd2.end());

    // 3.10
    sort(vd.begin(),vd.end());
    cout << "\nvd:\n";
    print(vd.begin(),vd.end());
}

//------------------------------------------------------------------------------

int main()
try {
    f1();

    // 1.8
    f2();

    f3();

    f4();
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