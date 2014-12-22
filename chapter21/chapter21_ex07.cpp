// Chapter 21, Exercise 7: implement and test binary search for a vector<int>
// and a list<string>

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

// binary search for containers with random access iterators
template<class Ran, class T>
bool my_binary_search(Ran first, Ran last, const T& val)
{
    if (first==last) return false;  // sequence is empty
    Ran p = first + (last-first)/2;
    if (*p==val) return true;
    if (*p<val && p+1!=last) return my_binary_search(p,last,val);
    if (*p>val) return my_binary_search(first,p,val);
    return false;   // *p<val && p+1==last
}

//------------------------------------------------------------------------------

// return middle position between two bidirectional iterators
template<class Bid>
Bid middle(Bid first, Bid last)
{
    if (first==last) error("first==last in middle");

    // calculate distance
    int dist = 0;
    Bid p = first;
    while (p != last) {
        ++p;
        ++dist;
    }
    advance(first,dist/2);
    return first;
}

//------------------------------------------------------------------------------

// binary search for containers with bidirectional iterators, i.e., distance
// between two iterators cannot be calculated
template<class Bid, class T>
bool my_binary_bid_search(Bid first, Bid last, const T& val)
{
    if (first==last) return false;  // sequence is empty
    Bid p = middle(first,last);
    if (*p==val) return true;
    Bid p2 = last;
    --p2;
    if (*p<val && p!=p2) return my_binary_bid_search(p,last,val);
    if (*p>val) return my_binary_bid_search(first,p,val);
    return false;   // *p<val && p==p2, i.e., we are looking at the last element
}

//------------------------------------------------------------------------------

template<class Iter>
void print(Iter first, Iter last)
{
    while (first != last) {
        cout << *first << '\n';
        ++first;
    }
}

//------------------------------------------------------------------------------

int main()
try {
    // test for vector
    vector<int> vi;
    for (int i = 0; i<20; ++i)
        vi.push_back(2*i);
    cout << "Vector:\n";
    print(vi.begin(),vi.end());

    cout << "Enter int to find (-1 to exit): ";
    int i;
    while (cin>>i && i!=-1) {
        cout << i << " is "
            << (my_binary_search(vi.begin(),vi.end(),i) ? "" : "not ")
            << "in vi. Next int: ";
    }

    // test for list
    list<int> li(20);
    copy(vi.begin(),vi.end(),li.begin());
    cout << "\nList:\n";
    print(li.begin(),li.end());

    cout << "Enter int to find (-1 to exit): ";
    while (cin>>i && i!=-1) {
        cout << i << " is "
            << (my_binary_bid_search(li.begin(),li.end(),i) ? "" : "not ")
            << "in li. Next int: ";
    }
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