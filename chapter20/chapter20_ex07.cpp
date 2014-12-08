// Chapter 20, Exercise 07: find the lexicographical last string in an unsorted
// vector<string>. Beware that "lexicographical" is not the same as "alphabeti-
// cal", as "Zzzz"<"aaa" (uppercase letters are lexicographically before lower-
// case letters).

#include "../lib_files/std_lib_facilities.h"

// returns an iterator to the biggest element of the argument
template<class Iterator>
Iterator biggest_element(Iterator first, Iterator last)
{
    Iterator high = first;
    while (first != last) {
        if (*first>*high) high = first;
        ++first;
    }
    return high;
}

int main()
try {
    vector<string> vs;
    string s;
    cout << "Enter a few words, Ctrl-Z to end: ";
    while (cin>>s)
        vs.push_back(s);

    vector<string>::iterator last = biggest_element(vs.begin(),vs.end());
    if (last!=vs.end())
        cout << "The lexicographically last string in the vector is \""
            << *last << "\".\n";
    else
        cout << "Something went wrong.\n";
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






