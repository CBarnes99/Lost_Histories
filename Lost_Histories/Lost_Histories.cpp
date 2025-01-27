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

        Create Obstacles

        Create Items and link the obstale to them

        Create location and link item and obstacle
    */


    Player player = Player();
    player.setPlayerName("Steve");


    Item testItem = Item();
    testItem.set_Item_Defaults("testItem", "Is a test");


    Obstacle testObs = Obstacle("Wall", "Big wall", "The wall seems to be cracked, with a hard enough hit, it might crumble");


    Location Hall = Location("Hall", "Long Hall", "Its too dark to see", "Hallway", true, testItem, "You see a test thing", false, "Null");

    Location hall2 = Location("a", "b", "cant see shit", "far away", false, testItem, "Test item here", false, "NULL");

    hall2.add_Pathway(Hall);

    hall2.get_Pathways();



}

