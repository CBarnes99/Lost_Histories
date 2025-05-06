#include <iostream>
#include "Item.h"
#include "Location.h"
#include "Obstacle.h"
#include "Player.h"
#include "Global_Functions.h"
#include "NPC.h"


#include "stdlib.h"

bool storyDiologue(NPC character, int part);

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
        if item in locationx`, set_searchable_in_location()
        if this location is blocked by obstacle, set_location_path_is_blocked_by()
        to link path to other locations, set_pathway()

    */
    //Player Class Here//
    Player player = Player("Barry");

    //NPC Classes Here//
    NPC caretaker = NPC("Caretaker");
    caretaker.addDiologue("Thank you for coming on such short notice, " + player.get_character_name() + ". I am the caretaker of the Basilica. The pope is currenlty occupied but he'll be ready for you in a moment. I'll wait for you inside the Basilica.");
    caretaker.addDiologue("The Pope is still occupied, but let me ask you this, when you look at the Baldachin knowing its protecting St Peters Tomb from the light above, how does that make you feel?");
    caretaker.addDiologue("Ignoring the first remark, I like your answer. But what if I told you the light of God isn't always the best thing for us.");
    caretaker.addDiologue("The Caretaker shaking his head in frustration. No no no, will you shut up! You simply don't get it, they CANT take in Gods rays, because, nevermind, you'll find you soon enough.");

    NPC pope = NPC("The Pope");
    pope.addDiologue("Welcome, glad you can make it. You've seemed to of made yourself at home.");
    pope.addDiologue("All will be answered in due time little lamb, but first, sit.");
    pope.addDiologue("You're here to see me, yes? To help me, yes?");
    pope.addDiologue("Of course I didn't " + player.get_character_name() + ", you are excatly who I needed for this important task. *The Pope bares his fangs towards you*");
    pope.addDiologue("Oh sorry, these fangs are not for you. Well depending on what you decided to do next. I'm going to need you to drink from this chalice.");
    pope.addDiologue("This is the Holy Grail, yes the one and only.");
    pope.addDiologue("Well I was expecting more of a reaction than that. Anyway, the rich deep red liquid it holds is the blood of Christ, he too was a vampire, and now you will continue the lineage.");
    pope.addDiologue("Watch your language.");
    pope.addDiologue("So, are you going to drink or not?");

    //Item Classes Here// 
    Item iCoin = Item(); //In sLeftFountain, Opens ???????????????????????????
    iCoin.set_item_defaults("A Gold Coin", "An Aureus Gold Coin, definitly not real but it looks cool", 1);
    iCoin.set_item_destroyed_text("-----------------------------------------------------");

    Item iBloodstainedKey = Item(); //In sMedicalTrolley, Opens oLockedBloodstainedDoor 
    iBloodstainedKey.set_item_defaults("Bloodstained Key", "A key that is coated in blood.", 2);

    Item iHammer = Item(); //In sCabinet, Opens oSmallWoodenCrate
    iHammer.set_item_defaults("Small Hammer", "A hammer is only real use is smashing things. Now what do I smash.", 5);
    iHammer.set_item_destroyed_text("After that final swing, the hammers head snapped off the shaft.");

    Item iBronzeKey = Item(); //In sSmallWoodenCrate, Opens oBronzeDoor
    iBronzeKey.set_item_defaults("Bronze Key", "A Bronze Key, it has loads of scratches, must be used often.", 2);

    Item iCombinationLockNote = Item(); //In sDesk, Opens oChestOfDrawers
    iCombinationLockNote.set_item_defaults("A four digit note", "It's just a note with four numbers, what could these mean?", 2);

    Item iNote = Item(); //In sChestOfDrawers, Opens oBloodBagNick
    iNote.set_item_defaults("A Note", "A medical note with alot of information about this one person called Nick, is this even useful?", 2);

    Item iSilverKey = Item(); //in sDesk, Opens oSilverDoor
    iSilverKey.set_item_defaults("Silver Key", "A Silver Key in near pristine condition, must unlock to something valuable", 2);

    Item iBloodBagNick = Item(); //in sBloodBagNick, Opens oGiantContainer
    iBloodBagNick.set_item_defaults("Nick's Blood Bag", "A huge blood bag with a label names Nick. You notice there might be more than blood in this bag", 1);
    iBloodBagNick.set_item_destroyed_text("You discard the bag after pouring it out into the container.");

    Item iNickHand = Item(); //in s, Opens oChest
    iNickHand.set_item_defaults("A hand", "The right hand possibly belonging to someone called Nick.", 1);
    iNickHand.set_item_destroyed_text("The hand gets absorbed into the coffin when you pressed it against the hand print.");

    Item iNicksEye = Item(); //in sNickCoffin, Opens oChest
    iNicksEye.set_item_defaults("Eye Ball", "You took this eye that was hanging out of the corpse, lovely.", 1);
    iNicksEye.set_item_destroyed_text("The eye becomes fused with the chest, unable to remove it.");

    Item iGoldKey = Item(); //in sChest, Opens oGoldDoor
    iGoldKey.set_item_defaults("Gold Key", "A golden key, if I get out of here, im going to melt this down.", 2);


    //Obstacle Classes Here//
    Obstacle oLockedBloodstainedDoor = Obstacle(); //iBloodstainedKey to open, For entering the lHallway from lHospitalRoom
    oLockedBloodstainedDoor.set_obstacle_defualts("Bloodstained Door", "The Bloodstained Door wont budge, need to get past it somehow", "The locked door is covered in fresh blood.", iBloodstainedKey.get_item_name(), "You put the key through the blood soaked keyhole and gently push open the door trying to avoid the blood with your hand.");

    Obstacle oChestOfDrawers = Obstacle(); //iCombinationLockNote to open, For sChestOfDrawers in lHospitalRoom
    oChestOfDrawers.set_obstacle_defualts("Chest of Drawers", "The draws won't budge, but one of the them has a four digit combination lock", "One of the draws has a combination lock, there must be a code for it somewhere.", iCombinationLockNote.get_item_name(), "You input the digits from the notes onto the lock. *Click*.");

    Obstacle oSmallWoodenCrate = Obstacle(); //iHammer to open, For opening sSmallWoodenCrate in lStorageRoom
    oSmallWoodenCrate.set_obstacle_defualts("Small Wodden Crate", "The crate is covered in rot and mold, probably for the best not to touch it", "Small rotting wodden crate, probably easily broken open with something.", iHammer.get_item_name(), "You smashed the top of the crate into tiny pieces and can now see inside the crate.");
    
    Obstacle oGiantContainer = Obstacle(); //iBloodBagNick to Open, For sTableWithAGiantContainer in lStorageRoom
    oGiantContainer.set_obstacle_defualts("A Table with a Giant Glass Container", "The Table is surrounded with junk, it's not worth digging it out until I might have a reason to", "Its just a giant glass container.", iBloodBagNick.get_item_name(), "You clear out the junk around the table making sure not to break the container. You pour the blood bag into the container. You notice that its not just blood in the bag, something else is floating around.");

    Obstacle oBronzeDoor = Obstacle(); //iBronzeKey to open, For entering lFreezer from lHallway
    oBronzeDoor.set_obstacle_defualts("Bronze Trimmed Door", "The door has a Bronze trim around the edge of the door", "Theres a bronze lock on the door.", iBronzeKey.get_item_name(), "You used the Bronze Key to open the door.");
    
    Obstacle oSilverDoor = Obstacle(); //iSilverKey to Open, For entering Coffin Room from lHallway
    oSilverDoor.set_obstacle_defualts("Silver Trimmed Door", "The door has a Silver trim around the edge of the door", "Theres a Silver lock on the door.", iSilverKey.get_item_name(), "You used the Silver Key to open the door.");

    Obstacle oBloodBagNick = Obstacle(); //iNote to Open, For sBloodBagNick in lFreezer  //////////////create multiple for the other names
    oBloodBagNick.set_obstacle_defualts("Blood Bag", "Blood Bag with the name Nick on the Label", "Why would this one be more useful then the rest, might need more information.", iNote.get_item_name() , "You take this blood bag due to the note, lets hope this helps somehow.");

    Obstacle oCoffinHand = Obstacle(); //iNickHand to Open, for sNickCoffin in lCoffinRoom  /////////////////Create multiple
    oCoffinHand.set_obstacle_defualts("Coffin", "The Coffin doesn't have an openable lid, it's just marked with a hand print in the center.", "Theres no way to lift open the coffin, its sealed shut.", iNickHand.get_item_name(), "You placed the hand onto the coffin, blood starts spewing out from the seams the and lid starts sliding off, reavaling a corpse.");

    Obstacle oChest = Obstacle(); //iNicksEye to Open, for sChest in lStudy
    oChest.set_obstacle_defualts("Small Chest", "The Small Chest lid wont budge, there's not a lock on it either", "Theres no keyhole for the chest, just a spherical bloodied socket on top.", iNicksEye.get_item_name(), "You place the eye into the socket, blood stars spewing out from the cracks in the chest, the lid opens.");

    Obstacle oGoldDoor = Obstacle(); //iGoldKey to Open, For entering Shrine from Hallway
    oGoldDoor.set_obstacle_defualts("Gold Trimmed Door", "The door has a Gold trim around the edge of the door", "Theres a gold lock on the door.", iGoldKey.get_item_name(), "You used the Gold Key to open the door.");

    //Searchables Classes Here//
    Searchables sLeftFountain = Searchables(); //In lLeftFountain, Not Blocked, Gain iCoin, 
    sLeftFountain.set_searchables_name("The Bernini Fountain");
    sLeftFountain.set_item(iCoin);
    sLeftFountain.set_opening_description("You reach in to the fountains water.");

    Searchables sMedicalTrolley = Searchables(); //In lHospitalRoom, Not Blocked, Gain iBloodstainedKey
    sMedicalTrolley.set_searchables_name("Medical Trolley");
    sMedicalTrolley.set_item(iBloodstainedKey);
    sMedicalTrolley.set_opening_description("You open the draw on the trolley.");

    Searchables sChestOfDrawers = Searchables(); //In lHospitalRoom, Blocked by oChestOfDrawers, Gain iNote
    sChestOfDrawers.set_searchables_name("Chest of Drawers");
    sChestOfDrawers.set_item(iNote);
    sChestOfDrawers.set_opening_description("You open the draw.");
    sChestOfDrawers.set_obstacle(&oChestOfDrawers);

    Searchables sSmallWoodenCrate = Searchables(); //In lStorageRoom, Blocked by oSmallWoodenCrate, Gain iBronzeKey
    sSmallWoodenCrate.set_searchables_name("Small Wooden Crate");
    sSmallWoodenCrate.set_item(iBronzeKey);
    sSmallWoodenCrate.set_opening_description("You peer into the smashed crate.");
    sSmallWoodenCrate.set_obstacle(&oSmallWoodenCrate);

    Searchables sTableWithAGiantContainer = Searchables(); //In lStorageRoom, Blocked by oGiantContainer, Gain iNickHand
    sTableWithAGiantContainer.set_searchables_name("Table with a Giant Container");
    sTableWithAGiantContainer.set_obstacle(&oGiantContainer);
    sTableWithAGiantContainer.set_item(iNickHand);
    sTableWithAGiantContainer.set_opening_description("You poor the blood back into the container, you notice theres more than just blood in the bag. You see a hand. You can only assume its the hand that belongs to Nick.");

    Searchables sCabinet = Searchables(); //In lHallway, Not Blocked, Gain iHammer
    sCabinet.set_searchables_name("Brown Cabinet");
    sCabinet.set_item(iHammer);
    sCabinet.set_opening_description("You open the two stiff doors gently hoping nothing jumps out.");

    Searchables sDesk = Searchables(); //In lStudy, Not Blocked, Gain iCombinationLockNote
    sDesk.set_searchables_name("Large Wooden Desk");
    sDesk.set_item(iCombinationLockNote);
    sDesk.set_opening_description("You search through the couple of draws in the desk.");

    Searchables sChest = Searchables(); //In lStudy, Blocked, Gain iNicksEye
    sChest.set_searchables_name("Small Chest");
    sChest.set_item(iGoldKey);
    sChest.set_opening_description("The chests lid slides off now the eye has been placed.");
    sChest.set_obstacle(&oChest);

    Searchables sBookshelf = Searchables(); //In lStudy, Not Blocked, Gain iSilverKey     Create multiple
    sBookshelf.set_searchables_name("Bookshelf");
    sBookshelf.set_item(iSilverKey);
    sBookshelf.set_opening_description("You start skimming through the books hoping to find something, anything in the books. A note, anything. As you start throwing the books, one opens on the floor to reveal a secret compartment with something inside.");   

    Searchables sBloodBagNick = Searchables(); //In lFreezer, Blocked, Gain iBloodBagNick           Create Multiple John, Sasha, Nick, Carol, Barry
    sBloodBagNick.set_searchables_name("Huge Blood Bag with the name Nick writen on the label.");
    sBloodBagNick.set_item(iBloodBagNick);
    sBloodBagNick.set_opening_description("You take the Blood Bag");
    sBloodBagNick.set_obstacle(&oBloodBagNick);

    Searchables sNickCoffin = Searchables(); //In lCoffingRoom, Blocked by iNickHand, Gain iNicksEye --------------Create Multiple
    sNickCoffin.set_searchables_name("Coffin with bloodied handprint.");
    sNickCoffin.set_item(iNicksEye);
    sNickCoffin.set_opening_description("You move the lid now that its open.");
    sNickCoffin.set_obstacle(&oCoffinHand);
    

    //Location Classes Here//
    
    // START OF INTRODUCTION LOCATIONS!
    Location lInFrontOfSquare = Location("In Front of St Peter's Square", "An open entrance leading up to the Square.", "Eerily quiet, not another person in sight. The Popes situation must be serious if the public aren't allowed in.");
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
    Location lStorageRoom = Location("Small Storage Room", "A room filled to the brim with boxes and junk.", "It's almost smells like a morgue, lets not think about that part.");
    Location lHallway = Location("Hallway", "A hallway with many connecting doors, some locked, some not.", "The ominous unlit chandeliers and the black pillers makes this hallway even less inviting.");
    Location lStudy = Location("Study", "A room with a desk and many many bookshelves.", "Every book here is very well perserved, I don't even recognise most of these. They look ancient.");
    Location lFreezer = Location("Walk-in Freezer", "A fridged room filled with bloodbags stretching along all the walls.", "All the blood bags are labled with different names, John, Sasha, Nick, Carol, Barry... Thats worrying.");
    Location lCoffinRoom = Location("Coffin Room", "A room with neatly stacked coffins leaning up against the back wall.", "None of the coffins open, but they each have different hand prints on them.");
    Location lShrine = Location("Shrine", "Cold dark room with a bronze statue of the current pope adorning the wall, alone.", "How did the Pope get lifted and die? And why? I'm suddenly more worried about that than the whole vamipire shenanigans.");
    Location lShrineExit = Location("Hidden Door", "N/A", "N/A");

    lHospitalRoom.set_pathway(lHallway);
    lHospitalRoom.set_pathway(lStorageRoom);
    lHospitalRoom.set_searchables_in_location(sMedicalTrolley);
    lHospitalRoom.set_searchables_in_location(sChestOfDrawers);

    lStorageRoom.set_pathway(lHospitalRoom);
    lStorageRoom.set_searchables_in_location(sSmallWoodenCrate);
    lStorageRoom.set_searchables_in_location(sTableWithAGiantContainer);

    lHallway.set_pathway(lHospitalRoom);
    lHallway.set_pathway(lCoffinRoom);
    lHallway.set_pathway(lStudy);
    lHallway.set_pathway(lFreezer);
    lHallway.set_pathway(lShrine);
    lHallway.set_location_path_is_blocked_by(oLockedBloodstainedDoor);
    lHallway.set_searchables_in_location(sCabinet);

    lStudy.set_pathway(lHallway);
    lStudy.set_searchables_in_location(sBookshelf);
    lStudy.set_searchables_in_location(sChest);
    lStudy.set_searchables_in_location(sDesk);

    lFreezer.set_pathway(lHallway);
    lFreezer.set_location_path_is_blocked_by(oBronzeDoor);
    lFreezer.set_searchables_in_location(sBloodBagNick);

    lCoffinRoom.set_pathway(lHallway);
    lCoffinRoom.set_location_path_is_blocked_by(oSilverDoor);
    lCoffinRoom.set_searchables_in_location(sNickCoffin);

    lShrine.set_pathway(lHallway);
    lShrine.set_pathway(lShrineExit);
    lShrine.set_location_path_is_blocked_by(oGoldDoor);

    //END OF DUNGEON LOCATIONS

    Location* curruntLocation = &lInFrontOfSquare;

    //////////Location* curruntLocation = &lHallway;

    bool playing = true;
    int userInputNum = 0;
    int LoopIncrement = 0;
    bool beenToShrine = false;

 
   std::cout << " _______  _        _______ _________ _______  _       _________   ______   _        _______  _______  ______" << std::endl;
   std::cout << "(  ___  )( (    /|(  ____  \\__   __/(  ____ \\( (    /|\\__   __/  (  ___ \\ ( \\      (  ___  )(  ___  )(  __  \\" << std::endl;
   std::cout << "| (   ) ||  \\  ( || (    \\/   ) (   | (    \\/|  \\  ( |   ) (     | (   ) )| (      | (   ) || (   ) || (  \\  )" << std::endl;
   std::cout << "| (___) ||   \\ | || |         | |   | (__    |   \\ | |   | |     | (__/ / | |      | |   | || |   | || |   ) |" << std::endl;
   std::cout << "|  ___  || (\\ \\) || |         | |   |  __)   | (\\ \\) |   | |     |  __ (  | |      | |   | || |   | || |   | |" << std::endl;
   std::cout << "| (   ) || | \\   || |         | |   | (      | | \\   |   | |     | (  \\ \\ | |      | |   | || |   | || |   ) |" << std::endl;
   std::cout << "| )   ( || )  \\  || (____/\\___) (___| (____/\\| )  \\  |   | |     | )___) )| (____/\\| (___) || (___) || (__/  )" << std::endl;
   std::cout << "|/     \\||/    )_)(_______/\\_______/(_______/|/    )_)   )_(     |/ \\___/ (_______/(_______)(_______)(______/ " << std::endl;
                                                                                                              
   Globals::enter_to_continue();


   //Introduction section
   Globals::letter_by_letter_output("I've been called in specifically to help with the situation thats taking place at the Vatican. The Pope has fallen ill and requires help from the best medical professional, that would indeed be me, Barry.", 1);
   Globals::enter_to_continue();
   Globals::letter_by_letter_output("Its currently 10pm, I'm unsure why they asked for me to wait for night to come and not ASAP, but the Pope probably has a busy schedule even when ill.", 1);
   Globals::enter_to_continue();
   Globals::letter_by_letter_output("As I approach the the entrance to the St Peters Square, I am approched by someone in a black suit, a butler maybe?", 1);
   Globals::enter_to_continue();
   Globals::letter_by_letter_output(caretaker.getNextDiologue(), 1);//caretaker
   Globals::enter_to_continue();
   Globals::letter_by_letter_output("I guess I can explore a little bit, its been many years since I last came here with my family.", 1);
   Globals::enter_to_continue();
   //End of Introduction Section

    //main game
    while (playing == true) {
        
        cout << "You are at --- " << curruntLocation->get_loc_name() << endl;       //Prints the location you are in
        cout << curruntLocation->get_loc_description() << endl;

        if (curruntLocation == &lStPetersAltar) {
            system("cls");
            playing = storyDiologue(caretaker, 1);
            curruntLocation = &lHospitalRoom;
        }
        else if (curruntLocation == &lShrine && beenToShrine == false) {
            system("cls");
            playing = storyDiologue(pope, 2);
            beenToShrine = true;
            
        }
        else if (curruntLocation == &lShrineExit) {
            system("cls");
            playing = storyDiologue(pope, 3);
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
                curruntLocation->search_location(player);   //search location for searchables
            }
            else if (userInputNum == LoopIncrement + 2) {
                player.output_all_items_in_inventory(false);     //displays all inventory items to player
            }
        }        
    }

    Globals::letter_by_letter_output("Thanks for Playing!", 2);
}

bool storyDiologue(NPC character, int part) {
    
    Globals::clear_invalid_input(true);

    if (part == 1) {
        Globals::letter_by_letter_output("You approach St Peter's Alter where the caretaker is standing, lost in thought.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("Is now a good time?", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output(character.getNextDiologue(), 1);//caretajer
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("Uh, thats not something I've thought about. It's not like the dead can get a tan.\n The caretaker frowns at you.\n Sorry, I was insensitive. I guess they would like to feel the light of God again.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output(character.getNextDiologue(), 1);//caretaker
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("Well of course too much sun is detrimental to your skin, but sun light provides vitamin D and", 2);
        Globals::letter_by_letter_output(character.getNextDiologue(), 1);//caretaker
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("The Caretaker grabs you with both arms with unweieldly strength and throws you down into the tomb below the alter.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("You hit your head hard when you reached the ground, darkness.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("You wake up, on the floor, in a daze, vision blurry, disoriented, your entire body aches like you've just been stabbed by a thousand tiny needles. You examine where the aches are coming from and you notice multiple hole like scars.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("Please don't be what I think this could be... Shit it is isn't it. I've gotta find my way out of here.", 1);
        Globals::enter_to_continue();

        return true;

    }
    else if (part == 2) {
        Globals::letter_by_letter_output("As you open the door into the shrine, the door creeks open. You notice a small dining table with two chairs in the center of the room, adorning the wall is a bronze statue of the current pope.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("You step into the room, a chill moves up your spine and you hear the floor boards creek.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("A man wearing a pure white robe, slowly steps closer towards you being lit by candles scattered across the floor.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("As he gets closer, you notice they are the reason why you are here in the first place, the Pope.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output(character.getNextDiologue(), 1);//pope
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("What the heck is happening, why did I get pushed down here?! What even is here?!", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output(character.getNextDiologue(), 1);//pope
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("You slowly make your way towards the table and take a seat, your legs are slightly trembling.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output(character.getNextDiologue(), 1); // pope
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("I think you've got the wrong person, I think I should leave.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output(character.getNextDiologue(), 1); //pope
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("You're too frightened to respond.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output(character.getNextDiologue(), 1);//pope
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("The Pope brings out a chalice, plated gold and coated in gems.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output(character.getNextDiologue(), 1); // pope
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("You stay in silence.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output(character.getNextDiologue(), 1); //pope
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("Wait what? One, why would I believe any of this? And two, God no.", 1);
        Globals::letter_by_letter_output(character.getNextDiologue(), 1); // pope
        Globals::letter_by_letter_output("Oh sorry father.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output(character.getNextDiologue(), 1); // pope
        Globals::letter_by_letter_output("*The Pope slides the Holy Grail towards you*", 2); 

        Globals::sleep(100);
        Globals::letter_by_letter_output("Y or N", 1);
        Globals::clear_invalid_input(false);
        std::string playerAnswerString;
        std::cin >> playerAnswerString;

        Globals::clear_invalid_input(true);
        system("cls");

        if (playerAnswerString == "y" || playerAnswerString == "Y") {
            Globals::letter_by_letter_output("You've decided to drink from the Holy Grail.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("As you drink the viscous blood, you initially don't feel any difference. Soon after you look back down at the chalice in your hand thirsting for more, but its already gone.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("The Pope: Can't have you drinking all of this now can we.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("I feel like I've got all the energy in the world and the thirst of a thousand elephants.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("The Pope: Dont worry, we all started like that.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("I thought this, this transformation would be more painful.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("The Pope: I know right! *The pope chuckles* Surpirsingly pain free. Anyway, lets get you some grub, Pope Barry.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("You leave the shrine with your new found power and friend, going for a hunt.", 1);
            Globals::enter_to_continue();
            return false;
        }
        else {
            Globals::letter_by_letter_output("You slap the Holy Grail off the table as hard as you can, the grail shatters as it hits the floor and the blood is spilled into the cracks of the floor.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("The Pope: NOOOOOOO! WHAT DID YOU DO!!", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("You jump back from your seat as the Pope lunges towards the spilled blood on the floor licking up what little remains.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("The Pope realises what he's just done, he's enduldging in the sacred blood. Stopping for a second knowing the sin he just committed, he continues licking the blood waiting for his fate.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("You take this moment to back away towards the door but, you see the pope somehow being lifted by an invisible force by the neck until hes floating and grasping for air.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("???: A sin committed, a death is granted.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("The Pope: This, is, your, fau..lt.", 1);
            Globals::enter_to_continue();
            Globals::letter_by_letter_output("You hear a snap and the Pope falls lifelessly to the ground with a thud.", 1);
            Globals::enter_to_continue();

            system("cls");
            system("start https://www.bbc.co.uk/news/articles/cqj42vd1rxlo");
            Globals::enter_to_continue();

            Globals::letter_by_letter_output("In shock, you start to make your way towards the entrance. Before you turn around, you notice at the other end of the room theres a door. Knowing where you came in is a dead end, what could go wrong?", 1);
            Globals::enter_to_continue();

            return true;
        }
    }
    else if (part == 3){
        Globals::letter_by_letter_output("As you open the door, you step through and notice that it leads to the back of the vatican.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("You take your time to look around making sure nothing else is going to leap to you... You make a run for it.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("You ran as fast as you can until you found civilization, called a taxi and gunned it for the airport.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("I think its time for an early retirement when I get back home, that was enough for me.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("The taxi driver looks in to the rear view mirror directly at you, his eyes turn pitch black.", 1);
        Globals::enter_to_continue();
        Globals::letter_by_letter_output("???: You've committed a grave sin...", 1);
        Globals::enter_to_continue();

        return false;
    }
    else {
        std::cout << "STORY DIOLOGUE NOT WORKING" << std::endl;
        return true;
    }
}