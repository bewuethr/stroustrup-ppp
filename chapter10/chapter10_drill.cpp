// Chapter 10, drill

#include "../lib_files/std_lib_facilities.h"

// type for points
struct Point {
    int x;
    int y;
    Point() :x(0), y(0) { }
    Point(int xx, int yy) :x(xx), y(yy) { }
};

bool operator==(const Point& p1, const Point& p2)
{
    return p1.x==p2.x && p1.y==p2.y;
}

bool operator!=(const Point& p1, const Point& p2)
{
    return !(p1==p2);
}

ostream& operator<<(ostream& os, const Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

istream& operator>>(istream& is, Point& p)
{
    int x, y;
    char ch1, ch2, ch3;
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (!is) return is;
    if (ch1!='(' || ch2!=',' || ch3!=')') {
        is.clear(ios_base::failbit);
        return is;
    }
    p = Point(x,y);
    return is;
}

// function to print to cout
void print_vector(const vector<Point>& points)
{
    for (int i = 0; i<points.size(); ++i)
        cout << points[i] << endl;
}

// function to print to file
void write_to_file(const vector<Point>& points, const string& name)
{
    ofstream ost(name.c_str());
    if (!ost) error("can't open output file ",name);
    for (int i = 0; i<points.size(); ++i)
        ost << points[i] << endl;
}

// function to read from file
void fill_from_file(vector<Point>& points, const string& name)
{
    ifstream ist(name.c_str());
    if (!ist) error("can't open input file, ",name);
    Point pp;
    while (ist>>pp) points.push_back(pp);
}

// function to compare two vectors
void compare_vectors(const vector<Point>& points1, const vector<Point>& points2)
{
    if (points1.size() != points2.size())
        error("Something's wrong!");
    for (int i = 0; i<points1.size(); ++i) {
        if (points1[i] != points2[i])
            error("Something's wrong!");
    }
}

int main()
try {
    // enter points
    vector<Point> original_points;
    cout << "Enter 7 (x,y) pairs:\n";
    for (int i = 0; i<7; ++i) {
        Point p;
        cin >> p;
        original_points.push_back(p);
    }

    // print points
    cout << "\nOriginal points:\n";
    print_vector(original_points);

    // write points to file
    string filename = "pics_and_txt/chapter10_drill_out.txt";
    write_to_file(original_points,filename);

    // read points from file
    vector<Point> processed_points;
    fill_from_file(processed_points,filename);

    // print data from both vectors
    cout << "\nData from ifstream:\n";
    print_vector(processed_points);
    cout << "\nOriginal data:\n";
    print_vector(original_points);

    // compare vectors
    compare_vectors(original_points,processed_points);

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
