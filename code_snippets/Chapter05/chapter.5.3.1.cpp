
//
// This is example code from Chapter 5.3.1 "Syntax errors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int area(int length, int width);    // calculate area of a rectangle

//------------------------------------------------------------------------------

int main()
{
    //int s1 = area(7;        // error: ) missing
    //int s1 = area(7)        // error: ; missing
    //Int s3 = area(7);        // error: Int is not a type
    //int s4 = area('7);        // error: non-terminated character (' missing)
    return area(4,4);
}

//------------------------------------------------------------------------------

int area(int length, int width)
{
    return length*width;
}

//------------------------------------------------------------------------------
