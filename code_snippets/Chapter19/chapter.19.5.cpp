
//
// This is example code from Chapter 19.5 "Resources and exceptions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

void suspicious(int s, int x)
{
    int* p = new int[s];  // acquire memory
    // ...
    delete[] p;           // release memory
}

//------------------------------------------------------------------------------

int main()
{
    suspicious(4,42);
}

//------------------------------------------------------------------------------
