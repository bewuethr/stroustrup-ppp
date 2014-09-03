
//
// This is example code from Chapter 19.2.1 "Representation " of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

class vector {
    int sz;       // number of elements
    double* elem; // address of first element
    int space;    // number of elements plus "free space"/"slots"
                  // for new elements ("the current allocation")
public:
    vector();
    // ...
};

//------------------------------------------------------------------------------

vector::vector() :sz(0), elem(0), space(0) { }

int main()
{
    vector v;
}

//------------------------------------------------------------------------------
