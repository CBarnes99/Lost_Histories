#include <iostream>
#include "Item.h"
#include "Location.h"
#include "Obstacle.h"
#include "Player.h"

using namespace std;

int main()
{
    /*
        Create Player
        set player vars

        Create Items

        Create Obstacle and link the Item to them

        Create location and link item and obstacle
    */


    Player player = Player();
    player.set_player_name("Steve");

    Item rustyKey = Item();
    rustyKey.set_item_defaults("Key", "A Rusty Key", "On the counter top, theres an odd looking key collecting dust by the window.");

    Obstacle door = Obstacle("Cracked Door", "The Door looks extreamly old but its study enough to not be hit down easily.", rustyKey.get_item_name(), "The key hole seems in tact. Maybe theres a key around here.");
    Location bedroom = Location("Bedroom", "A small bedroom that looks like a childs play room.", "Childs Bedroom");
    Location hallway = Location("Hallway", "A hallway with multiple connecting doors.", "Hallway");


    bedroom.add_pathway(hallway);
    bedroom.set_item_in_location(rustyKey);
    bedroom.set_light_in_area(true);

    hallway.add_pathway(bedroom);
    hallway.set_location_path_is_blocked(door);


    Location& curruntLocation = bedroom;
    int userInput;


    while (true) {

        cout << "You are at --- " << curruntLocation.get_loc_name() << endl;
        cout << curruntLocation.get_loc_description() << endl;

        cout << '\n' << "You can see these (Enter number to travel)" << endl;
        for (int i = 0; i < curruntLocation.get_pathways().size(); i++) {
            cout << "[ " << i << " ] " << curruntLocation.get_pathways()[i]->get_loc_distant_description() << endl;
        }
        cout << ">>>";
        cin >> userInput;
    }
}

