// Chapter 20, Exercise 02: get the Jack-and-Jill example from §20.1.2 to work;
// use input from a couple of small files to test it

#include "../lib_files/std_lib_facilities.h"

double* get_from_jack(int* count)
{
    string ifname = "pics_and_txt/chapter20_ex02_in1.txt";
    ifstream ifs(ifname.c_str());
    if (!ifs) error("Can't open input file ",ifname);

    // Elegantly read input into vector first
    vector<double> v;
    double d;
    while (ifs>>d) v.push_back(d);

    *count = v.size();
    double* data = new double[*count];
    for (int i = 0; i<v.size(); ++i)
        data[i] = v[i];

    return data;
}

vector<double>* get_from_jill()
{
    string ifname = "pics_and_txt/chapter20_ex02_in2.txt";
    ifstream ifs(ifname.c_str());
    if (!ifs) error ("Can't open input file ",ifname);

    vector<double>* v = new vector<double>;
    double d;
    while (ifs>>d) (*v).push_back(d);

    return v;
}

// Return a pointer to the element in [first,last) that has the highest value
double* high(double* first, double* last)
{
    double h = -1;
    double* high;
    for(double* p = first; p!=last; ++p)
        if (h<*p) { high = p; h = *p; }
    return high;
}

int main()
try {
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data = get_from_jill();

    double* jack_high = high(jack_data,jack_data+jack_count);
    vector<double>& v = *jill_data;
    double* jill_high = high(&v[0],&v[0]+v.size());

    cout << "Jill's max: " << *jill_high << "; Jack's max: " << *jack_high;

    delete[] jack_data;
    delete jill_data;
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



