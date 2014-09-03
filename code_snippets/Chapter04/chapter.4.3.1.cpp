
//
// This is example code from Chapter 4.3.1 "Constant expressions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int main()
{
    const double pi = 3.14159265359;
    //pi = 7;           // error: assignment to const
    int r = 7;
    int v = 2*pi/r;     // ok: we just read pi; we don't try to change it
    const int max = 17; // a literal is a constant expression
    int val = 19;

    max+2;              // a constant expression (a const int plus a literal)
    val+2;              // not a constant expression: it uses a variable
}

//------------------------------------------------------------------------------
