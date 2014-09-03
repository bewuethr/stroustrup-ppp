
//
// This is example code from Chapter 9.2 "Classes and members" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

class X {
public:
    int m;              // data member
    int mf(int v) { int old = m; m=v; return old; } // function member
};

//------------------------------------------------------------------------------

int main()
{
    X var;              // var is a variable of type X
    var.m = 7;          // assign to var's data member m
    int x = var.mf(9);  // call var's member function mf()
    return x;
}

//------------------------------------------------------------------------------
