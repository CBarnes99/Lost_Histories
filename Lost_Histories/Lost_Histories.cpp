#include <iostream>
#include "Item.h"
#include "Location.h"
#include "Obstacle.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    Item rustyKey = Item("Rusty Key", "Big rust", rustyDoor);

    Obstacle rustyDoor = Obstacle("Rusty Door", "Big Rusty Door", rustyKey, "Maybe rusty key hmmm");

    Location room = Location("Room", "Big room", "Dark room", "looks like a big room", true, Item("key", "rusty", Obstacle("rusty door", "big rusty door", "key", "look for a rusty key"));

}

