// Chapter 13, exercise 07: make an RGB color chart

#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"RGB chart");
    Vector_ref<Graph_lib::Rectangle> rects;

    for (int i1 = 0; i1<4; ++i1) {
        for (int i2 = 0; i2<4; ++i2) {
            for (int j = 0; j<16; ++j) {
                for (int k = 0; k<16; ++k) {
                    rects.push_back(new Graph_lib::Rectangle(Point(16*12*i1+12*k,16*12*i2+12*j),12,12));
                    rects[rects.size()-1].set_fill_color(fl_rgb_color(15*(4*i1+i2),15*j,15*k));
                    rects[rects.size()-1].set_color(Color(Color::black,Color::invisible));
                    win.attach(rects[rects.size()-1]);
                }
            }
        }
    }
    win.wait_for_button();

    for (int i = 0; i<rects.size(); ++i)
        win.detach(rects[i]);

    const int box_h = 22;
    const int box_w = 88;
    Vector_ref<Graph_lib::Rectangle> boxes;
    Vector_ref<Text> labels;

    for (int i = 0; i<6; ++i) {
        for (int j = 0; j<6; ++j) {
            for (int k = 0; k<6; ++k) {
                boxes.push_back(new Graph_lib::Rectangle(Point(k*box_w,i*6*box_h+j*box_h),box_w,box_h));
                boxes[boxes.size()-1].set_fill_color(fl_rgb_color(51*i,51*j,51*k));
                boxes[boxes.size()-1].set_color(Color(Color::black,Color::invisible));
                win.attach(boxes[boxes.size()-1]);
                ostringstream oss;
                oss << hex << uppercase << setfill('0') << left <<
                    setw(2) << 51*i << setw(2) << 51*j << setw(2) << 51*k;
                labels.push_back(new Text(Point(k*box_w+20,i*6*box_h+j*box_h+16),oss.str().c_str()));
                if (j<=2) labels[labels.size()-1].set_color(Color::white);
                win.attach(labels[labels.size()-1]);
            }
        }
    }
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
