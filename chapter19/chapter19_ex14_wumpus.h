#ifndef WUMPUS_H_INCLUDED
#define WUMPUS_H_INCLUDED

#include "../lib_files/std_lib_facilities.h"

namespace Wumpus {;

const string shoot_or_move_str = "Shoot or move (S-M)?";
const string where_str = "Where to?";
const string restart_str = "Play again (Y-N)?";
const string you_loose_str = "Ha ha ha - you lose!\n";
const string you_win_str = "Aha! You got the Wumpus!\nHee hee hee - the Wumpus'll getcha next time!\n";

// influences what happens when the OK button is pushed
enum Game_state {
    restart,        // asking if player wants to restart
    shoot_or_move,  // expecting input for question "Shoor or move?"
    move,           // expecting input for question "Where to?"
    shoot,          // asking for how many rooms to shoot through
    get_room,       // asking for next room number in arrow route
    plr_shot,       // arrow has killed player
    no_arrows,      // player has run out of arrows
    wmp_dead,       // player has killed Wumpus
    running         // player alive, game running
};

// a room in the cave
struct Room {
    Room();
    Room(int n, Room* nxt0, Room* nxt1, Room* nxt2);
    int label;
    vector<Room*> next;
    bool has_pit;
    bool has_bat;
};

// to check if two rooms are connected
bool contains(vector<Room*> v, Room* x);

struct Player {
    Player(Room* n);
    Room* location;
    int n_arrows;
};

struct Wumpus {
    Wumpus(Room* r);
    Room* location;
};

class Cave {
public:
    Cave();
    Room* get_player_loc() const;
    Room* get_wumpus_loc() const;
    const vector<Room>& get_rooms() const { return rooms; }
    int get_n_arrows() const { return plr.n_arrows; }
    bool move_player(int lbl);
    string hazard_warnings() const;
    string room_description() const;
    void bat_flight();
    void wake_wumpus();
    Game_state shoot_arrow(vector<Room*> rte);
    Room* lbl_to_ptr(int lbl);      // convert label to Room ptr
    int lbl_to_idx(int lbl) const;  // convert label to vector index
private:
    vector<Room> rooms;
    Player plr;
    Wumpus wmp;
};

struct Wumpus_engine {
    Wumpus_engine() : gs(shoot_or_move), room_ctr(0) { }

    Game_state gs;
    Cave c;
    int room_ctr;   // number of rooms in the arrow route
    vector<Room*> route;
};

string get_instructions();

}   // namespace Wumpus

#endif // WUMPUS_H_INCLUDED
