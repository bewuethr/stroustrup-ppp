// Chapter 04, exercise 04: guess a number from 1 to 100 in no more than 7 tries

#include "../lib_files/std_lib_facilities.h"
int main()
{
    cout << "Think of a number between 1 and 100.\n";
    cout << "For every guess, enter if your number is\n";
    cout << "(l)arger or (s)maller than the one shown.\n";
    cout << "Enter 'c' (for 'correct') if the number shown is yours.\n";

    int guess = 50;
    vector<int> differences(6);
    differences[0] = 25;
    differences[1] = 13;
    differences[2] = 6;
    differences[3] = 3;
    differences[4] = 2;
    differences[5] = 1;
    int counter = 0;
    char answer = ' ';

    while (answer != 'c') {
        cout << "My guess: " << guess << endl;
        ++counter;
        cout << "Correct, larger or smaller (c, l, s)? ";
        cin >> answer;
        switch (answer) {
        case 'c':
            // do nothing, simply fall out of the loop
            break;
        case 'l':
            // increase by next difference or one
            if (counter<=differences.size())
                guess += differences[counter-1];
            else
                ++guess;
            break;
        case 's':
            // decrease by next difference
            if (counter<=differences.size())
                guess -= differences[counter-1];
            else
                --guess;
            break;
        default:
            // invalid answer, reduce counter because guess does not count
            cout << "This is not a valid answer, use 'c', 'l' or 's'\n";
            --counter;
            break;
        }
        if (guess>100 || guess<1) {
            cout << "Your number must be between 1 and 100!\n";
            return 0;
        }
        if (counter==7 && answer!='c')
        {
            cout << "Super fishy, dude. I should have your number by now.\n";
            return 0;
        }
    }

    string s_try;
    if (counter==1)
        s_try = " try ";
    else
        s_try = " tries ";
    cout << "It took me " << counter << s_try << "to find your number, " << guess << ".\n";
}
