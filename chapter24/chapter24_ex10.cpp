// Chapter 24, exercise 10: test rand(); write a program that takes two integers
// n and d and calls randint(n) d times; output the number of draws for each
// [0:n) and see if there are any obvious biases

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<map>

using namespace std;

inline int randint(int max) { return rand()%max; }

inline int randint(int min, int max) { return randint(max-min)+min; }

int main()
try
{
    while (true) {
        cout << "Enter biggest number: ";
        int n;
        cin >> n;
        cout << "Enter number of draws (0 to exit): ";
        int d;
        cin >> d;
        if (d==0) break;
        srand(time(0));

        int r = 0;
        map<int,int> histo;
        for (int i = 0; i<d; ++i)
            ++histo[randint(n)];

        for (int i= 0; i<n; ++i) {
            cout << setw(2) << i << ": ";
            for (int j = 0; j<histo[i]; ++j)
                cout << '*';
            cout << '\n';
        }
    }
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
