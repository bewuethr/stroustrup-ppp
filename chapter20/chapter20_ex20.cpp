// Chapter 20, Exercise 20: compare vector and list by timing how long it takes
// to insert N random ints into a vector/list such that the container is always
// sorted. For which N is the list faster than the vector?

// At around 1500 elements, the vector starts to be much faster, and for a few
// 10'000 elements, it's faster by about an order of a magnitude - rather unex-
// pected, given that inserting in the middle of a long container should be a
// strength of the list

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

// insert n into container, keeping it sorted
template<class C>
void insert(int n, C& container)
{
    typename C::iterator it = container.begin();
    while (it!=container.end() && *it<=n) ++it;
    container.insert(it,n);
}

//------------------------------------------------------------------------------

// time it takes to insert n_elem elements into a container, keeping it sorted
template<class C>
double get_time(int n_elem, C& container)
{
    clock_t t1 = clock();
    if (t1==clock_t(-1)) error("clock() didn't work");
    for (int i = 0; i<n_elem; ++i) {
        insert(randint(n_elem),container);
    }
    clock_t t2 = clock();
    if (t2==clock_t(-1)) error("clock overflow");
    return double(t2-t1)/CLOCKS_PER_SEC;
}

//------------------------------------------------------------------------------

int main()
try {
    const int n_max = 2100;
    const int n_init = 1000;
    const int n_incr = 50;
    const int reps = 30; // average over this many repetitions
    vector<double> vec_times;
    vector<double> list_times;
    vector<int> sizes;

    for (int n = n_init; n<=n_max; n+=n_incr) {
        sizes.push_back(n);

        // vector test
        double vec_time = 0;
        for (int i = 0; i<reps; ++i) {
            vector<int> v;
            vec_time += get_time(n,v);
        }
        vec_times.push_back(vec_time/reps);

        // list test
        double list_time = 0;
        for (int i = 0; i<reps; ++i) {
            list<int> l;
            list_time += get_time(n,l);
        }
        list_times.push_back(list_time/reps);
    }

    cout << "Size    t_vec [s]  t_list [s]  list/vec\n";
    for (int i = 0; i<vec_times.size(); ++i)
        cout << right << setw(6) << sizes[i] << "  "
            << fixed << setprecision(3)
            << left << setw(9) << vec_times[i] << "  "
            << setw(12) << list_times[i]
            << list_times[i]/vec_times[i] << "\n";
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


