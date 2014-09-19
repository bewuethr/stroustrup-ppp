
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "chapter19_ex14_Simple_window.h"

namespace Graph_lib {;

//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
    button_pushed(false)
{
    attach(next_button);
}

//------------------------------------------------------------------------------

bool Simple_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
    show();
    button_pushed = false;
#if 1
    // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

void Simple_window::cb_next(Address, Address pw)
// call Simple_window::next() for the window located at pw
{
    reference_to<Simple_window>(pw).next();
}

//------------------------------------------------------------------------------

void Simple_window::next()
{
    button_pushed = true;
    hide();
}

//------------------------------------------------------------------------------

Quit_window::Quit_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    quit_button(Point(x_max()-70,0),70,20,"Quit",cb_qpushed)
{
    attach(quit_button);
}

//------------------------------------------------------------------------------

Wumpus_window::Wumpus_window()
    :Quit_window(Point(200,50),1200,800,"Hunt the Wumpus"),
    output(Point(x_max()*2/3+40,40),x_max()/3-67,140,""),
    input(Point(x_max()*2/3+40,140+55),263,20,Wumpus::shoot_or_move_str),
    ok_button(Point(x_max()-97,140+55),70,20,"OK",cb_okpushed),
    we(new Wumpus::Wumpus_engine())
{
    attach(output);
    output.set_textsize(12);
    output.put(we->c.hazard_warnings() + we->c.room_description());
    attach(input);
    attach(ok_button);
}

//------------------------------------------------------------------------------

void Wumpus_window::ok_pressed()
{
    switch (we->gs) {
    case Wumpus::shoot_or_move:
        get_s_or_m();
        break;
    case Wumpus::move:
        move_player();
        break;
    case Wumpus::shoot:
        get_n_of_rooms();
        break;
    case Wumpus::get_room:
        // if arrow route is shorter than desired, add next room to it
        // if arrow route is complete, fire arrow
        fire_arrow();
        break;
    case Wumpus::restart:
        restart();
        break;
    default:
        error("Illegal Game_state");
        break;
    }
}

//------------------------------------------------------------------------------

// get 's' or 'm' from input, set to move or shoot, change input label
void Wumpus_window::get_s_or_m()
{
    string in = input.get_string();
    input.clear();
    if (in=="s") {
        input.set_label("No. of rooms:");
        redraw();
        we->gs = Wumpus::shoot;
    }
    else if (in=="m") {
        input.set_label(Wumpus::where_str);
        redraw();
        we->gs = Wumpus::move;
    }
    return;
}

//------------------------------------------------------------------------------

// get room number from input and, if valid, move player
// check for Wumpus, bat and pit after move
// set to shoot_or_move, change input label
void Wumpus_window::move_player()
{
    int r = input.get_int();
    input.clear();
    if (r<0 || r>19) {  // TODO (Benjamin#1#): Set back to 1 to 20
        input.set_label("Number between 0 and 19:");    // TODO (Benjamin#1#): Set back to 1 to 20
        redraw();
        return;
    }
    if (we->c.move_player(r)) {
        ostringstream oss;  // collect strings for output

        // check for bat
        while (we->c.get_player_loc()->has_bat) {
            oss << "Zap - super bat snatch! Elsewhereville for you!\n";
            we->c.bat_flight();
        }

        // check for pit
        if (we->c.get_player_loc()->has_pit) {
            oss << "Yyyiiiieeee... fell in pit!\n" << Wumpus::you_loose_str;
            output.put(oss.str());
            input.set_label(Wumpus::restart_str);
            we->gs = Wumpus::restart;
            redraw();
            return;
        }

        // check for Wumpus
        if (we->c.get_player_loc() == we->c.get_wumpus_loc()) {
            oss << "...oops! Bumped a Wumpus!\n";
            we->c.wake_wumpus();
            if (we->c.get_player_loc() == we->c.get_wumpus_loc()) {
                oss << "Tsk tsk tsk - Wumpus got you!\n"
                    << Wumpus::you_loose_str;
                output.put(oss.str());
                input.set_label(Wumpus::restart_str);
                we->gs = Wumpus::restart;
                redraw();
                return;
            }
        }

        oss << we->c.hazard_warnings() + we->c.room_description();
        output.put(oss.str());
        we->gs = Wumpus::shoot_or_move;
        input.set_label(Wumpus::shoot_or_move_str);
        redraw();
    }
    else {
        output.put("Not possible! Choose another room.\n"
            + we->c.hazard_warnings() + we->c.room_description());
        input.set_label(Wumpus::where_str);
        redraw();
    }
}

//------------------------------------------------------------------------------

// get number of rooms for arrow route, must be between 1 and 5
void Wumpus_window::get_n_of_rooms()
{
    int n = input.get_int();
    input.clear();
    if (n<1 || n>5) {
        input.set_label("Number between 1 and 5:");
        redraw();
        return;
    }
    we->room_ctr = n;
    input.set_label("Room #1:");
    we->gs = Wumpus::get_room;
    redraw();
}

//------------------------------------------------------------------------------

// get next room for route: only accept existing rooms, but don't check connec-
// tivity; don't accept routes that require the arrow to turn around
void Wumpus_window::fire_arrow()
{
    int n = input.get_int();
    input.clear();
    if (n<0 || n>19) {  // TODO (Benjamin#1#): Set back to 1 to 20
        input.set_label("Number between 0 and 19:");    // TODO (Benjamin#1#): Set back to 1 to 20
        redraw();
        return;
    }
    we->route.push_back(we->c.lbl_to_ptr(n));

    // check for illegal route
    if (we->route.size() >= 3 &&
        we->route[we->route.size()-1] == we->route[we->route.size()-3]) {
        output.put("Arrows aren't THAT crooked - try again\n");
        we->route.resize(0);
        input.set_label("Room #1:");
        redraw();
        return;
    }
    if (we->route.size() < we->room_ctr) {
        ostringstream oss;
        oss << "Room #" << we->route.size()+1 << ":";
        input.set_label(oss.str());
        redraw();
        return;
    }
    else {  // fire arrow
        Wumpus::Game_state gs = we->c.shoot_arrow(we->route);
        ostringstream oss;
        switch(gs) {
        case Wumpus::wmp_dead:
            oss << Wumpus::you_win_str;
            break;
        case Wumpus::plr_shot:
            oss << "Ouch! Arrow got you!\n" << Wumpus::you_loose_str;
            break;
        case Wumpus::no_arrows:
            oss << "You have run out of arrows!\n" << Wumpus::you_loose_str;
            break;
        case Wumpus::running:
            we->c.wake_wumpus();
            we->route.resize(0);
            if (we->c.get_player_loc() == we->c.get_wumpus_loc()) {
                oss << "Tsk tsk tsk - Wumpus got you!\n"
                    << Wumpus::you_loose_str;
                break;
            }
            oss << we->c.get_n_arrows() << " arrows left\n";
            oss << we->c.hazard_warnings() + we->c.room_description();
            output.put(oss.str());
            we->gs = Wumpus::shoot_or_move;
            input.set_label(Wumpus::shoot_or_move_str);
            redraw();
            return;
        default:
            error("Illegal game_state");
            break;
        }
        output.put(oss.str());
        input.set_label(Wumpus::restart_str);
        we->gs = Wumpus::restart;
        redraw();
    }

}

//------------------------------------------------------------------------------

// get 'y' or 'n', the restart or quit
void Wumpus_window::restart()
{
    string in = input.get_string();
    input.clear();
    if (in=="n") {
        hide();
    }
    else if (in=="y") {
        reset_wumpus_engine();
        output.put(we->c.hazard_warnings() + we->c.room_description());
        redraw();
    }
    return;
}

//------------------------------------------------------------------------------

// reset Wumpus engine
void Wumpus_window::reset_wumpus_engine()
{
    delete we;
    we = new Wumpus::Wumpus_engine();
    input.set_label(Wumpus::shoot_or_move_str);
}

//------------------------------------------------------------------------------

} // Graph_lib
