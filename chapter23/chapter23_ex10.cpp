// Chapter 23, exercise 10: modify table checking program from 23.9 to write a
// new table where rows starting with the same initial digit (the year) are
// merged

#include<iostream>
#include<fstream>
#include<sstream>
#include<regex>
#include<stdexcept>
#include<map>

using namespace std;

//------------------------------------------------------------------------------

struct bad_from_string : std::bad_cast
// class for reporting string cast errors
{
    const char* what() const throw() // override bad_cast's what()
    {
        return "bad cast from string";
    }
};

//------------------------------------------------------------------------------

template<class T> T from_string(const string& s)
{
    istringstream is(s);
    T t;
    if (!(is >> t)) throw bad_from_string();
    return t;
}

//------------------------------------------------------------------------------

struct Class_size {
    Class_size() :n_boys(0), n_girls(0) { }
    Class_size(int b, int g) :n_boys(b), n_girls(g) { }
    int n_boys;
    int n_girls;
};

//------------------------------------------------------------------------------

int main()
try
{
    ifstream in("pics_and_txt/chapter23_ex09_in1.txt"); // input file
    if (!in) throw runtime_error("no input file");
    ofstream ofs("pics_and_txt/chapter23_ex10_out.txt");
    if (!ofs) throw runtime_error("can't open output file");

    string line;    // input buffer
    int lineno = 0;

    regex header("^[\\w ]+(\\t[\\w ]+)*$");
    regex row("^(\\w)[\\w ]*(\\t\\d+)(\\t\\d+)(\\t\\d+)$");

    if (getline(in,line)) {        // check header line
        smatch matches;
        if (!regex_match(line,matches,header)) {
            throw runtime_error("no header");
        }
        ofs << line << '\n';
    }

    // column totals:
    int boys = 0;
    int girls = 0;

    // current line values:
    int curr_boy = 0;
    int curr_girl = 0;
    int rest_boy = 0;   // boys in "REST" row
    int rest_girl = 0;  // girls in "REST" row

    // map to keep track of year totals
    map<int,Class_size> class_sizes;

    while (getline(in,line)) {  // extract and check data
        ++lineno;
        if (line=="") continue;
        smatch matches;
        if (!regex_match(line,matches,row)) 
            throw runtime_error("bad line " + to_string(lineno));

        // check row:
        curr_boy = from_string<int>(matches[2]);
        curr_girl = from_string<int>(matches[3]);
        int curr_total = from_string<int>(matches[4]);
        if (curr_boy+curr_girl != curr_total)
            throw runtime_error("bad row sum");

        boys += curr_boy;
        girls += curr_girl;

        if (isdigit(*matches[1].first)) {
            class_sizes[from_string<int>(matches[1])].n_boys += curr_boy;
            class_sizes[from_string<int>(matches[1])].n_girls += curr_girl;
        }
        if (matches[1] == "R") {    // "REST" row
            rest_boy = curr_boy;
            rest_girl = curr_girl;
        }
    }

    // check columns:
    if (2*curr_boy != boys)  throw runtime_error("boys don't add up");
    if (2*curr_girl != girls) throw runtime_error("girls don't add up");
    cout << "Checked " << lineno << " lines - all good!\n";

    typedef map<int,Class_size>::const_iterator MCI;
    int boys_sum = 0;
    int girls_sum = 0;
    for (MCI p = class_sizes.begin(); p!=class_sizes.end(); ++p) {
        ofs << p->first << '\t' << p->second.n_boys << '\t' <<
            p->second.n_girls << '\t' << p->second.n_boys + p->second.n_girls << '\n';
        boys_sum += p->second.n_boys;
        girls_sum += p->second.n_girls;
    }
    ofs << "REST\t" << rest_boy << '\t' << rest_girl << '\t' <<
        rest_boy + rest_girl << '\n';
    ofs << "Alle klasser\t" << boys_sum + rest_boy << '\t' <<
        girls_sum + rest_girl << '\t' <<
        boys_sum + girls_sum + rest_boy + rest_girl << '\n';
}
catch (std::exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
