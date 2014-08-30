// Chapter 18, exercise 12: implement "Hunt the Wumpus"

#include "wumpus.h"

using namespace Wumpus;

// main game loop
void wumpus_loop() {
    while (true) {
        // init cave
        Cave c;

        while (true) {
            cout << "\n";

            c.hazard_warnings();
            c.room_description();

            // shoot or move?
            char ch;
            cout << "Shoot or move (S-M)?\n";
            while (cin>>ch && !(ch=='m' || ch=='s')) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Shoot or move (S-M)?\n";
            }
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            if (ch=='m') {
                // get label of room to move to, move player
                while (true) {
                    cout << "Where to?\n";
                    int lbl = get_int();
                    if (c.move_player(lbl)) break;
                }

                // check for Wumpus
                if (c.get_player_loc() == c.get_wumpus_loc()) {
                    cout << "...oops! Bumped a Wumpus!\n";
                    c.wake_wumpus();
                    if (c.get_player_loc() == c.get_wumpus_loc()) {
                        cout << "Tsk tsk tsk - Wumpus got you!\n";
                        cout << "Ha ha ha - you lose!\n";
                        break;
                    }
                }

                // check for bat
                while (c.get_player_loc()->has_bat) {
                    cout << "Zap - super bat snatch! Elsewhereville for you!\n";
                    c.bat_flight();
                }

                // check for pit
                if (c.get_player_loc()->has_pit) {
                    cout << "Yyyiiiieeee... fell in pit!\n"
                        << "Ha ha ha - you lose!\n";
                    break;
                }
            }
            else {
                Game_state gs = c.shoot_arrow();
                switch (gs) {
                case plr_shot:
                    cout << "Ouch! Arrow got you!\n"
                        << "Ha ha ha - you lose!\n";
                    break;
                case no_arrows:
                    cout << "You have run out of arrows!\n"
                        << "Ha ha ha - you lose!\n";
                    break;
                case wmp_dead:
                    cout << "Aha! You got the Wumpus!\n"
                        << "Hee hee hee - the Wumpus'll getcha next time!\n";
                    break;
                default:    // everybody is alive, wake up Wumpus
                    c.wake_wumpus();
                    break;
                }
                if (gs!=running) break;
            }

            // check if at end of round Wumpus is in the same room
            if (c.get_player_loc() == c.get_wumpus_loc()) {
                cout << "Tsk tsk tsk - Wumpus got you!\n";
                cout << "Ha ha ha - you lose!\n";
                break;
            }
        }
        cout << "Play again?\n";
        char ch;
        cin >> ch;
        if (ch!='y') break;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
}

int main()
try {
    cout << "Instructions (Y-N)?\n";
    char ch;
    cin >> ch;
    if (ch!='n') print_instructions();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    wumpus_loop();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
