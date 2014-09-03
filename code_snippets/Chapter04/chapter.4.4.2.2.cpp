
//
// This is example code from Chapter 4.4.2.2 "Blocks" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

int main()
{
    int a = 7;
    int b = 4;

    if (a<=b) { // do nothing
    }
    else {      // swap a and b
        int t = a;
        a = b;
        b = t;
    }
}

//------------------------------------------------------------------------------
