
//
// This is example code from Chapter 18.5.2 "Pointers and arrays" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

// The name of an array refers to all the elements of the array. Consider:
char ch[100];
char* p = ch; // Here p is initialized to &ch[0].

//------------------------------------------------------------------------------

int strlen(const char a[])    // similar to the standard-library strlen()
{
    int count = 0;
    while (a[count]) { ++count; }
    return count;
}

//------------------------------------------------------------------------------

char lots [100000];

void f()
{
    int nchar = strlen(lots);
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
