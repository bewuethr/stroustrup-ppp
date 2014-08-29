// Chapter 09, exercise 02: Name_pairs class
// Exercise 03: add << operator, define == and != for Name_pairs

#include "../lib_files/std_lib_facilities.h"

// type for (name,age) pairs
class Name_pairs {
public:
    void read_names();  // reads a series of names
    void read_ages();   // prompt user for age for each name
    void print() const; // print (name[i],age[i]) pairs
    void sort();        // sort name vector alphabetically, with matching age vector
    const vector<string>& get_name() const { return name; }
    const vector<double>& get_age() const { return age; }
private:
    vector<string> name;
    vector<double> age;
};

// reads series of names
void Name_pairs::read_names()
{
    cout << "Enter names, 'NoName' to finish: ";
    string s;
    while (cin>>s && s!="NoName") {
        for (int i = 0; i<name.size(); ++i)
            if (name[i]==s) error("Name exists already: ",s);
        name.push_back(s);
    }
}

// prompt user to enter age for each name
void Name_pairs::read_ages()
{
    age = vector<double>();
    for (int i = 0; i<name.size(); ++i) {
        cout << "Age of " << name[i] << ": ";
        double a;
        cin >> a;
        age.push_back(a);
    }
}

// prints (name[i],age[i]) pairs
void Name_pairs::print() const
{
    if (name.size() != age.size())
        error("print(): name and age must be the same size");
    for (int i = 0; i<name.size(); ++i) {
        cout << '(' << name[i] << ',' << age[i] << ')' << endl;
    }
}

// sort name vector alphabetically, match age vector
void Name_pairs::sort()
{
    if (name.size() != age.size())
        error("sort(): name and age must be the same size");
    Vector<string> name_presort = name;
    Vector<double> age_cp = age;
    std::sort(name.begin(),name.end());
    for (int i = 0; i<name.size(); ++i) {
        for (int j = 0; j<name_presort.size(); ++j) {
            if (name[i] == name_presort[j])
                age[i] = age_cp[j];
        }
    }
}

// operators
ostream& operator<<(ostream& os, const Name_pairs& np)
{
    if (np.get_name().size() != np.get_age().size())
        error("<<: name and age must be the same size");
    for (int i = 0; i<np.get_name().size(); ++i)
        os << '(' << np.get_name()[i] << ',' << np.get_age()[i] << ')' << endl;
    return os;
}

bool operator==(const Name_pairs& a, const Name_pairs& b)
{
    if (a.get_name().size()!=b.get_name().size() || a.get_age().size() != b.get_age().size())
        return false;
    bool equal = true;
    for (int i = 0; i<a.get_name().size(); ++i) {
        if (a.get_name()[i] != b.get_name()[i])
            return false;
    }
    for (int i = 0; i<a.get_age().size(); ++i) {
        if (a.get_age()[i] != b.get_age()[i])
            return false;
    }
    return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
    return !(a==b);
}

int main()
try {
    Name_pairs np1;
    np1.read_names();
    np1.read_ages();
    Name_pairs np2;
    np2.read_names();
    np2.read_ages();
    cout << "np1:\n" << np1;
    cout << "np2:\n" << np2;
    if (np1==np2) cout << "Identical!\n";
    if (np1!=np2) cout << "Not identical!\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
