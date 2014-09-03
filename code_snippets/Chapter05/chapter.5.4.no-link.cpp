
//
// This is example code from Chapter 5.4 "Link-time errors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int area(int length, int width);    // calculate area of a rectangle

//------------------------------------------------------------------------------

int main()
{
    int x = area(2,3);
}

//------------------------------------------------------------------------------

//int area(int x, int y) { return x*y; } // "our" area()

// Functions with the same name, but different types will not match and will be ignored:

double area(double x, double y) { return x*y; }    // not "our" area()

int area(int x, int y, char unit) { return x*y; }  // not "our" area()

//------------------------------------------------------------------------------
