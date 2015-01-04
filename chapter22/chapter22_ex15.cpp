// Chapter 22, exercise 15: write a program that, given a file of (name,year)
// pairs such as (Algol,1960) graphs the names on a timeline

#include "chapter22_Simple_window.h"
#include<map>

using namespace Graph_lib;
//------------------------------------------------------------------------------

istream& operator>>(istream& is, pair<string,int>& psi)
{
    char ch1;
    char ch2;
    char ch3;
    string s;
    int i;
    is >> ch1;
    if (!is) {
        is.clear(ios_base::failbit);
        return is;
    }
    if (ch1!='(') error("expected '('");
    while (is.get(ch2) && ch2!=',')
        s.push_back(ch2);
    is >> i;
    if (!is) error("problem reading integer");
    is >> ch3;
    if (ch3!=')') error("expected ')'");
    psi = pair<string,int>(s,i);
    return is;
}

//------------------------------------------------------------------------------

map<string,int> read_file(const string& fname)
{
    ifstream ifs(fname);
    if (!ifs) error("can't open ",fname);
    pair<string,int> psi;
    map<string,int> msi;
    while (ifs >> psi)
        msi.insert(psi);
    return msi;
}

//------------------------------------------------------------------------------

// find smallest and largest value in msi
pair<int,int> get_extrema(const map<string,int>& msi)
{
    if (msi.size()==0) return make_pair(0,0);
    int min = msi.begin()->second;
    int max = min;
    typedef map<string,int>::const_iterator Iter;
    for (Iter p = msi.begin(); p!=msi.end(); ++p) {
        if (p->second < min) min = p->second;
        if (p->second > max) max = p->second;
    }
    return make_pair(min,max);
}

//------------------------------------------------------------------------------

string get_label(int min, int max, double nticks)
{
    double dt = (max-min)/nticks;
    ostringstream oss;
    for (int i = 0; i<=nticks; ++i)
        oss << left << setw(320/nticks) << int(min+i*dt);
    return oss.str();
}

//------------------------------------------------------------------------------

int get_x_coord(int min, int max, int xmax, int xoffset, int year)
{
    double ratio = (year-min)/double(max-min);
    return xoffset + ratio*(xmax-2*xoffset);
}

//------------------------------------------------------------------------------

double shape_distance(const Shape& s1, const Shape& s2)
{
    double x1 = s1.point(0).x;
    double y1 = s1.point(0).y;
    double x2 = s2.point(0).x;
    double y2 = s2.point(0).y;
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

//------------------------------------------------------------------------------

void adjust_y(Shape& s1, const Vector_ref<Shape>& shapes)
{
    if (shapes.size()==0) return;
    double min_dist = 0;
    vector<double> distances(shapes.size());
    bool loop = true;
    while (loop) {
        for (int i = 0; i<shapes.size(); ++i)
            distances[i] = shape_distance(s1,shapes[i]);
        min_dist = *min_element(distances.begin(),distances.end());
        if (min_dist < 50)
            s1.move(0,-51);
        else
            loop = false;
    }
}

//------------------------------------------------------------------------------

int main()
try {
    // constants for window
    const int xmax = 1500;
    const int ymax = 800;
    const int xoffset = 50;
    const int yoffset = 50;
    const int xlength = xmax - 2*xoffset;
    const int nticks = 5;

    const string fname = "pics_and_txt/chapter22_ex15_in.txt";
    map<string,int> graph_data = read_file(fname);

    // determine year of oldest and newest language for graph label
    pair<int,int> min_max = get_extrema(graph_data); 

    // get axis labels
    string xlabel = get_label(min_max.first,min_max.second,nticks);

    // create window
    Simple_window win(Point(50,50),xmax,ymax,
        "Timeline of programming languages");

    // add axis with labels and ticks corresponding to findings above
    Axis t_axis(Axis::x,Point(xoffset,ymax-yoffset),xlength,nticks,xlabel);
    t_axis.label.move(-xmax/3.5,0);
    win.attach(t_axis);

    Vector_ref<Shape> labels;
    typedef map<string,int>::const_iterator Iter;
    for (Iter p = graph_data.begin(); p!=graph_data.end(); ++p) {
        int x = get_x_coord(min_max.first,min_max.second,xmax,xoffset,p->second);
        Text* label = new Text(Point(x,ymax-2*yoffset),p->first);
        adjust_y(*label,labels);
        labels.push_back(label);
        win.attach(labels[labels.size()-1]);
    }

    // add languages
    win.wait_for_button();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}