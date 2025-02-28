#include <iostream>
#include "Item.h"
#include "Location.h"
#include "Obstacle.h"
#include "Player.h"
#include "Global_Functions.h"

using namespace std;

int main()
{
    /*
        Create Player
        set player vars   set_player_name()

        Create Items
        Set Item Defaults set_item_defaults()

        Create Obstacle and link the Item to them via item.get_item_name()

        Create location
        if item in location, set_item_in_location()
        if this location is blocked, set_location_path_is_blocked_by()
        if theres light in location, set_light_in_aera()
        link path to other locations, add_pathway()

    */

    Player player = Player();

    Item rustyKey = Item();
    rustyKey.set_item_defaults("Rusty Key", "A Rusty Key", "On the counter top, theres an odd looking key collecting dust by the window.", 1); ////BUGGG IF DURABILITY IS GREATER THAN 1, ITEM IN INVENTORY DOSENT GET REDUCED BY 1 WHEN USED





    Obstacle door = Obstacle();
    door.set_obstacle_defualts("Cracked Door", "The Door looks extreamly old but its study enough to not be hit down easily. The key hole still looks like its in working condition.", rustyKey.get_item_name(), /*"The key hole seems in tact. Maybe theres a key around here.",*/ "You opened the door");

    
    Location bedroom = Location("Bedroom", "A small bedroom that looks like a childs play room.", "Childs Bedroom");
    Location hallway = Location("Hallway", "A hallway with multiple connecting doors.", "Hallway");
    Location bathroom = Location("Bathroom", "A small bathroom", "Bathroom");
    Location kitchen = Location("Kitchen", "A kitchen with an abundance of stoves for some reason", "Kitchen");


    bedroom.add_pathway(hallway);
    bedroom.set_item_in_location(rustyKey);
    bedroom.set_light_in_area(true);

    hallway.add_pathway(bedroom);
    hallway.add_pathway(kitchen);
    hallway.add_pathway(bathroom);
    hallway.set_location_path_is_blocked_by(door);

    bathroom.add_pathway(hallway);

    kitchen.add_pathway(hallway);
    kitchen.set_light_in_area(true);

    Location* curruntLocation = &bedroom;

    bool playing = true;
    int userInputNum = 0;
    int LoopIncrement = 0;
    string userInputString = "abc";


    cout << "Welcome, what is your name?" << endl;
    cout << "---";
    cin >> userInputString;
    player.set_player_name(userInputString);
    system("cls");
    cout << "Welcome, " << player.get_player_name() << endl;

    while (playing == true) {

        cout << "You are at --- " << curruntLocation->get_loc_name() << endl;       //Prints the location you are in
        cout << curruntLocation->get_loc_description() << endl;

        cout << '\n' << "You can see these (Enter number to travel)" << endl;
        for (LoopIncrement = 0; LoopIncrement < curruntLocation->get_pathways().size(); LoopIncrement++) {
            cout << "[" << LoopIncrement << "] " << curruntLocation->get_pathways()[LoopIncrement]->get_loc_distant_description() << endl;  //outputs the locations connected to the location you are in
        }
        cout << endl;
        cout << "[" << LoopIncrement << "] Search Area" << endl;    //option to search the area you are in
        cout << "[" << LoopIncrement + 1 << "] Open Inventory" << endl; //desplays the items in your inventory
        cout << ">>>";
        cin >> userInputNum;

        while (cin.fail()) { //check for input that is not a number
            cout << "Input a number" << endl;
            clear_invalid_input();
            cin >> userInputNum;
            while (userInputNum < 0 || userInputNum > LoopIncrement + 1) {  //checks for wrong input
                cout << "Wrong input, try again!" << '\n' << ">>>";
                cin >> userInputNum;
            }
        }

        system("cls");

        if (userInputNum < LoopIncrement) {
            if (curruntLocation->move_to_location(curruntLocation, userInputNum, player) == true) {
                curruntLocation = curruntLocation->get_pathways()[userInputNum];    //moves to location if the user input was correct
            }            
        }
        else if (userInputNum == LoopIncrement){
            curruntLocation->search_location(player);   //search location for items
        }
        else {
            player.output_all_items_in_inventory();     //displayes all inventory items to player
        }

    }
}