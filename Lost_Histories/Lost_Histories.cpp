#include <iostream>
#include "Item.h"
#include "Location.h"
#include "Obstacle.h"
#include "Player.h"
#include "Global_Functions.h"
#include "NPC.h"

using namespace std;

void introductionsEnd(NPC character);

int main()
{
    /*
        Create Player
        set player vars   set_player_name()

        Create NPCs

        Create Items
        Set Item Defaults set_item_defaults()
        
        Create Obstacle and link the Item to them via item.get_item_name()

        Create Searchables

        Create location
        if item in location, set_searchable_in_location()
        if this location is blocked by obstacle, set_location_path_is_blocked_by()
        to link path to other locations, set_pathway()

    */
    //Player Class Here//
    Player player = Player("Barry");

    //NPC Classes Here//
    NPC caretaker = NPC("Careataker");
    caretaker.addDiologue("Thank you for coming on such short notice, " + player.get_character_name() + ". I am the caretaker of the Basilica. The pope is currenlty occupied but he'll be ready for you in a moment. I'll wait for you inside the Basilica.");
    caretaker.addDiologue("The Pope is still occupied, but let me ask you this, when you look at the Baldachin knowing its protecting St Peters Tomb from the light above, how does that make you feel?");
    caretaker.addDiologue("Ignoreing the first remark, I like your answer. But what if I told you the light of God isn't always the best thing for us.");
    caretaker.addDiologue("The Caretaker shaking his head in frustration. No no no, will you shut up! You simply don't get it, they CANT take in Gods rays, because, nevermind, you'll find you soon enough.");

    //Item Classes Here// 
    //S = IN SEARCHABLE X, O = OPENEING OBSTACLE X

    Item iCoin = Item(); //1 - S 1, O ?????
    iCoin.set_item_defaults("A Gold Coin", "An Aureus Gold Coin, definitly not real but it looks cool", 1);

    Item iRustyKey = Item(); //2 - S 2, O 1 
    iRustyKey.set_item_defaults("Rusty Key", "A rusty key that is bearly holding together, probably will break when its used.", 1);

    Item iTest2 = Item(); //3 --- 
    iTest2.set_item_defaults(" ", " ", 1);

    Item iTest3 = Item(); //4 --- 
    iTest3.set_item_defaults(" ", " ", 1);

    Item iTest4 = Item(); //5 --- 
    iTest4.set_item_defaults(" ", " ", 1);

    Item iNote = Item(); //6 --- In Chest of Drawers
    iNote.set_item_defaults("A Note", "A medical note with alot of information about this one person called Nick, is this even useful?", 2);

    Item iTest6 = Item(); //7 --- 
    iTest6.set_item_defaults(" ", " ", 1);

    Item iTest7 = Item(); //8 --- 
    iTest7.set_item_defaults(" ", " ", 1);

    Item iTest8 = Item(); //9 --- 
    iTest8.set_item_defaults(" ", " ", 1);

    Item iTest9 = Item(); //10 --- 
    iTest9.set_item_defaults(" ", " ", 1);

    Item iTest10 = Item(); //11 --- 11 will be a leaver to enter the shirne
    iTest10.set_item_defaults( " ", " ", 1);


  
    //Obstacle Classes Here//
    // I = ITEM NEEDED TO UNBLOCK OBSTACLE

    Obstacle oLockedDoor = Obstacle(); //1 --- For entering the hallway
    oLockedDoor.set_obstacle_defualts("Bloodstained Door", "The door locked is covered in fresh blood", iRustyKey.get_item_name(), "You put the key through the blood soaked keyhole and gently push open the door trying to avoid the blood with your hand.");

    Obstacle oTest2 = Obstacle(); //2 --- For opening TEST 3
    oTest2.set_obstacle_defualts(" ", " ", " ", " ");

    Obstacle oTest3 = Obstacle(); //3 --- 
    oTest3.set_obstacle_defualts(" ", " ", " ", " ");

    Obstacle oLockedChestOfDrawers = Obstacle(); //4 --- For the chest of drawers
    //oLockedChestOfDrawers.set_obstacle_defualts("Chest of Draws With Keyhole", "One of the draws has a lock, now wheres the key", )
    
    Obstacle oTest5 = Obstacle(); //5 --- 
    oTest5.set_obstacle_defualts(" ", " ", " ", " ");

    Obstacle oTest6 = Obstacle(); //6 --- 
    oTest6.set_obstacle_defualts(" ", " ", " ", " ");

    Obstacle oTest7 = Obstacle(); //7 --- 
    oTest7.set_obstacle_defualts(" ", " ", " ", " ");

    Obstacle oTest8 = Obstacle(); //8 --- 
    oTest8.set_obstacle_defualts(" ", " ", " ", " ");

    Obstacle oTest9 = Obstacle(); //9 --- 
    oTest9.set_obstacle_defualts(" ", " ", " ", " ");

    Obstacle oTest10 = Obstacle(); //10 --- 
    oTest10.set_obstacle_defualts(" ", " ", " ", " ");

    ///Searchables Classes Here//
    // N = NOT BLOCKED, B = BLOCKED BY X, G = GAIN AN ITEM FOR X OBSTACLE

    Searchables sLeftFountain = Searchables(); //1 - N, G 1 --- In Left Fountain
    sLeftFountain.set_searchables_name("The Bernini Fountain");
    sLeftFountain.set_item(iCoin);
    sLeftFountain.set_opening_description("You reach in to the fountains water.");

    Searchables sMedicalTrolley = Searchables(); //2 - N, G 2 --- In Hospital Room
    sMedicalTrolley.set_searchables_name("Medical Trolley");
    sMedicalTrolley.set_item(iRustyKey);
    sMedicalTrolley.set_opening_description("You open the draw on the trolley.");

    Searchables sCabinet = Searchables(); //3 - N, G 3 --- In Hallway
    sCabinet.set_searchables_name("Brown Cabinet");
   //sCabinet.set_item();
    sCabinet.set_opening_description("You open the two stiff doors gently hoping nothing jumps out.");

    Searchables sTEST3 = Searchables(); //4 - B 2, G 4 --- In Storage 
    sTEST3.set_searchables_name(" ");
    //sTEST3.set_item();
    sTEST3.set_opening_description(" ");

    Searchables sChestOfDrawers = Searchables(); //5 --- In Hospital Room
    sChestOfDrawers.set_searchables_name("Chest of Draws");
    sChestOfDrawers.set_item(iNote);

    Searchables sTEST5 = Searchables(); //6 --- 
    sTEST5.set_searchables_name(" ");
    //TEST5.set_item();
    sTEST5.set_opening_description(" ");

    Searchables sTEST6 = Searchables(); //7 --- 
    sTEST6.set_searchables_name(" ");
    //TEST6.set_item();
    sTEST6.set_opening_description(" ");

    Searchables sTEST7 = Searchables(); //8 --- 
    sTEST7.set_searchables_name(" ");
   // TEST7.set_item();
    sTEST7.set_opening_description(" ");

    Searchables sTEST8 = Searchables(); //9 --- 
    sTEST8.set_searchables_name(" ");
    //TEST8.set_item();
    sTEST8.set_opening_description(" ");

    Searchables sTEST9 = Searchables(); //10 --- 
    sTEST9.set_searchables_name(" ");
    //TEST9.set_item();
    sTEST9.set_opening_description(" ");
    

    //Location Classes Here//
    
    // START OF INTRODUCTION LOCATIONS!
    Location lInFrontOfSquare = Location("In Front of St Peter's Square", "An open entrance leading up to the Square", "Eerily quiet, not another person in sight. The Popes situation must be serious if the public aren't allowed in.");
    Location lStPetersSquare = Location("St Peter's Square", "A huge open area surrounded by statues overlooking the square.", "The Obelisk in the center with fountains either side while being overlooked by St Peter's Basilica.");
    Location lObelisk = Location("Obelisk", "Vaticano, one of the thirteen Roman Obelisks.", "Enscribed on the Obelisk says: DIVO CAESARI DIVI F AVGVSTO TI CAESARI DIVI AVGVSTI F AVGVSTO SACRVM. If I remember my latin correctly, Sacred to the Divine Caesar Augustus, son of the Divine, to Tiberius Caesar Augustus, son of the Divine Augustus.");
    Location lLeftFountain = Location("Left Fountain", "The fountain to the left of the Obelisk.", "The Bernini Fountain");
    Location lRightFountain = Location("Right Fountain", "The fountain to the right of the Obelisk.", "The Maderno Fountain");
   
    Location lStPetersBasilicaEntrance = Location("St Peter's Basilica", "A monolithic structure that is the focal point of the Vatican", "St Peter's Basilica");
    Location lInsideBasilica = Location("Inside the Basilica", "You're inside the nave, surrounded by magnificent works of art and craftmanship.", "You see many enticing areas to look at. At the far end you see the caretaker standing infront of the Alter.");

    Location lPieta = Location("Pieta", "A Carrara marble sculpture of Jesus and Mary at Mount Golgotha representing the Sixth Sorrow of the Virgin Mary by Michelangelo.", "What an impressive sulpture, I wonder how long it took Michelangelo to craft.");
    Location lChoirChapel = Location("Choir Chapel", "The Cappella Giulia", "I wonder how the accustices of this building is like when the choir is here. Must be a magnificent display.");
    Location lNorthTransept = Location("North Transept", "The Sacrament of Reconciliation, the confession Transept", "I don't have any sins to confess, well none that I'd like to admit anyway.");
    Location lSouthTransept = Location("South Transept", "A smaller alter and many enpty pews infront", "This altar is the spot which is closest to where Peter the Apostle was crucified.");
    Location lApse = Location("Apse", "The Chair of St. Peter.", "Numerous scuptures surround the bronze Chair of St. Peter, what an incrediable sight to behold.");
    Location lStPetersAltar = Location("St Peter's Altar", "St.Peter's Baldachin is a large Baroque sculpted bronze canopy", "N/A");
       
    lInFrontOfSquare.set_pathway(lStPetersSquare);
    
    lStPetersSquare.set_pathway(lInFrontOfSquare);
    lStPetersSquare.set_pathway(lObelisk);
    lStPetersSquare.set_pathway(lLeftFountain);
    lStPetersSquare.set_pathway(lRightFountain);
    lStPetersSquare.set_pathway(lStPetersBasilicaEntrance);

    lObelisk.set_pathway(lStPetersSquare);

    lLeftFountain.set_pathway(lStPetersSquare);
    lLeftFountain.set_searchables_in_location(sLeftFountain);

    lRightFountain.set_pathway(lStPetersSquare);

    lStPetersBasilicaEntrance.set_pathway(lStPetersSquare);
    lStPetersBasilicaEntrance.set_pathway(lInsideBasilica);

    lInsideBasilica.set_pathway(lPieta);
    lInsideBasilica.set_pathway(lChoirChapel);
    lInsideBasilica.set_pathway(lNorthTransept);
    lInsideBasilica.set_pathway(lSouthTransept);
    lInsideBasilica.set_pathway(lApse);
    lInsideBasilica.set_pathway(lStPetersAltar);

    lPieta.set_pathway(lInsideBasilica);

    lChoirChapel.set_pathway(lInsideBasilica);

    lNorthTransept.set_pathway(lInsideBasilica);

    lSouthTransept.set_pathway(lInsideBasilica);

    lApse.set_pathway(lInsideBasilica);

    lStPetersAltar.set_pathway(lInsideBasilica);
    //END OF INTRODUCTION LOCATIONS

    //START OF DUNGEON LOCATIONS
    Location lHospitalRoom = Location("Hospital Room", "A room that looks and feels like an isolated hospital room.", "Theres a hospital bed, surgical equipment on a trolley, and a disturbing amount of blood all over the floor.");
    Location lStorageRoom = Location("Small Storage Room", "A room filled to the brim with boxes and junk.", "It's almost smells like a morgue, lets not think about that part");
    Location lHallway = Location("Dim Hallway", "A hallway with many connecting doors, some locked, some not.", "The ominous unlit chandeliers and the black pillers makes this hallway even less inviting.");
    Location lStudy = Location("Study", "A room with a desk and many many bookshelves.", "Everybook here is very well perserved, I don't even reconise most of these. They look ancient.");
    Location lFridge = Location("Walk-in Freezer", "A fridged room filled with bloodbags stretching along all the walls.", "All the blood bags are labled with different names, John, Sasha, Nick, Carol, Barry... Thats worrying.");
    Location lCoffinRoom = Location("Coffin Room", "A room with neatly stacked coffins leaning up against the back wall.", "None of the coffins open, but they each have different hand prints on them.");
    Location lShrine = Location("Shrine", "Cold dark room with a bronze statue of the current pope adorning the wall, alone.", "N/A");



    lHospitalRoom.set_pathway(lHallway);
    lHospitalRoom.set_pathway(lStorageRoom);
    lHospitalRoom.set_searchables_in_location(sMedicalTrolley);


    //lstoreageroom

    lHallway.set_location_path_is_blocked_by(oLockedDoor);

    //lstudy
    //put searchable 9 here

    //lfridge

    //lcoffinroom

    //lshirne

    //END OF DUNGEON LOCATIONS

    Location* curruntLocation = &lInFrontOfSquare;

    bool playing = true;
    int userInputNum = 0;
    int LoopIncrement = 0;
    //string userInputString = "abc";

   //Introduction section
   Globals::letter_by_letter_output("I've been called in specifically to help with the situation thats taking place at the Vatican. The Pope has fallen ill and requires help from the best medical professional, that would indeed be me, Barry", 1);
   Globals::enter_to_continue();
   Globals::letter_by_letter_output("Its currently 10pm, I'm unsure why they asked for me to wait for night to come and not ASAP, but the Pope probably has a busy schedule even when ill.", 1);
   Globals::enter_to_continue();
   Globals::letter_by_letter_output("As I approach the the entrance to the St Peters Square, I am approched by someone in a black suit, a butler maybe?", 1);
   Globals::enter_to_continue();
   Globals::letter_by_letter_output(caretaker.outputNextDiologue(), 1);
   Globals::enter_to_continue();
   Globals::letter_by_letter_output("I guess I can explore a little bit, its been many years since I last came here with my family.", 1);
   Globals::enter_to_continue();
   //End of Introduction Section

    //main game
    while (playing == true) {
        
        cout << "You are at --- " << curruntLocation->get_loc_name() << endl;       //Prints the location you are in
        cout << curruntLocation->get_loc_description() << endl;

        if (curruntLocation == &lStPetersAltar) {
            introductionsEnd(caretaker);
            curruntLocation = &lHospitalRoom;
        }
        else {
            cout << '\n' << "You can see these (Enter number to travel)" << endl;
            for (LoopIncrement = 0; LoopIncrement < curruntLocation->get_pathways().size(); LoopIncrement++) {
                cout << "[" << LoopIncrement << "] " << curruntLocation->get_pathways()[LoopIncrement]->get_loc_name() << endl;  //outputs the locations connected to the location you are in
            }
            cout << endl;
            cout << "[" << LoopIncrement << "] Inspect Current Location" << endl;    //option to search the area you are in
            cout << "[" << LoopIncrement + 1 << "] Search Area" << endl; //desplays the items in your inventory
            cout << "[" << LoopIncrement + 2 << "] Open Inventory" << endl; //desplays the items in your inventory
            cout << ">>>";
            Globals::clear_invalid_input(false);
            cin >> userInputNum;

            while (cin.fail()) { //check for input that is not a number
                cout << "Input a number" << endl;
                Globals::clear_invalid_input(false);
                cin >> userInputNum;
                while (userInputNum < 0 || userInputNum > LoopIncrement + 2) {  //checks for wrong input
                    cout << "Wrong input, try again!" << '\n' << ">>>";
                    Globals::clear_invalid_input(false);
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
            else if (userInputNum == LoopIncrement) {
                Globals::letter_by_letter_output(curruntLocation->get_loc_inspect_location(), 2); //output location inspection string
            }
            else if (userInputNum == LoopIncrement + 1) {
                curruntLocation->search_location(player);   //search location for items

            }
            else if (userInputNum == LoopIncrement + 2) {
                player.output_all_items_in_inventory(false);     //displays all inventory items to player

            }
        }        
    }
}

void introductionsEnd(NPC character) {
    cout << endl;
    Globals::clear_invalid_input(true);
    Globals::letter_by_letter_output("You approach St Peter's Alter where the caretaker is standing, lost in thought.", 1);
    Globals::enter_to_continue();
    Globals::letter_by_letter_output("Is now a good time?", 1);
    Globals::enter_to_continue();
    Globals::letter_by_letter_output(character.outputNextDiologue(), 1);
    Globals::enter_to_continue();
    Globals::letter_by_letter_output("Uh, thats not something I've thought about. It's not like the dead can get a tan.\n The caretaker frowns at you.\n Sorry, I was insensitive. I guess they would like to feel the light of God again.", 1);
    Globals::enter_to_continue();
    Globals::letter_by_letter_output(character.outputNextDiologue(), 1);
    Globals::enter_to_continue();
    Globals::letter_by_letter_output("Well of course too much sun is detrimental to your skin, but sun light provides vitamin d and...", 1);
    Globals::enter_to_continue();
    Globals::letter_by_letter_output(character.outputNextDiologue(), 1);
    Globals::enter_to_continue();
    Globals::letter_by_letter_output("The Caretaker grabs you with both arms with unweieldly strength and throws you down into the tomb below the alter.", 1);
    Globals::enter_to_continue();
    Globals::letter_by_letter_output("You hit your head hard when you reached the ground, darkness.", 1);
    Globals::enter_to_continue();
    Globals::letter_by_letter_output("You wake up, on the floor, in a daze, vision blurry, disoriented, your entire body aches like you've just been stabbed by a thousand tiny needles. You examine your where the aches are coming from and you notice multiple hole like scars.", 1);
    Globals::enter_to_continue();
    Globals::letter_by_letter_output("Please don't be what I think this could be... Shit it is isn't it. I've gotta find my way out of here.", 1);
    Globals::enter_to_continue();
}
