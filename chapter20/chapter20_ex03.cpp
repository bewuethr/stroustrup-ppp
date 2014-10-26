// Chapter 20, Exercise 03: look at the palindrome example (§18.6); redo the
// Jack-and-Jill example from §20.1.2 using that variety of techniques.

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

// return a pointer to the element in vector v that has the highest value
double* high_vec(vector<double>& v)
{
    if (v.size()==0) return 0;
    double* highest = &v[0];
    for (int i = 1; i<v.size(); ++i)
        if (v[i]>*highest) highest = &v[i];
    return highest;
}

// return a pointer to the element in array arg with n elements that has the
// highest value
double* high_arr(double arg[], int n)
{
    if (n==0) return 0;
    double* highest = &arg[0];
    for (int i = 0; i<n; ++i)
        if (arg[i]>*highest) highest = &arg[i];
    return highest;
}

// return a pointer to the element in [first,last) that has the highest value
double* high_ptr(double* first, double* last)
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

    // use vectors: turn jack_data into vector
    vector<double> jack_vec;
    for (int i = 0; i<jack_count; ++i)
        jack_vec.push_back(jack_data[i]);
    double* jack_high_vec = high_vec(jack_vec);
    double* jill_high_vec = high_vec(*jill_data);
    cout << "Vector: Jill's max: " << *jill_high_vec <<
        "; Jack's max: " << *jack_high_vec << "\n";

    // use arrays: turn jill_data into array
    double* jill_arr = new double[(*jill_data).size()];
    for (int i = 0; i<(*jill_data).size(); ++i)
        jill_arr[i] = (*jill_data)[i];
    double* jack_high_arr = high_arr(jack_data,jack_count);
    double* jill_high_arr = high_arr(jill_arr,(*jill_data).size());
    cout << "Array: Jill's max: " << *jill_high_arr <<
        "; Jack's max: " << *jack_high_arr << "\n";
    delete[] jill_arr;

    // use pointers
    double* jack_high_ptr = high_ptr(jack_data,jack_data+jack_count);
    vector<double>& v = *jill_data;
    double* jill_high_ptr = high_ptr(&v[0],&v[0]+v.size());

    cout << "Pointer: Jill's max: " << *jill_high_ptr <<
        "; Jack's max: " << *jack_high_ptr << "\n";

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




