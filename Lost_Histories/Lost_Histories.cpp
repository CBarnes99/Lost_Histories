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

        Create Searchables

        Create Items
        Set Item Defaults set_item_defaults()

        Create Obstacle and link the Item to them via item.get_item_name()

        Create location
        if item in location, set_item_in_location()
        if this location is blocked by obstacle, set_location_path_is_blocked_by()
        if theres light in location, set_light_in_area()
        to link path to other locations, add_pathway()

    */
    //Player Class Here
    Player player = Player();


    //Item Classes Here
    Item rustyKey = Item();
    rustyKey.set_item_defaults("Rusty Key", "A Rusty Key", 1); //"On the counter top, theres an odd looking key collecting dust by the window.",
    
    Item gun = Item();
    gun.set_item_defaults("Tommy Gun", "An old WW1 Tommy Gun", 10);

  
    //Obstacle Classes Here
    Obstacle door = Obstacle();
    door.set_obstacle_defualts("Cracked Door", "The Door looks extreamly old but its study enough to not be hit down easily. The key hole still looks like its in working condition.", rustyKey.get_item_name(), "You opened the door");

    Obstacle lock = Obstacle();
    lock.set_obstacle_defualts("A silver Lock", "A silver lock with no key hole to be found", gun.get_item_name(), "You shoot the lock and it explodes into a billion pieces");
    

    ///Searchables Classes Here
    Searchables cupboard = Searchables();
    cupboard.set_item(rustyKey);
    cupboard.set_needs_opening("You open the door to the cupboard");
    cupboard.set_searchables_name("Cupboard");

    Searchables chest = Searchables();
    chest.set_needs_opening("You open the heavy lid of the chest");
    chest.set_searchables_name("Gold lined chest");
    chest.set_obstacle(&lock, "Shot the lock");

    Searchables draw = Searchables();
    draw.set_item(gun);
    draw.set_searchables_name("Drawer");
    draw.set_needs_opening("You pull the draw open");



    //Location Classes Here
    Location bedroom = Location("Bedroom", "A small bedroom that looks like a childs play room.", "Childs Bedroom");
    Location hallway = Location("Hallway", "A hallway with multiple connecting doors.", "Hallway");
    Location bathroom = Location("Bathroom", "A small bathroom", "Bathroom");
    Location kitchen = Location("Kitchen", "A kitchen with an abundance of stoves for some reason", "Kitchen");

    bedroom.add_pathway(hallway);
    bedroom.set_light_in_area(true);
    bedroom.set_searchables_in_location(cupboard);
    bedroom.set_searchables_in_location(chest);

    hallway.add_pathway(bedroom);
    hallway.add_pathway(kitchen);
    hallway.add_pathway(bathroom);
    hallway.set_location_path_is_blocked_by(door);

    bathroom.add_pathway(hallway);

    kitchen.add_pathway(hallway);
    kitchen.set_searchables_in_location(draw);
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
        clear_invalid_input();
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
        clear_invalid_input();
        system("cls");

        if (userInputNum < LoopIncrement) {
            Location* desiredLocation = curruntLocation->get_pathways()[userInputNum];

            if (desiredLocation->is_Loc_Accessible(player) == true) {
                curruntLocation = desiredLocation;
            }

        }
        else if (userInputNum == LoopIncrement){
            curruntLocation->search_location(player);   //search location for items
        }
        else {
            player.output_all_items_in_inventory();     //displays all inventory items to player
        }
        
    }
}