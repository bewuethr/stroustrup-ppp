// Chapter 25, exercise 5: write an infinite loop and execute it

#include<iostream>
#include<exception>

using namespace std;

int main()
try
{
    while (true)
        cout << "Looping!\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
    return 2;
}
