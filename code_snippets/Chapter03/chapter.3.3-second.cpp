
//
// This is example code from Chapter 3.3 "Input and type" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// read name and age (2nd version)
int main()
{
    cout << "please enter your first_name and age\n";
    string first_name = "???"; // string variable
                               // ("???" means "don't know the name")
    int age = -1;              // integer variable (-1 means "don't know the age") 
    cin >> first_name >> age;  // read a string followed by an integer
    cout << "Hello, " << first_name << " (age " << age << ")\n";    
}

//------------------------------------------------------------------------------
