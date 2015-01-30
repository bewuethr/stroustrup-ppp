// Chapter 25, exercise 6: write an infinite loop that is hard to recognize as
// an infinite loop

#include<iostream>
#include<exception>

using namespace std;

int main()
try
{
    for (char ch = 0; ch<250; ++ch)
        cout << int(ch) << '\n';
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
    return 2;
}
