// Chapter 05, exercise 07: solve quadratic equations

#include "../lib_files/std_lib_facilities.h"

double a,b,c;
bool do_check;

// checks if x is close to the solution
// warns if solution is poor
// if do_check is false, simply returns x
double found(double x)
{
    if (!do_check)
        return x;
    else {
        const double epsilon = 1e-7;
        double e = a*x*x + b*x + c;
        if (e == 0) return x;
        if (0<e && epsilon<e)
            cout << "poor root; off by " << e << endl;
        else if (e < -epsilon)
            cout << "poor root; off by " << e << endl;
        return x;
    }
}

// solves quadratic equation
void quad_solver()
{
    while (cin>>a>>b>>c){
        if (a == 0) {
            if (b == 0)
                cout << "no root (x isn't used)\n";
            else
                cout << "x = " << found(-c/b) << endl;
        }
        else if (b == 0) {
            double ca = -c/a;
            if (ca == 0)
                cout << "x = 0\n";
            else if (ca < 0)
                cout << "no real roots\n";
            else
                cout << "two real roots: x = " << found(sqrt(ca)) << " and " << found(-sqrt(ca)) << endl;
        }
        else {
            double delta = b*b - 4*a*c;
            if (delta == 0)
                cout << "one real root: " << found(-b/(2*a)) << endl;
            else if (delta < 0)
                cout << "no real roots\n";
            else
                cout << "two real roots: " << found((-b + sqrt(delta))/(2*a)) << " and " << found((-b - sqrt(delta))/(2*a)) << endl;
        }
        cout << "try again: ";
    }
}

int main()
try {
    cout << "Should your solutions be checked?\n";
    char check = 0;
    cin >> check;
    if (check == 'y' || check == 'Y')
        do_check = true;
    else if (check == 'n' || check == 'N')
        do_check = false;
    else
        error("answer not recognised (try 'y' or 'n')");
    cout << "Enter coefficients for quadratic equation a*x^2 + b*x + c = 0\n";
    quad_solver();
    return 0;
}
catch (exception& e) {
    cerr << "Error: " << e.what() << endl;
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Unknown exception!\n";
    return 2;
}
