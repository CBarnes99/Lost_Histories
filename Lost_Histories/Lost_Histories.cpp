#include <iostream>
#include "Item.h"
#include "Location.h"
#include "Obstacle.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    Item rustyKey = Item("Rusty Key", "Big rust", rustyDoor);

<<<<<<< Updated upstream
    Obstacle rustyDoor = Obstacle("Rusty Door", "Big Rusty Door", rustyKey, "Maybe rusty key hmmm");
=======
    /*
        Create Player
        set player vars

        Create Items

        Create Obstacle and link the Item to them

        Create location and link item and obstacle
    */


    Player player = Player();
    player.set_Player_Name("Steve");


    Item rustyKey = Item();
    rustyKey.set_Item_Defaults("Key", "A Rusty Key", "On the counter top, theres an odd looking key collecting dust by the window.");

    Obstacle door = Obstacle("Cracked Door", "The Door looks extreamly old but its study enough to not be hit down easily.", rustyKey.get_Item_Name(), "The key hole seems in tact still. Maybe theres a key around here.");

    Location bedroom = Location("Bedroom", "A small bedroom that looks like a childs play room.", "Childs Bedroom");
    Location hallway = Location("Hallway", "A hallway with multiple connecting doors.", "Hallway");

    bedroom.add_Pathway(hallway);
    bedroom.set_Item_In_Location(rustyKey);
    bedroom.set_Light_In_Area(true);

    hallway.add_Pathway(bedroom);
    hallway.set_Location_Path_Is_Blocked(door);
>>>>>>> Stashed changes

    Location room = Location("Room", "Big room", "Dark room", "looks like a big room", true, Item("key", "rusty", Obstacle("rusty door", "big rusty door", "key", "look for a rusty key"));




    Location& curruntLocation = bedroom;
    int userInput;



    while (true) {

        cout << "You are at --- " << curruntLocation.get_Name() << endl;
        cout << curruntLocation.get_Loc_Description() << endl;

        cout << '\n' << "You can see these (Enter number to travel)" << endl;
        for (int i = 0; i < curruntLocation.get_Pathways().size(); i++) {
            cout << "[ " << i << " ] " << curruntLocation.get_Pathways()[i]->get_Loc_Distant_Description() << endl;
        }
        cout << ">>>";
        cin >> userInput;
    }

}

