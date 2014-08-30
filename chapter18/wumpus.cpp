#include "wumpus.h"

namespace Wumpus {

// ----------------------------------------------------------------------------

Room::Room() : label(0), has_pit(false), has_bat(false) { }

// ----------------------------------------------------------------------------

Room::Room(int n, Room* nxt0, Room* nxt1, Room* nxt2)
    : label(n), next(3), has_pit(false), has_bat(false)
{
    next[0] = nxt0;
    next[1] = nxt1;
    next[2] = nxt2;
}

// ----------------------------------------------------------------------------

bool contains(vector<Room*> v, Room* x) {
    for (int i = 0; i<v.size(); ++i) {
        if (v[i] == x) return true;
    }
    return false;
}

// ----------------------------------------------------------------------------

Player::Player(Room* n) : location(n), n_arrows(5) { }

// ----------------------------------------------------------------------------

Wumpus::Wumpus(Room* r) : location(r) { }

// ----------------------------------------------------------------------------

Cave::Cave() : rooms(20), plr(0), wmp(0)
{
    srand(time(0));

    // vector of room labels, to randomize later
    vector<int> labels;
    for (int i = 0; i<20; ++i) labels.push_back(i+1);
    random_shuffle(labels.begin(),labels.end());

    // set up tunnel system
    rooms[0] = Room(labels[0],&rooms[1],&rooms[4],&rooms[5]);
    rooms[1] = Room(labels[1],&rooms[0],&rooms[2],&rooms[7]);
    rooms[2] = Room(labels[2],&rooms[1],&rooms[3],&rooms[9]);
    rooms[3] = Room(labels[3],&rooms[2],&rooms[4],&rooms[11]);
    rooms[4] = Room(labels[4],&rooms[0],&rooms[3],&rooms[13]);
    rooms[5] = Room(labels[5],&rooms[0],&rooms[6],&rooms[14]);
    rooms[6] = Room(labels[6],&rooms[5],&rooms[7],&rooms[15]);
    rooms[7] = Room(labels[7],&rooms[1],&rooms[6],&rooms[8]);
    rooms[8] = Room(labels[8],&rooms[7],&rooms[9],&rooms[16]);
    rooms[9] = Room(labels[9],&rooms[2],&rooms[8],&rooms[10]);
    rooms[10] = Room(labels[10],&rooms[9],&rooms[11],&rooms[17]);
    rooms[11] = Room(labels[11],&rooms[3],&rooms[10],&rooms[12]);
    rooms[12] = Room(labels[12],&rooms[11],&rooms[13],&rooms[18]);
    rooms[13] = Room(labels[13],&rooms[4],&rooms[12],&rooms[14]);
    rooms[14] = Room(labels[14],&rooms[5],&rooms[13],&rooms[19]);
    rooms[15] = Room(labels[15],&rooms[6],&rooms[16],&rooms[19]);
    rooms[16] = Room(labels[16],&rooms[8],&rooms[15],&rooms[17]);
    rooms[17] = Room(labels[17],&rooms[10],&rooms[16],&rooms[18]);
    rooms[18] = Room(labels[18],&rooms[12],&rooms[17],&rooms[19]);
    rooms[19] = Room(labels[19],&rooms[14],&rooms[15],&rooms[18]);

    // assign player and hazards: randomly shuffle vector with room numbers,
    // then select the first six and assign to player, pit, bats, and wumpus
    vector<int> room_no;
    for (int i = 0; i<20; ++i)
        room_no.push_back(i);
    random_shuffle(room_no.begin(),room_no.end());
    plr.location = &rooms[room_no[0]];
    rooms[room_no[1]].has_pit = true;
    rooms[room_no[2]].has_pit = true;
    rooms[room_no[3]].has_bat = true;
    rooms[room_no[4]].has_bat = true;
    wmp.location = &rooms[room_no[5]];

    // output for debugging
    //cout << "Pits: " << rooms[room_no[1]].label << " and "
    //    << rooms[room_no[2]].label << "\n";
    //cout << "Bats: " << rooms[room_no[3]].label << " and "
    //    << rooms[room_no[4]].label << "\n";
    //cout << "Wumpus: " << rooms[room_no[5]].label << "\n";
}

// ----------------------------------------------------------------------------

// if possible, move player to room with label lbl
bool Cave::move_player(int lbl) {
    Room* n = lbl_to_ptr(lbl);
    // see if label existed and move is legal
    if (n==0) {
        cout << "Not possible\n";
        return false;
    }
    else if (contains(plr.location->next,n)) {
        plr.location = n;
        return true;
    }
    else
        cout << "Not possible\n";
    return false;
}

// ----------------------------------------------------------------------------

// check for Wumpus, pits and bats in neighbouring rooms
void Cave::hazard_warnings() {
    if (plr.location->next[0] == wmp.location ||
        plr.location->next[1] == wmp.location ||
        plr.location->next[2] == wmp.location)
        cout << "I smell a Wumpus!\n";
    if (plr.location->next[0]->has_pit ||
        plr.location->next[1]->has_pit ||
        plr.location->next[2]->has_pit)
        cout << "I feel a draft!\n";
    if (plr.location->next[0]->has_bat ||
        plr.location->next[1]->has_bat ||
        plr.location->next[2]->has_bat)
        cout << "Bats nearby!\n";
}

// ----------------------------------------------------------------------------

// give neighbouring rooms
void Cave::room_description() {
    cout << "You are in room " << plr.location->label << "\n";
    cout << "Tunnels lead to " << plr.location->next[0]->label << ' '
        << plr.location->next[1]->label << ' '
        << plr.location->next[2]->label << "\n";
}

// ----------------------------------------------------------------------------

Room* Cave::get_player_loc() { return plr.location; }

// ----------------------------------------------------------------------------

void Cave::bat_flight() { plr.location = &rooms[randint(20)]; }

// ----------------------------------------------------------------------------

// wake Wumpus: stays in same room (P=0.25), move to neighbouring room (P=0.75)
void Cave::wake_wumpus() {
    int n = randint(4);
    if (n==3) return;
    wmp.location = wmp.location->next[n];

    // output for debugging
    //cout << "Wumpus is at " << wmp.location->label << "\n";
}

// ----------------------------------------------------------------------------

Game_state Cave::shoot_arrow() {
    // get valid route of arrow
    int n = get_int(1,5,"No. of rooms","Must be");
    vector<Room*> route(n);
    while (true) {
        for (int i = 0; i<n; ++i) {
            ostringstream os;
            os << "Room #" << i+1;
            route[i] = lbl_to_ptr(get_int(1,20,os.str(),"Must be"));
        }
        if (route_valid(route)) break;
    }

    // for each room, check if tunnel exists, choose random tunnel if not
    Room* arrow_loc = get_player_loc();
    for (int i = 0; i<route.size(); ++i) {
        if (contains(arrow_loc->next,route[i]))
            arrow_loc = route[i];
        else
            arrow_loc = arrow_loc->next[randint(3)];    // no connection
        //cout << arrow_loc->label << ' ';  // output for debugging

        // check if arrow in room with player or wumpus (die/win)
        if (arrow_loc==get_wumpus_loc()) return wmp_dead;
        if (arrow_loc==get_player_loc()) return plr_shot;
    }
    cout << "\n";

    // reduce number of arrows (if equals zero --> die)
    --plr.n_arrows;
    if (plr.n_arrows==0) return no_arrows;
    cout << "\n" << plr.n_arrows << " arrows left\n";
    return running;
}

// ----------------------------------------------------------------------------

Room* Cave::get_wumpus_loc() { return wmp.location; }

// ----------------------------------------------------------------------------

// return pointer to room with label lbl, and 0 if no such room exists
Room* Cave::lbl_to_ptr(int lbl) {
    for (int i = 0; i<20; ++i)
        if (rooms[i].label==lbl) return &rooms[i];
    return 0;
}

// ----------------------------------------------------------------------------

void print_instructions() {
    cout << "Welcome to 'Kara Hunts the Wumpus'!\n\n"
        << "The Wumpus lives in a cave of 20 rooms. Each room\n"
        << "has 3 tunnels leading to other rooms. (Look at a\n"
        << "dodecahedron to see how this works - if you don't know\n"
        << "what a dodecahedron is, ask someone.)\n\n"
        << "Hazards:\n"
        << "Bottomless pits - two rooms have bottomless pits in them.\n"
        << "If you go there, you fall into the pit (and lose!)\n"
        << "Super bats - two other rooms have super bats. If you\n"
        << "go there, a bat grabs you and takes you to some other\n"
        << "room at random (which might be troublesome).\n\n"
        << "Wumpus:\n"
        << "The Wumpus is not bothered by the hazards (he has sucker\n"
        << "feet and is too big for a bat to lift). Usually\n"
        << "he is asleep. Two things wake him up: your entering\n"
        << "his room or your shooting an arrow.\n"
        << "If the Wumpus wakes, he moves (75% chance) one room\n"
        << "or stays still (25% chance). After that, if he is where you\n"
        << "are, he eats you up (and you lose)!\n\n"
        << "You:\n"
        << "Each turn you may move or shoot a crooked arrow.\n"
        << "Moving: you can go one room (through one tunnel).\n"
        << "Arrows: you have 5 arrows. You lose when you run out.\n"
        << "Each arrow can go from 1 to 5 rooms. You aim by telling\n"
        << "the computer the room numbers you want the arrow to go to.\n"
        << "If the arrow can't go that way (i.e., no tunnel) it moves\n"
        << "at random to the next room.\n"
        << "If the arrow hits the Wumpus, you win.\n"
        << "If the arrow hits you, you lose.\n\n"
        << "Warnings: when you are one room away from a hazard,\n"
        << "the computer says:\n"
        << "Wumpus - I smell a Wumpus!\n"
        << "Bat - 'Bats nearby!'\n"
        << "Pit - 'I feel a draft!'\n\n";
}

// ----------------------------------------------------------------------------

// test if route for arrow is valid
bool route_valid(vector<Room*> r) {
    if (r.size()<1 || r.size()>5) {
        cout << "Route not valid, start again\n";
        return false;
    }
    for (int i = 2; i<r.size(); ++i) {
        if (r[i] == r[i-2]) {
            cout << "Arrows aren't THAT crooked - try again\n";
            return false;
        }
    }
    return true;
}

// ----------------------------------------------------------------------------

}   // namespace Wumpus

// ----------------------------------------------------------------------------

// helper function to recover from failing to get an int from cin
void skip_to_int() {
    if (cin.fail()) {
        cin.clear();
        char ch;
        while (cin>>ch) {
            if (isdigit(ch) || ch=='-') {
                cin.unget();
                return;
            }
        }
    }
    error("No input");
}

// ----------------------------------------------------------------------------

// read until cin provides an integer
int get_int() {
    int n = 0;
    while (true) {
        if (cin>>n) {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            return n;
        }
        cout << "Not valid\n";
        skip_to_int();
    }
}

// ----------------------------------------------------------------------------

// get integer in given range, prompt with greeting, print sorry if invalid
int get_int(int low, int high, const string& greeting, const string& sorry) {
    cout << greeting << " (" << low << '-' << high << ")\n";

    while (true) {
        int n = get_int();
        if (low<=n && n<=high) return n;
        cout << sorry << " (" << low << '-' << high << ")\n";
    }
}

// ----------------------------------------------------------------------------
