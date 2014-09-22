
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
    tag_input(Point(200,0),25,20,"Add warning to room:"),
    pit_tag_button(Point(230,0),68,20,"Pit?",cb_pittagpushed),
    bat_tag_button(Point(298,0),68,20,"Bat?",cb_battagpushed),
    wmp_tag_button(Point(366,0),68,20,"Wumpus?",cb_wmptagpushed),
    pit_excl_button(Point(230,20),68,20,"Pit!",cb_pitexclpushed),
    bat_excl_button(Point(298,20),68,20,"Bat!",cb_batexclpushed),
    wmp_excl_button(Point(366,20),68,20,"Wumpus!",cb_wmpexclpushed),
    output(Point(x_max()*2/3+40,40),x_max()/3-67,140,""),
    input(Point(x_max()*2/3+40,140+55),263,20,Wumpus::shoot_or_move_str),
    ok_button(Point(x_max()-97,140+55),70,20,"OK",cb_okpushed),
    show_instr_button(Point(x_max()-200,0),130,20,"Show instructions",cb_showinstrpushed),
    hide_instr_button(Point(x_max()-200,0),130,20,"Hide instructions",cb_hideinstrpushed),
    instr_box(Point(x_max()*2/3+40,230),x_max()/3-67,560,""),
    tags(new Vector_ref<Image>),
    we(new Wumpus::Wumpus_engine()),
    wm(Point(x_max()/3,y_max()/2),y_max()/2-15,we->c.get_rooms())
{
    attach(tag_input);
    attach(pit_tag_button);
    attach(bat_tag_button);
    attach(wmp_tag_button);
    attach(pit_excl_button);
    attach(bat_excl_button);
    attach(wmp_excl_button);
    attach(output);
    output.set_textsize(12);
    output.put(we->c.hazard_warnings() + we->c.room_description());
    uncloak_map();
    attach(input);
    input.take_focus();
    attach(ok_button);
    ok_button.shortcut(FL_Enter);
    attach(show_instr_button);
    attach(hide_instr_button);
    hide_instr_button.hide();
    attach(instr_box);
    instr_box.set_textsize(11);
    instr_box.put(Wumpus::get_instructions());
    instr_box.hide();
    wm.set_avatar(we->c.lbl_to_idx(we->c.get_player_loc()->label));
    attach(wm);
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
    input.take_focus();
}

//------------------------------------------------------------------------------

void Wumpus_window::show_instr_pressed()
{
    instr_box.show();
    show_instr_button.hide();
    hide_instr_button.show();
}

//------------------------------------------------------------------------------

void Wumpus_window::hide_instr_pressed()
{
    instr_box.hide();
    show_instr_button.show();
    hide_instr_button.hide();
}

//------------------------------------------------------------------------------

void Wumpus_window::tag_pressed(tag_type tt)
{
    int r = tag_input.get_int();
    tag_input.clear();
    if (r<1 || r>20) return;
    int idx = we->c.lbl_to_idx(r);
    if (wm.is_visible(idx)) {
        int x = wm.point(idx+1).x;
        int y = wm.point(idx+1).y;
        switch (tt) {
        case pit:
            tags->push_back(new Image(Point(x-45,y+15),"pics_and_txt/wump_pit.jpg"));
            break;
        case pit_excl:
            tags->push_back(new Image(Point(x-45,y+15),"pics_and_txt/wump_pit_conf.jpg"));
            break;
        case bat:
            tags->push_back(new Image(Point(x-15,y-45),"pics_and_txt/wump_bat.jpg"));
            break;
        case bat_excl:
            tags->push_back(new Image(Point(x-15,y-45),"pics_and_txt/wump_bat_conf.jpg"));
            break;
        case wumpus:
            tags->push_back(new Image(Point(x+15,y+15),"pics_and_txt/wump_wump.jpg"));
            break;
        case wumpus_excl:
            tags->push_back(new Image(Point(x+15,y+15),"pics_and_txt/wump_wump_conf.jpg"));
            break;
        default:
            error("Illegal tag type");
        }
        attach((*tags)[tags->size()-1]);
        redraw();
    }
    input.take_focus();
}

//------------------------------------------------------------------------------

// get 's' or 'm' from input, set to move or shoot, change input label
void Wumpus_window::get_s_or_m()
{
    string in = input.get_string();
    input.clear();
    if (in=="s" || in=="S") {
        input.set_label("No. of rooms:");
        redraw();
        we->gs = Wumpus::shoot;
    }
    else if (in=="m" || in=="M") {
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
    if (r<1 || r>20) {
        input.set_label("Number between 1 and 20:");
        redraw();
        return;
    }
    if (we->c.move_player(r)) {
        wm.set_avatar(we->c.lbl_to_idx(we->c.get_player_loc()->label));
        ostringstream oss;  // collect strings for output

        // check for bat
        while (we->c.get_player_loc()->has_bat) {
            oss << "Zap - super bat snatch! Elsewhereville for you!\n";
            we->c.bat_flight();
            wm.set_avatar(we->c.lbl_to_idx(we->c.get_player_loc()->label));
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
        uncloak_map();
        we->gs = Wumpus::shoot_or_move;
        input.set_label(Wumpus::shoot_or_move_str);
        redraw();
    }
    else {
        output.put("Not possible! Choose another room.\n"
            + we->c.hazard_warnings() + we->c.room_description());
        uncloak_map();
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
    if (n<1 || n>20) {
        input.set_label("Number between 1 and 20:");
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
            uncloak_map();
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
    if (in=="n" || in=="N") {
        hide();
    }
    else if (in=="y" || in=="Y") {
        reset_wumpus_engine();
        for (int i = 0; i<tags->size(); ++i)
            detach((*tags)[i]);
        delete tags;
        tags = new Vector_ref<Image>;
        wm.set_avatar(we->c.lbl_to_idx(we->c.get_player_loc()->label));
        output.put(we->c.hazard_warnings() + we->c.room_description());
        uncloak_map();
        redraw();
    }
    return;
}

//------------------------------------------------------------------------------

// show new parts of map around player location
void Wumpus_window::uncloak_map()
{
    Wumpus::Room* pl = we->c.get_player_loc();
    int pl_idx = we->c.lbl_to_idx(pl->label);
    wm.show(pl_idx);

    Point p1 = wm.point(pl_idx+1);
    double rad = wm.lbl_radius();

    for (int i = 0; i<3; ++i) {
        int nxt_idx = we->c.lbl_to_idx(pl->next[i]->label);
        wm.show(nxt_idx);

        // draw line from circle boundary instead of center
        Point p2 = wm.point(nxt_idx+1);
        double length = sqrt(pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2));
        Point p3 = Point(p1.x + rad*(p2.x-p1.x)/length,
            p1.y + rad*(p2.y-p1.y)/length);
        Point p4 = Point(round(p2.x + rad*(p1.x-p2.x)/length),
            round(p2.y + rad*(p1.y-p2.y)/length));
        wm.add_tunnel(p3,p4);
    }
}

//------------------------------------------------------------------------------

// reset Wumpus engine
void Wumpus_window::reset_wumpus_engine()
{
    delete we;
    we = new Wumpus::Wumpus_engine();
    input.set_label(Wumpus::shoot_or_move_str);
    wm.reset_labels(we->c.get_rooms());
    wm.hide_all();
}

//------------------------------------------------------------------------------

} // Graph_lib
