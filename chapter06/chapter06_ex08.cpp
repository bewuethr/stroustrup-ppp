// Chapter 06, exercise 08: redo the Cows and Bulls game from exercise 12 in
// Chapter 5, but with letters instead of digits

#include "../lib_files/std_lib_facilities.h"

vector<char> solution(4);

// set four random letters to solution vector
void init_solution()
{
    solution[0] = 'a';
    solution[1] = 'b';
    solution[2] = 'c';
    solution[3] = 'd';
}

// check if given vector is solution vector
// print out number of cows and bulls
bool is_solution(vector<char> v)
{
    vector<int> is_used(4,0);
    int bulls = 0;
    int cows = 0;

    // check for and mark bulls
    for (int i = 0; i<solution.size(); ++i) {
        if (v[i] == solution[i]) {
            ++bulls;
            is_used[i] = 1;
        }
    }

    // check for cows
    for (int i = 0; i<solution.size(); ++i) {
        for (int j = 0; j<v.size(); ++j) {
            if (solution[i]==v[j] && is_used[j]==0) {
                ++cows;
                is_used[j] = 1;
            }
        }
    }

    // print result
    cout << "Number of cows: " << cows << endl;
    cout << "Number of bulls: " << bulls << endl;
    if (bulls == 4) return true;
    return false;
}

int main()
try {
    char c0 = 0;
    char c1 = 0;
    char c2 = 0;
    char c3 = 0;
    vector<char> guess(4);

    init_solution();

    cout << "Enter your guess:\n";
    while (cin>>c0>>c1>>c2>>c3) {
        guess[0] = c0;
        guess[1] = c1;
        guess[2] = c2;
        guess[3] = c3;

        bool b = is_solution(guess);
        if (b) {
            cout << "You found the solution!\n";
            break;
        }
    }
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
