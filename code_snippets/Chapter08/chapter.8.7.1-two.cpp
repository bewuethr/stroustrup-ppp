
//
// This is example code from Chapter 8.7.1 "Using declarations and using directives" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include<string>        // get the string library
#include<iostream>      // get the iostream library

//------------------------------------------------------------------------------

using namespace std;    // make names from std directly accessible

int main()
{
    string name;
    cout << "Please enter your first name\n";
    cin >> name;
    cout << "Hello, " << name << '\n';
}

//------------------------------------------------------------------------------
