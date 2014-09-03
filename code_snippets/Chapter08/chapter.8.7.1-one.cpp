
//
// This is example code from Chapter 8.7.1 "Using declarations and using directives" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include<string>        // get the string library
#include<iostream>      // get the iostream library

//------------------------------------------------------------------------------

int main()
{
    std::string name;
    std::cout << "Please enter your first name\n";
    std::cin >> name;
    std::cout << "Hello, " << name << '\n';
}

//------------------------------------------------------------------------------
