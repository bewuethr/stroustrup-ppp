// Chapter 06, exercise 04: Name_value class with a constructor; rework exercise
// 19 from Chapter 4 to use vector<Name_value>

#include "../lib_files/std_lib_facilities.h"

class Name_value {
public:
    string name;
    int value;
    Name_value(string str, int val)
        :name(str), value(val) { }
};

int main()
try {
    // input
    cout << "Enter name/value pairs, like 'Joe 17'. Terminate with NoName 0\n";
    string name = "";
    int value = -1;
    vector<Name_value> nv_vec;
    while (cin>>name>>value && !(name=="NoName" && value==0)) {
        for (int i = 0; i<nv_vec.size(); ++i)
            if (name == nv_vec[i].name) error("name occurs twice: ",name);
        nv_vec.push_back(Name_value(name,value));
    }

    // print list of name/value pairs
    for (int i = 0; i<nv_vec.size(); ++i) {
        cout << "(" << nv_vec[i].name << ',' << nv_vec[i].value << ")\n";
    }
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
