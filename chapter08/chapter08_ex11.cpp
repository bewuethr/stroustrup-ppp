// Chapter 08, exercise 11: write function maxv() that returns the largest
// element of a vector argument
// Exercise 12: functions to find smallest/largest element, mean and median

#include "../lib_files/std_lib_facilities.h"

// struct for vector properties
struct Vector_properties {
    Vector_properties();
    int smallest;
    int largest;
    double mean;
    int median;
};

 Vector_properties::Vector_properties()
    :smallest(0), largest(0), mean(0), median(0) { }

 void print(const vector<int>& v)
 {
     cout << "{ ";
     for (int i = 0; i<v.size(); ++i)
         cout << v[i] << ' ';
     cout << " }\n";
 }

// returns largest element of vector argument
int maxv(const vector<int>& v)
{
    if (v.size()==0) error("maxv: argument vector is empty");
    int v_max = v[0];
    if (v.size()==1) return v_max;
    for (int i = 1; i<v.size(); ++i) {
        if (v[i]>v_max) v_max = v[i];
    }
    return v_max;
}

// returns smallest element of vector argument
int minv(const vector<int>& v)
{
    if (v.size()==0) error("minv: argument vector is empty");
    int v_min = v[0];
    if (v.size()==1) return v_min;
    for (int i = 1; i<v.size(); ++i) {
        if (v[i]<v_min) v_min = v[i];
    }
    return v_min;
}

// returns mean of vector argument
double meanv(const vector<int>& v)
{
    if (v.size()==0) error("meanv: argument vector is empty");
    double v_sum = 0;
    for (int i = 0; i<v.size(); ++i)
        v_sum += v[i];
    return v_sum / v.size();
}

// returns median of vector argument
int medianv(vector<int> v)
{
    if (v.size()==0) error("medianv: argument vector is empty");
    sort(v.begin(),v.end());
    return v[v.size()/2];
}

Vector_properties get_props(const vector<int>& v)
{
    Vector_properties vec_props;
    vec_props.largest = maxv(v);
    vec_props.smallest = minv(v);
    vec_props.mean = meanv(v);
    vec_props.median = medianv(v);
    return vec_props;
}

int main()
try
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    v.push_back(8);
    v.push_back(6);
    v.push_back(4);
    v.push_back(2);
    v.push_back(99);
    Vector_properties vec_props = get_props(v);

    cout << "Vector:\n";
    print(v);

    cout << "max: " << vec_props.largest << endl;
    cout << "min: " << vec_props.smallest << endl;
    cout << "mean: " << vec_props.mean << endl;
    cout << "median: " << vec_props.median << endl;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
