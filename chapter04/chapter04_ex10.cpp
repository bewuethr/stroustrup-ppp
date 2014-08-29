// Chapter 04, exercise 10: play "Rock, paper, scissors" against the user

#include "../lib_files/std_lib_facilities.h"

int main()
{
    // set computer moves
    cout << "How many different moves (at least one) should the computer have?\n";
    int num_moves = 0;
    cin >> num_moves;
    if (num_moves<1)
        simple_error("Number of moves must be at least 1");
    vector<char> comp_moves;
    cout << "Enter the computer moves as 'r', 'p' or 's'\n";
    for (int i = 0; i<num_moves; ++i) {
        char next_move = 0;
        cin >> next_move;
        if (next_move=='r' || next_move=='p' || next_move=='s')
            comp_moves.push_back(next_move);
        else {
            cout << "Invalid move, use 'r', 'p' or 's'\n";
            --i;
        }
    }

    // play game
    cout << "***Starting game***\n";
    cout << "Enter r, p or s to play, q to quit\n";
    char player_move = 0;
    int comp_move = 0;
    int p_score = 0;
    int c_score = 0;
    int ties = 0;
    while (true) {
        cin >> player_move;
        cout << "Player: " << player_move << " Computer: " << comp_moves[comp_move] << endl;
        switch (player_move) {
        case 'r':
            switch (comp_moves[comp_move]) {
            case 'r':
                ++ties;
                cout << "Tie!\n";
                break;
            case 'p':
                ++c_score;
                cout << "I win!\n";
                break;
            case 's':
                ++p_score;
                cout << "You win!\n";
                break;
            }
            break;
        case 'p':
            switch (comp_moves[comp_move]) {
            case 'r':
                ++p_score;
                cout << "You win!\n";
                break;
            case 'p':
                ++ties;
                cout << "Tie!\n";
                break;
            case 's':
                ++c_score;
                cout << "I win!\n";
                break;
            }
            break;
        case 's':
            switch (comp_moves[comp_move]) {
            case 'r':
                ++c_score;
                cout << "I win!\n";
                break;
            case 'p':
                ++p_score;
                cout << "You win!\n";
                break;
            case 's':
                ++ties;
                cout << "Tie!\n";
                break;
            }
            break;
        case 'q':
            return 0;
        default:
            cout << "Invalid move, use 'r', 'p' or 's'\n";
            break;
        }
        cout << "Score: Player " << p_score << " Computer " << c_score << " Ties " << ties << endl;
        ++comp_move;
        // check if computer moves have to wrap around
        if (comp_move==comp_moves.size())
            comp_move = 0;
    }
    return 0;
}
