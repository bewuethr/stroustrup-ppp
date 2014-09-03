
//
// This is example code from Chapter 18.2.3 "Copy terminology" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int main()
{
    // Here is an example of shallow copy:
    {
        int* p = new int(77);
        int* q = p;           // copy the pointer p
        *p = 88;              // change the value of the int pointed to by p and q
    }

    //To contrast, we can do a deep copy:
    {
        int* p = new int(77);
        int* q = new int(*p); // allocate a new int; then copy the value pointed to by p
        *p = 88;              // change the value of the int pointed to by p
    }
}

//------------------------------------------------------------------------------
