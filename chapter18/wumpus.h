#ifndef WUMPUS_H_INCLUDED
#define WUMPUS_H_INCLUDED

#include "../lib_files/std_lib_facilities.h"

namespace Wumpus {

// to serve as return value from functions that can kill player or Wumpus
enum Game_state {
    plr_shot, no_arrows, wmp_dead, running
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
    Room* get_player_loc();
    Room* get_wumpus_loc();
    bool move_player(int lbl);
    void hazard_warnings();
    void room_description();
    void bat_flight();
    void wake_wumpus();
    Game_state shoot_arrow();
private:
    vector<Room> rooms;
    Player plr;
    Wumpus wmp;
    Room* lbl_to_ptr(int lbl);  // convert label to Room ptr
};

void print_instructions();

// test if route for arrow is valid
bool route_valid(vector<Room*> r);

}   // namespace Wumpus

// helper function to recover from failing to get an int from cin
void skip_to_int();

// read until cin provides an integer
int get_int();

// get integer in given range, prompt with greeting, print sorry if invalid
int get_int(int low, int high, const string& greeting, const string& sorry);

#endif // WUMPUS_H_INCLUDED
