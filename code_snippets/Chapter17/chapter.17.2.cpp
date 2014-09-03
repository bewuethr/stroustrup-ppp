
//
// This is example code from Chapter 17.2 "Vector basics" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <vector>

//------------------------------------------------------------------------------

int main()
{
    using std::vector;        // Use STL vector for this example.
    vector<double> age(4);    // a vector with 4 elements of type double
    age[0]=0.33;
    age[1]=22.0;
    age[2]=27.2;
    age[3]=54.2;
}

//------------------------------------------------------------------------------

// a very simplified vector of doubles (like vector<double>):
class vector {
    int sz;                   // the size
    double* elem;             // pointer to the first element (of type double)
public:
    vector(int s);            // constructor: allocate s doubles,
                              // let elem point to them
                              // store s in sz
    int size() const { return sz; } // the current size
};

//------------------------------------------------------------------------------
