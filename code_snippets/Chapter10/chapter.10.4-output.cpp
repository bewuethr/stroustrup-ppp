
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
    cout << "Please enter name of output file: ";
    string name;
    cin >> name;
    ofstream ost(name.c_str());    // ost is an output stream for a file named name
    if (!ost) error("can't open output file ",name);

    vector<Point> points;

    for (int i = 0; i < 10; ++i)
    {
        Point p = {i, i*i};
        points.push_back(p);
    }

    for (int i=0; i<points.size(); ++i)
        ost << '(' << points[i].x << ',' << points[i].y << ")\n";
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
};

//------------------------------------------------------------------------------

void fill_from_file(vector<Point>& points, string& name)
{
    ifstream ist(name.c_str());    // open file for reading
    if (!ist) error("can't open input file ",name);
    // ... use ist ...
    // the file is implicitly closed when we leave the function
}

//------------------------------------------------------------------------------
