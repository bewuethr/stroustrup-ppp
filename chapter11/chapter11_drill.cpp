// Chapter 11, drill

#include "../lib_files/std_lib_facilities.h"

void int_output()
{
    cout << showbase << "Birth year:" << endl
        << 1980 << "\t(decimal)" << endl
        << hex << 1980 << "\t(hexadecimal)" << endl
        << oct << 1980 << "\t(octal)" << endl;

    cout << dec << endl << "Age:" << endl
        << 33 << "\t(decimal)" << endl
        << hex << 33 << "\t(hexadecimal)" << endl
        << oct << 33 << "\t(octal)" << endl;
}

void int_input()
{
    int a;
    int b;
    int c;
    int d;
    cin >> a >> hex >> b >> oct >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << endl;
}

void float_output()
{
    cout << 1234567.89 << "\t(general)\n"
        << fixed << 1234567.89 << "\t(fixed)\n"
        << scientific << 1234567.89 << "\t(scientific)\n";
}

int main()
{
    cout << setw(10) << "Wuethrich" << " | " << "Benjamin" << " | "
        << setw(16) << "+1345 326 5181" << " | " << setw(29) << "benjamin.wuethrich@gmail.com" << endl
        << setw(10) << "Forrest" << " | " << setw(8) << "Kara" << " | "
        << setw(16) << "+1345 516 1920" << " | " << setw(29) << "kara_forrest@hotmail.com" << endl
        << setw(10) << "Aarnau" << " | " << setw(8) << "Mayra" << " | "
        << "+34 66 696 55 63" << " | " << setw(29) << "mayraaachen@hotmail.com" << endl
        << setw(10) << "Michel" << " | " << setw(8) << "Tanael" << " | "
        << "+41 79 374 48 62" << " | " << setw(29) << "tanael@gmail.com" << endl
        << setw(10) << "Widler" << " | " << setw(8) << "Andrea" << " | "
        << "+41 79 293 29 38" << " | " << setw(29) << "andreawidler@bluewin.ch" << endl
        << "Amanatidou" << " | " << "Elisabet" << " | "
        << "+41 76 701 61 28" << " | " << "elisabet.amanatidou@gmail.com" << endl;
}
