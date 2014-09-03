
//
// This is example code from Chapter 17.9 "Pointers and references" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int main()
{
    int x = 10;
    int* p = &x;   // you need & to get a pointer
    *p = 7;        // use * to assign to x through p
    int x2 = *p;   // read x through p
    int* p2 = &x2; // get a pointer to another int
    p2 = p;        // p2 and p both point to x
    p = &x2;       // make p point to another object

    // The equivalent example for references is:

    int y = 10;
    int& r = y;    // the & is in the type, not in the initializer
    r = 7;         // assign to y through r (no * needed)
    int y2 = r;    // read y through r (no * needed)
    int& r2 = y2;  // get a reference to another int
    r2 = r;        // the value of y is assigned to y2 
    //r = &y2;       // error: you can't change the value of a reference
                   //      (no assignment of an int* to an int&)
}

//------------------------------------------------------------------------------
