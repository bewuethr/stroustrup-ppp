// Chapter 21, Exercise 8: take word frequency example from 21.6.1 and modify
// it to output its lines in order of frequency rather than lexicographical
// order ("3: C++" rather than "C++: 3")

#include "../lib_files/std_lib_facilities.h"
#include<map>

//------------------------------------------------------------------------------

int main()
try {
    map<string,int> words;

    const string ifname = "pics_and_txt/chapter21_ex08_in.txt";
    ifstream ifs(ifname.c_str());
    if (!ifs) error("couldn't open ",ifname);
    string s;
    while (ifs>>s) ++words[s];

    vector<pair<int,string> > v_words;

    typedef map<string,int>::const_iterator Iter;
    for (Iter p = words.begin(); p!=words.end(); ++p)
        v_words.push_back(make_pair(p->second,p->first));

    sort(v_words.begin(),v_words.end());

    typedef vector<pair<int,string> >::const_iterator V_iter;
    for (V_iter p = v_words.begin(); p!=v_words.end(); ++p)
        cout << p->first << ": " << p->second << '\n';
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