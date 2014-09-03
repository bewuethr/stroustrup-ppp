
//
// This is example code from Chapter 26.3.3.4 "Branching" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

void do_branch1(int x, int y) // messy function
// undisciplined use of if
{
    if (x<0) {
        if (y<0)
            cout << "very negative\n";
        else
            cout << "somewhat negative\n";
    }
    else if (x>0) {
        if (y<0)
            cout << "very positive\n";
        else
            cout << "somewhat positive\n";
    }
}

//------------------------------------------------------------------------------

int main()
{
    do_branch1(-1,-1);
    do_branch1(-1, 1);
    do_branch1(1,-1);
    do_branch1(1,1);
    do_branch1(-1,0); 
    do_branch1(0,-1);
    do_branch1(1,0);
    do_branch1(0,1);
    do_branch1(0,0);
}

//------------------------------------------------------------------------------

void do_branch2(int x, int y) // messy function
// undisciplined use of switch
{
    if (y<0 && y<=3)
        switch (x) {
        case 1:
            cout << "one\n"; 
            break;
        case 2:
            cout << "two\n";
        case 3:
            cout << "three\n";
    }
}

//------------------------------------------------------------------------------
