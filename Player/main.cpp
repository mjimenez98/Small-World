//
// Created by Miguel Jimenez on 2/4/18.
//

#include "Player.h"
#include <iostream>

using namespace std;

int main() {

    /* This main creates a player, allows them to pick a race, place their tokens on three regions and receive their
     * victory coins */

    Map m1 = loadMap("../textMaps/2Players.txt");
    Map* map = &m1;

    Player p1 = Player();

    p1.picks_race();
    p1.firstConquer(map);
    p1.scores();

    cout << p1.toString();

    return 0;
};