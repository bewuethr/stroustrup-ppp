/*
	simple "Programming: Principles and Practice using C++" course header to
	be used for the first few weeks.
	It provides the most common standard headers (in the global namespace)
	and minimal exception/error support.

	Students: please don't try to understand the details of headers just yet.
	All will be explained. This header is primarily used so that you don't have
	to understand every concept all at once.

	Revised April 25, 2010: simple_error() added
*/

#ifndef H112
#define H112 201004L

#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<stdexcept>
#include<limits>
#include<ctime>

//------------------------------------------------------------------------------

#ifdef _MSC_VER
#include <unordered_map>
#else
#include <ext/hash_map>
using __gnu_cxx::hash_map;

namespace __gnu_cxx {

    template<> struct hash<std::string>
    {
        size_t operator()(const std::string& s) const
        {
            return hash<char*>()(s.c_str());
        }
    };

} // of namespace __gnu_cxx
#endif

//------------------------------------------------------------------------------

typedef long Unicode;

//------------------------------------------------------------------------------

using namespace std;

template<class T> string to_string(const T& t)
{
	ostringstream os;
	os << t;
	return os.str();
}

struct Range_error : out_of_range {	// enhanced vector range error reporting
	int index;
	Range_error(int i) :out_of_range("Range error: "+to_string(i)), index(i) { }
};


// trivially range-checked vector (no iterator checking):
template<class T> struct Vector : public std::vector<T> {
	typedef typename std::vector<T>::size_type size_type;

	Vector() { }
	explicit Vector(size_type n) :std::vector<T>(n) { }
	Vector(size_type n, const T& v) :std::vector<T>(n,v) { }
	template <class I>
	Vector(I first, I last) :std::vector<T>(first,last) { }

	T& operator[](unsigned int i) // rather than return at(i);
	{
		if (i<0||this->size()<=i) throw Range_error(i);
		return std::vector<T>::operator[](i);
	}
	const T& operator[](unsigned int i) const
	{
		if (i<0||this->size()<=i) throw Range_error(i);
		return std::vector<T>::operator[](i);
	}
};

// disgusting macro hack to get a range checked vector:
#define vector Vector

// trivially range-checked string (no iterator checking):
struct String : std::string {

	String() { }
	String(const char* p) :std::string(p) { }
	String(const string& s) :std::string(s) {}
	template<class S> String(S s) :std::string(s) { }
	String(int sz, char val) :std::string(sz,val) { }
	template<class Iter> String(Iter p1, Iter p2) : std::string(p1,p2) { }

	char& operator[](unsigned int i) // rather than return at(i);
	{
		if (i<0||size()<=i) throw Range_error(i);
		return std::string::operator[](i);
	}

	const char& operator[](unsigned int i) const
	{
		if (i<0||size()<=i) throw Range_error(i);
		return std::string::operator[](i);
	}
};

#ifndef _MSC_VER
namespace __gnu_cxx {

    template<> struct hash<String>
    {
        size_t operator()(const String& s) const
        {
            return hash<std::string>()(s);
        }
    };

} // of namespace __gnu_cxx
#endif


struct Exit : runtime_error {
	Exit() :runtime_error("Exit") {}
};

// error() simply disguises throws:
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void error(const string& s, const string& s2)
{
	error(s+s2);
}

inline void error(const string& s, int i)
{
	ostringstream os;
	os << s <<": " << i;
	error(os.str());
}

#if _MSC_VER<1500
	// disgusting macro hack to get a range checked string:
	#define string String
	// MS C++ 9.0 have a built-in assert for string range check
	// and uses "std::string" in several places so that macro substitution fails
#endif

template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
						// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}


inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

inline void keep_window_open(string s)
{
	if (s=="") return;
	cin.clear();
	cin.ignore(120,'\n');
	for (;;) {
		cout << "Please enter " << s << " to exit\n";
		string ss;
		while (cin >> ss && ss!=s)
			cout << "Please enter " << s << " to exit\n";
		return;
	}
}



// error function to be used (only) until error() is introduced in Chapter 5:
inline void simple_error(string s)	// write ``error: s’’ and exit program
{
	cerr << "error: " << s << '\n';
	keep_window_open();		// for some Windows environments
	exit(1);
}

// make std::min() and std::max() accessible:
#undef min
#undef max

#include<iomanip>
inline ios_base& general(ios_base& b)	// to augment fixed and scientific
{
	b.setf(ios_base::fmtflags(0),ios_base::floatfield);
	return b;
}

// run-time checked narrowing cast (type conversion):
template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r)!=a) error(string("info loss"));
	return r;
}


inline int randint(int max) { return rand()%max; }

inline int randint(int min, int max) { return randint(max-min)+min; }

inline double sqrt(int x) { return sqrt(double(x)); }	// to match C++0x

#endif
