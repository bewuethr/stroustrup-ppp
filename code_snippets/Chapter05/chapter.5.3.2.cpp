
//
// This is example code from Chapter 5.3.2 "Type errors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int area(int length, int width);    // calculate area of a rectangle

//------------------------------------------------------------------------------

int main()
{
    //int x0 = arena(7);        // error: undeclared function
    //int x1 = area(7);           // error: wrong number of arguments
    //int x2 = area("seven",2);    // error: 1st argument has a wrong type
    return area(4,4);
}

//------------------------------------------------------------------------------

int area(int length, int width)
{
    return length*width;
}

//------------------------------------------------------------------------------
