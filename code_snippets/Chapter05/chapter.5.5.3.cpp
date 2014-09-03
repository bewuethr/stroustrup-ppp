
//
// This is example code from Chapter 5.5.3 "Error reporting" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// ask user for a yes-or-no answer;
// return 'b' to indicate a bad answer (i.e., not yes or no)
char ask_user(string question)
{
    cout << question << "? (yes or no)\n";
    string answer = " ";
    cin >> answer;
    if (answer =="y" || answer=="yes") return 'y'; 
    if (answer =="n" || answer=="no") return 'n';
    return 'b';    // 'b' for "bad answer"
}

//------------------------------------------------------------------------------


int area(int length, int width);    // calculate area of a rectangle

int framed_area(int x, int y)       // calculate area within frame
{ 
    const int frame_width = 2;
    if (x-frame_width<=0 || y-frame_width<=0)
        error("non-positive argument for area() called by framed_area()");
    return area(x-frame_width,y-frame_width);
}

//------------------------------------------------------------------------------

// calculate area of a rectangle;
// return -1 to indicate a bad argument
int area(int length, int width)
{
    if (length<=0 || width <=0) return -1;
    return length*width;
}

//------------------------------------------------------------------------------

int f(int x, int y, int z)
{
    cout << "x=" << x << "; y=" << y << "; z=" << z << endl;

    int area1 = area(x,y);
    if (area1<=0) error("non-positive area");
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3;
    // ...

    cout << "area1=" << area1 << endl
         << "area2=" << area2 << endl
         << "area3=" << area3 << endl;
}

//------------------------------------------------------------------------------

int main()
try
{
    f( 1, 2, 3);
    f(-1, 2, 3);
    f( 1,-2, 3);
    f(-1,-2, 3);
    f( 1, 2,-3);
    f(-1, 2,-3);
    f( 1,-2,-3);
    f(-1,-2,-3);
    char answer = ask_user("Have you read results?");
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
