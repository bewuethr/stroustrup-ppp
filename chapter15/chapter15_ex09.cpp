// Chapter 15, exercise09: graph data from another file
// Use pics_and_txt/chapter15_ex09_in.txt

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // read in data
    string ifname;
    cout << "Enter input file name: ";
    cin >> ifname;
    ifstream ifs(ifname.c_str());
    if (!ifs) error("can't open input file ",ifname);
    string height;
    double pct;
    vector<double> pctage;
    string xlabel = "height     ";
    while (ifs>>height>>pct) {
        pctage.push_back(pct);
        xlabel += (height + "        ");
    }

    const int xmax = 600;
    const int ymax = 600;

    const int x_orig = 100;
    const int y_orig = ymax - 100;
    const Point orig(x_orig,y_orig);

    const int r_min = 0;
    const int r_max = pctage.size();;


    Point tl(600,50);
    Simple_window win(tl,xmax,ymax,"Height of people");

    const int xlength = xmax - 200;
    const int ylength = ymax - 200;

    const int x_scale = ylength/r_max;
    const int y_scale = 10;
    Axis x(Axis::x,Point(x_orig,y_orig),xlength,xlength/x_scale,xlabel);
    x.label.move(-80,0);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig,y_orig),ylength,ylength/y_scale,"% of people");
    win.attach(y);

    Bar_chart bc(orig,y_scale,20,x_scale-20);
    for (int i = 0; i<pctage.size(); ++i) {
        bc.add_val(pctage[i]);
        ostringstream oss;
        oss << setprecision(2) << pctage[i];
        bc.set_label(i,oss.str());
    }
    bc.set_fill_color(Color::red);
    win.attach(bc);

    win.wait_for_button();


}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
