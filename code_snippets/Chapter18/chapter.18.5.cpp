
//
// This is example code from Chapter 18.5 "Arrays" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

const int max = 100;
int gai[max];            // a global array (of 100 ints); "lives forever"

int f(int n)
{
    char lac[20];        // local array - "lives" until the end of scope
    int lai[60];
    //double lad[n];       // error: array size not a constant
    // ...
    return 0;
}

//------------------------------------------------------------------------------

int f2(int n)
{
    char lac[20];        // local array - "lives" until the end of scope

    lac[7] = 'a';
    *lac = 'b';          // equivalent to lac[0]='b'

    lac[-2] = 'b';       // huh?
    lac[200] = 'c';      // huh?
    return 0;
}

//------------------------------------------------------------------------------

int main()
{
    f(10);
    f2(10);
}

//------------------------------------------------------------------------------
