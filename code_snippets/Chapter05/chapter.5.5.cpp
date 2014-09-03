
//
// This is example code from Chapter 5.5 "Run-time errors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int area(int length, int width)         // calculate area of a rectangle
{
    return length*width;
}

//------------------------------------------------------------------------------

int framed_area(int x, int y)           // calculate area within frame
{
    return area(x-2,y-2);
}

//------------------------------------------------------------------------------

int main()
{
    int x = -1;
    int y = 2;
    int z = 4;
    // ...
    int area1 = area(x,y);
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3; // convert to double to get
    // floating-point division
}

//------------------------------------------------------------------------------
