//
// Created by Miguel Jimenez on 2/6/18.
//

#ifndef SMALL_WORLD_BADGE_H
#define SMALL_WORLD_BADGE_H

#include <string>

using namespace std;

class Badge {

public:
    Badge(string newType, int newNumOfCoins);
    void activateSpecialPower();
    void giveCoinsToPlayer();

private:
    string type;
    int numOfCoins;

};

#endif //SMALL_WORLD_BADGE_H
