
//
// This is example code from Chapter 4.3 "Expressions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int main()
{
    // compute area: 
    int length = 20;         // a literal integer (used to initialize a variable)
    int width = 40;
    int area = length*width; // a multiplication

    length = 99;             // assign 99 to length

    {
        int perimeter = (length+width)*2; // add then multiply
    }

    {
        int perimeter = length*2+width*2;
    }

    {
        int perimeter = length+width/2;    // add width*2 to length
    }
}

//------------------------------------------------------------------------------
