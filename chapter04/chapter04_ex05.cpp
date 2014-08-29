// Chapter 04, exercise 05: simple calculator for four basic math operations

#include "../lib_files/std_lib_facilities.h"

int main()
{
    cout << "Enter two double values and character (+, -, * or /)\n";
    double val1 = 0;
    double val2 = 0;
    char op = ' ';
    while (cin>>val1>>val2>>op) {
        switch (op) {
        case '+':
            cout << "The sum of " << val1 << " and " << val2 << " is " << val1+val2 << ".\n";
            break;
        case '-':
            cout << "The difference of " << val1 << " and " << val2 << " is " << val1-val2 << ".\n";
            break;
        case '*':
            cout << "The product of " << val1 << " and " << val2 << " is " << val1*val2 << ".\n";
            break;
        case '/':
            cout << "The ratio of " << val1 << " and " << val2 << " is " << val1/val2 << ".\n";
            break;
        default:
            cout << "This is not a valid operation (use +, -, * or /)\n";
            break;
        }
    }
}
