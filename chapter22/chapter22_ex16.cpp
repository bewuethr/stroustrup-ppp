// Chapter 22, exercise 16: modify the program from exercise 15 so it reads a
// file with (name,year,(ancestors)) tuples such as (C++,1985,(C,Simula)) and
// graph them on a timeline with arrows from ancestors to descendants

#include "chapter22_Simple_window.h"
#include<map>

using namespace Graph_lib;

struct Lang_data {
    Lang_data() :year(0), ancestors() { }
    Lang_data(int y, vector<string> a) :year(y), ancestors(a) { }
    int year;
    vector<string> ancestors;
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, pair<string,Lang_data>& psld)
{
    char ch1;
    char ch2;
    char ch3;
    char ch4;
    char ch5;
    char ch6;
    string name;
    int year;
    is >> ch1;
    if (!is) {
        is.clear(ios_base::failbit);
        return is;
    }
    if (ch1!='(') error("expected '('");
    while (is.get(ch2) && ch2!=',')
        name.push_back(ch2);
    is >> year;
    if (!is) error("problem reading integer");
    is >> ch3;
    if (ch3!=',') error("expected ','");
    is >> ch4;
    if (ch4!='(') error("expected '('");
    bool loop = true;
    vector<string> ancestors;
    while (loop) {
        string anc_name;
        while (is.get(ch5) && ch5!=',' && ch5!=')')
            anc_name.push_back(ch5);
        ancestors.push_back(anc_name);
        switch (ch5) {
        case ')':
            loop = false;
            break;
        case ',':
            break;
        default:
            error("expected ',' or ')'");
        }
    }
    is >> ch6;
    if (ch6!=')') error("expected ')'");
    Lang_data ld(year,ancestors);
    psld = pair<string,Lang_data>(name,ld);
    return is;
}

//------------------------------------------------------------------------------

map<string,Lang_data> read_file(const string& fname)
{
    ifstream ifs(fname);
    if (!ifs) error("can't open ",fname);
    pair<string,Lang_data> psld;
    map<string,Lang_data> msld;
    while (ifs >> psld)
        msld.insert(psld);
    return msld;
}

//------------------------------------------------------------------------------

// find smallest and largest value in msld
pair<int,int> get_extrema(const map<string,Lang_data>& msld)
{
    if (msld.size()==0) return make_pair(0,0);
    int min = msld.begin()->second.year;
    int max = min;
    typedef map<string,Lang_data>::const_iterator Iter;
    for (Iter p = msld.begin(); p!=msld.end(); ++p) {
        if (p->second.year < min) min = p->second.year;
        if (p->second.year > max) max = p->second.year;
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

double ell_distance(const Graph_lib::Ellipse& e1, const Graph_lib::Ellipse& e2)
{
    double x1 = e1.center().x;
    double y1 = e1.center().y;
    double x2 = e2.center().x;
    double y2 = e2.center().y;
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

//------------------------------------------------------------------------------

void adjust_y(Graph_lib::Ellipse& e1, const Vector_ref<Text_ellipse>& shapes)
{
    if (shapes.size()==0) return;
    double min_dist = 0;
    vector<double> distances(shapes.size());
    bool loop = true;
    while (loop) {
        for (int i = 0; i<shapes.size(); ++i)
            distances[i] = ell_distance(e1,shapes[i]);
        min_dist = *min_element(distances.begin(),distances.end());
        if (min_dist < 100)
            e1.move(0,-100);
        else
            loop = false;
    }
}

//------------------------------------------------------------------------------

void set_arrows(Simple_window& win,
    const map<string,Lang_data>& graph_data,
    const Vector_ref<Text_ellipse>& labels,
    Vector_ref<Arrow>& arrows)
{
    // for each element in graph_data
        // for each element of ancestors
            // draw an arrow from e(ancestor label) to w(element label)
    typedef map<string,Lang_data>::const_iterator Iter;
    for (Iter p = graph_data.begin(); p!=graph_data.end(); ++p) {
        for (int i = 0; i<p->second.ancestors.size(); ++i) {
            Point p0;
            Point p1;
            for (int j = 0; j<labels.size(); ++j) { // find labels
                if (labels[j].get_label() == p->second.ancestors[i])
                    p0 = e(labels[j]);
                if (labels[j].get_label() == p->first)
                    p1 = w(labels[j]);
                if (p0!=Point(0,0) && p1!=Point(0,0))
                    break;
            }
            if (p0!=Point(0,0) && p1!=Point(0,0)) {
                arrows.push_back(new Arrow(p0,p1));
                win.attach(arrows[arrows.size()-1]);
            }
        }
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

    const string fname = "pics_and_txt/chapter22_ex16_in.txt";
    map<string,Lang_data> graph_data = read_file(fname);

    // determine year of oldest and newest language for graph label
    pair<int,int> min_max = get_extrema(graph_data); 

    // get axis labels
    string xlabel = get_label(min_max.first,min_max.second,nticks);

    // create window
    Simple_window win(Point(50,50),xmax,ymax,
        "Timeline and ancestor relationships of programming languages");

    // add axis with labels and ticks corresponding to findings above
    Axis t_axis(Axis::x,Point(xoffset,ymax-yoffset),xlength,nticks,xlabel);
    t_axis.label.move(-xmax/3.5,0);
    win.attach(t_axis);

    Vector_ref<Graph_lib::Text_ellipse> labels;
    typedef map<string,Lang_data>::const_iterator Iter;
    for (Iter p = graph_data.begin(); p!=graph_data.end(); ++p) {
        int x = get_x_coord(min_max.first,min_max.second,xmax,xoffset,p->second.year);
        Text_ellipse* label = new Text_ellipse(Point(x,ymax-2*yoffset),p->first);
        adjust_y(*label,labels);
        labels.push_back(label);
        win.attach(labels[labels.size()-1]);
    }

    Vector_ref<Arrow> arrows;
    set_arrows(win,graph_data,labels,arrows);

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