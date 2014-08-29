// Chapter 05, exercise 14: read (day-of-the-week,value) pairs, collect values
// for each day in a separate vector. Ignore illegal days, but accept common
// synonyms. Print sum and list of values for each day in the end, count number
// of rejected entries.

#include "../lib_files/std_lib_facilities.h"

vector<int> mondays;
vector<int> tuesdays;
vector<int> wednesdays;
vector<int> thursdays;
vector<int> fridays;
vector<int> saturdays;
vector<int> sundays;
int rejected = 0;

// put input into right vector, count rejected entries
int handle_input(string day, int val)
{
    int cont = 0;
    if (day=="Monday" || day=="monday" || day=="Mon" || day=="mon")
        mondays.push_back(val);
    else if (day=="Tuesday" || day=="tuesday" || day=="Tue" || day=="tue")
        tuesdays.push_back(val);
    else if (day=="Wednesday" || day=="wednesday" || day=="Wed" || day=="wed")
        wednesdays.push_back(val);
    else if (day=="Thursday" || day=="thursday" || day=="Thu" || day=="thu")
        thursdays.push_back(val);
    else if (day=="Friday" || day=="friday" || day=="Fri" || day=="fri")
        fridays.push_back(val);
    else if (day=="Saturday" || day=="saturday" || day=="Sat" || day=="sat")
        saturdays.push_back(val);
    else if (day=="Sunday" || day=="sunday" || day=="Sun" || day=="sun")
        sundays.push_back(val);
    else if (day=="q" && val==0)
        cont = -1;
    else ++rejected;
    return cont;
}

// compute sum of vector elements
int get_sum(vector<int> v)
{
    int sum = 0;
    for (int i = 0; i<v.size(); ++i) sum += v[i];
    return sum;
}

// print weekday
void print_day(string day, vector<int> v)
{
    cout << day << " (sum: " << get_sum(v) << ")\n";
    cout << "Values:";
    for (int i = 0; i<v.size(); ++i)
        cout << ' ' << v[i];
    cout << endl;
}

// print results: sum and values for each weekday, number of rejected entries
void print_results()
{
    print_day("Monday",mondays);
    print_day("Tuesday",tuesdays);
    print_day("Wednesday",wednesdays);
    print_day("Thursday",thursdays);
    print_day("Friday",fridays);
    print_day("Saturday",saturdays);
    print_day("Sunday",sundays);
    cout << rejected << " values rejected\n";
}

int main()
try {
    string day = " ";
    int val = 0;
    cout << "Enter weekday/value pairs, exit with 'q 0'\n";
    while (cin>>day>>val) {
        int cont = handle_input(day,val);
        if (cont == -1) {
            print_results();
            return 0;
        }
    }
    error("Invalid input");
}
catch (exception& e) {
    cerr << "Error: " << e.what() << endl;
    //keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Unknown exception!\n";
    return 2;
}
