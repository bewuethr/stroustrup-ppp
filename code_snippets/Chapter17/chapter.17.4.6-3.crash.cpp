
//
// This is example code from Chapter 17.4.6 "Free store deallocation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int main()
{
    // Deleting an object twice is a bad mistake. For example:

    int* p = new int(5);
    delete p;    // fine: p points to an object created by new
    // ... no use of p here ...
    delete p;    // error: p points to memory owned by the free store manager

    {
        int* p = 0;
        delete p;    // fine: no action needed
        delete p;    // also fine (still no action needed)
    }
}

//------------------------------------------------------------------------------
