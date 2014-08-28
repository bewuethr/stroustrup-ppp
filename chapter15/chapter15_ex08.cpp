// Chapter 15, exercise 08: graph data from file
// Use pics_and_txt/chapter15_ex08_in.txt

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
    int height;
    int n;
    vector<double> n_people;
    string xlabel = "height [cm]     ";
    while (ifs>>height>>n) {
        n_people.push_back(n);
        xlabel += (to_string(height) + "          ");
    }

    const int xmax = 600;
    const int ymax = 600;

    const int x_orig = 100;
    const int y_orig = ymax - 100;
    const Point orig(x_orig,y_orig);

    const int r_min = 0;
    const int r_max = 6;


    Point tl(600,50);
    Simple_window win(tl,xmax,ymax,"Height of people");

    const int xlength = xmax - 200;
    const int ylength = ymax - 200;

    const int x_scale = ylength/6;
    const int y_scale = 10;
    Axis x(Axis::x,Point(x_orig,y_orig),xlength,xlength/x_scale,xlabel);
    x.label.move(-108,0);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig,y_orig),ylength,ylength/y_scale,"number of people");
    win.attach(y);

    Bar_chart bc(orig,y_scale,20,x_scale-20);
    for (int i = 0; i<n_people.size(); ++i) {
        bc.add_val(n_people[i]);
        bc.set_label(i,to_string(int(n_people[i])));
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
