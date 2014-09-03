
//
// This is example code from Chapter 10.4 "Opening a file" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <fstream>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

struct Point
{
    int x;
    int y;

    friend istream& operator>>(istream& ist, Point& p)
    {
        char a,b,c;

        if ((ist >> a >> p.x >> b >> p.y >> c) && !(a == '(' && b == ',' && c == ')'))
            throw runtime_error("Invalid format");

        return ist;
    }

    friend ostream& operator<<(ostream& ost, const Point& p)
    {
        return ost << '(' << p.x << ',' << p.y << ')' << endl;
    }
};

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Please enter input file name: ";
    string name;
    cin >> name;
    ifstream ist(name.c_str());    // ist is an input stream for the file named name
    if (!ist) error("can't open input file ",name);

    vector<Point> points;
    Point p;
    while (ist>>p) points.push_back(p);
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
