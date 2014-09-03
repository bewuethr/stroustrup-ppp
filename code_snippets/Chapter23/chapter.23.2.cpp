
//
// This is example code from Chapter 23.2 "Strings" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

basic_string<Unicode> a_unicode_string;

//typedef basic_string<char> string;    // string means basic_string<char>

template<class T>
string to_string(const T& t)
{
    ostringstream os;
    os << t;
    return os.str();
}

//------------------------------------------------------------------------------

struct bad_from_string : std::bad_cast
    // class for reporting string cast errors
{
    const char* what() const throw()    // override bad_cast's what()
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

void do_something(const string s)
try
{
    int i = from_string<int>(s);
    // ...
}
catch (bad_from_string e) {
    error ("bad input string",s);
};

//------------------------------------------------------------------------------

int main()
try
{
    string s1 = to_string(12.333);
    string s2 = to_string(1+5*6-99/7);
    double d = from_string<double>("12.333");
    do_something("Mary had a little lamb");
    int g = from_string<int>("Mary had a little lamb");    // oops!
}
catch (std::exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
};

//------------------------------------------------------------------------------

struct bad_lexical_cast : std::bad_cast
{
    const char* what() const throw() { return "bad cast"; }
};

//------------------------------------------------------------------------------

template<typename Target, typename Source>
Target lexical_cast(Source arg)
{
    std::stringstream interpreter;
    Target result;

    if (!(interpreter << arg)        // read arg into stream
        || !(interpreter >> result)        // read result from stream
        || !(interpreter >> std::ws).eof())    // stuff left in stream?
        throw bad_lexical_cast();

    return result;
}

//------------------------------------------------------------------------------
