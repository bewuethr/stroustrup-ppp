// Chapter 23, exercise 9: use eof() to simplify the table checking program from
// 23.9 - it makes it possible to determine which line of a table is the last
// one. Test with empty lines after the table and files that don't end with a
// newline at all

// chapter23_ex09_in1.txt ends with \n on the last line
// chapter23_ex09_in2.txt has empty lines after the table
// chapter23_ex09_in3.txt ends wihtout a newline
// chapter23_ex09_in4.txt has an empty line in the middle

#include<iostream>
#include<fstream>
#include<sstream>
#include<regex>
#include<stdexcept>

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

int main()
try
{
    ifstream in("pics_and_txt/chapter23_ex09_in1.txt"); // input file
    if (!in) throw runtime_error("no input file");

    string line;    // input buffer
    int lineno = 0;

    regex header("^[\\w ]+(\\t[\\w ]+)*$");
    regex row("^[\\w ]+(\\t\\d+)(\\t\\d+)(\\t\\d+)$");

    if (getline(in,line)) {        // check header line
        smatch matches;
        if (!regex_match(line,matches,header)) {
            throw runtime_error("no header");
        }
    }

    // column totals:
    int boys = 0;
    int girls = 0;

    // current line values:
    int curr_boy = 0;
    int curr_girl = 0;

    while (getline(in,line)) {  // extract and check data
        ++lineno;
        if (line=="") continue;
        smatch matches;
        if (!regex_match(line, matches, row)) 
            throw runtime_error("bad line " + to_string(lineno));

        // check row:
        curr_boy = from_string<int>(matches[1]);
        curr_girl = from_string<int>(matches[2]);
        int curr_total = from_string<int>(matches[3]);
        if (curr_boy+curr_girl != curr_total) throw runtime_error("bad row sum");

        boys += curr_boy;
        girls += curr_girl;
    }

    // check columns:
    if (2*curr_boy != boys)  throw runtime_error("boys don't add up");
    if (2*curr_girl != girls) throw runtime_error("girls don't add up");
    cout << "Checked " << lineno << " lines - all good!\n";
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
