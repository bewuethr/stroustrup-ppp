// Chapter 04, exercise 18: solve quadratic equations

#include "../lib_files/std_lib_facilities.h"

int main()
{
    cout << "Enter coefficients a, b and c of ax^2 + bx + c = 0:\n";
    double a = 0;
    double b = 0;
    double c = 0;
    while (cin>>a>>b>>c) {
        // Calculate discriminant
        double delta = b*b - 4*a*c;
        if (delta<0)
            cout << "Sorry, no complex math here - can't solve that! Try again:\n";
        else if (delta==0) {
            double x = -b / (2*a);
            cout << "Just one solution: x = " << x << endl;
        }
        else {
            double x1 = (-b + sqrt(delta)) / (2*a);
            double x2 = (-b - sqrt(delta)) / (2*a);
            cout << "Two solutions: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    }
}
