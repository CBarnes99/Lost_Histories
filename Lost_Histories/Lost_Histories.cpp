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
        to link path to other locations, set_pathway()

    */
    //Player Class Here//
    Player player = Player("defualt");


    //Item Classes Here//
       
    Item iCoin = Item();
    iCoin.set_item_defaults("A Gold Coin", "An Aureus Gold Coin, definitly not real but it looks cool", 1);

  
    //Obstacle Classes Here//
    //Obstacle door = Obstacle();
    //door.set_obstacle_defualts("Cracked Door", "The Door looks extreamly old but its study enough to not be hit down easily. The key hole still looks like its in working condition.", rustyKey.get_item_name(), "You opened the door");

    

    ///Searchables Classes Here//
    //Searchables cupboard = Searchables();
    //cupboard.set_item(rustyKey);
    //cupboard.set_opening_description("You open the door to the cupboard");
    //cupboard.set_searchables_name("Cupboard");

    Searchables sLeftFountain = Searchables();
    sLeftFountain.set_searchables_name("The Bernini Fountain");
    sLeftFountain.set_item(iCoin);
    sLeftFountain.set_opening_description("You reach in to the fountains water.");

    

    //Location Classes Here//
    Location lInFrontOfSquare = Location("In Front of St Peter's Square", "An open entrance leading up to the Square", "Eerily quite, not another person in sight. The Popes situation must be serious if the public aren't allowed in.");
    Location lStPetersSquare = Location("St Peter's Square", "A huge open area surrounded by statues overlooking the square.", "The Obelisk in the center with fountains either side while being overlooked by St Peter's Basilica.");
    Location lObelisk = Location("Obelisk", "Vaticano, one of the thirteen Roman Obelisks.", "Enscribed on the Obelisk says: DIVO CAESARI DIVI F AVGVSTO TI CAESARI DIVI AVGVSTI F AVGVSTO SACRVM, Sacred to the Divine Caesar Augustus, son of the Divine, to Tiberius Caesar Augustus, son of the Divine Augustus. ");
    Location lLeftFountain = Location("Left Fountain", "The fountain to the left of the Obelisk.", "The Bernini Fountain");
    Location lRightFountain = Location("Right Fountain", "The fountain to the right of the Obelisk.", "The Maderno Fountain");


    Location stPetersBasilicaEntrance = Location("St Peter's Basilica", "A monolithic structure that is the focal point of the Vatican", "St Peter's Basilica");




    lInFrontOfSquare.set_pathway(lStPetersSquare);
    

    lStPetersSquare.set_pathway(lInFrontOfSquare);
    lStPetersSquare.set_pathway(lObelisk);
    lStPetersSquare.set_pathway(lLeftFountain);
    lStPetersSquare.set_pathway(lRightFountain);
    lStPetersSquare.set_pathway(stPetersBasilicaEntrance);

    lObelisk.set_pathway(lStPetersSquare);
    
    lLeftFountain.set_pathway(lStPetersSquare);
    lLeftFountain.set_searchables_in_location(sLeftFountain);



    lRightFountain.set_pathway(lStPetersSquare);

    stPetersBasilicaEntrance.set_pathway(lStPetersSquare);


    
  /*
    Location bedroom = Location("Bedroom", "A small bedroom that looks like a childs play room.", "Childs Bedroom");
    Location hallway = Location("Hallway", "A hallway with multiple connecting doors.", "Hallway");
    Location bathroom = Location("Bathroom", "A small bathroom", "Bathroom");
    Location kitchen = Location("Kitchen", "A kitchen with an abundance of stoves for some reason", "Kitchen");

    bedroom.set_pathway(hallway);
    bedroom.set_searchables_in_location(cupboard);
    bedroom.set_searchables_in_location(chest);

    hallway.set_pathway(bedroom);
    hallway.set_pathway(kitchen);
    hallway.set_pathway(bathroom);
    hallway.set_location_path_is_blocked_by(door);

    bathroom.set_pathway(hallway);

    kitchen.set_pathway(hallway);
    kitchen.set_searchables_in_location(draw);
  */


    Location* curruntLocation = &lInFrontOfSquare;

    bool playing = true;
    int userInputNum = 0;
    int LoopIncrement = 0;
    string userInputString = "abc";


    cout << "Welcome, what is your name?" << endl;
    cout << "---";
    cin >> userInputString;
    player.set_player_name(userInputString);
    system("cls");
    cout << "Welcome, " << player.get_character_name() << endl;

    //make introduction section
    letter_by_letter_output("I've been called in specifically to help with the situation thats taking place at the Vatican. The Pope has fallen ill and requires help from the best medical professional, that would indeed be me.", 1);
    enter_to_continue();
    letter_by_letter_output("Its currently 10pm, I'm unsure why they asked for me to wait for night to come and not ASAP, but the Pope probably has a busy schedule even when ill.", 1);
    enter_to_continue();
    letter_by_letter_output("As I approach the the entrance to the St.Peters Square, I am approched by someone in a fancy suit.", 1);
    enter_to_continue();














    //main game
    while (playing == true) {
        
        cout << "You are at --- " << curruntLocation->get_loc_name() << endl;       //Prints the location you are in
        cout << curruntLocation->get_loc_description() << endl;

        cout << '\n' << "You can see these (Enter number to travel)" << endl;
        for (LoopIncrement = 0; LoopIncrement < curruntLocation->get_pathways().size(); LoopIncrement++) {
            cout << "[" << LoopIncrement << "] " << curruntLocation->get_pathways()[LoopIncrement]->get_loc_name() << endl;  //outputs the locations connected to the location you are in
        }
        cout << endl;
        cout << "[" << LoopIncrement << "] Inspect Current Location" << endl;    //option to search the area you are in
        cout << "[" << LoopIncrement + 1 << "] Search Area" << endl; //desplays the items in your inventory
        cout << "[" << LoopIncrement + 2 << "] Open Inventory" << endl; //desplays the items in your inventory
        cout << ">>>";
        clear_invalid_input();
        cin >> userInputNum;

        while (cin.fail()) { //check for input that is not a number
            cout << "Input a number" << endl;
            clear_invalid_input();
            cin >> userInputNum;
            while (userInputNum < 0 || userInputNum > LoopIncrement + 2) {  //checks for wrong input
                cout << "Wrong input, try again!" << '\n' << ">>>";
                clear_invalid_input();
                cin >> userInputNum;
            }
        }
        system("cls");

        if (userInputNum < LoopIncrement) {
            Location* desiredLocation = curruntLocation->get_pathways()[userInputNum];

            if (desiredLocation->is_loc_accessible(player) == true) {
                curruntLocation = desiredLocation;
            }

        }
        else if (userInputNum == LoopIncrement){
            letter_by_letter_output(curruntLocation->get_loc_inspect_location(), 2); //output location inspection string
        }
        else if (userInputNum == LoopIncrement + 1) {
            curruntLocation->search_location(player);   //search location for items
            
        }
        else {
            player.output_all_items_in_inventory(false);     //displays all inventory items to player
     
        }
        
    }
}