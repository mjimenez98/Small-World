//
// Created by Miguel Jimenez on 5/7/18.
//

#ifndef SMALL_WORLD_OBSERVERINTERFACE_H
#define SMALL_WORLD_OBSERVERINTERFACE_H

#include <string>
#include <vector>

using namespace std;

class ObserverInterface {

public:
    virtual void notifyAction(string action) = 0;
    virtual void notifyPlayer(int playerNum) = 0;
    virtual void notifyRegionsOwned(int regionsOwned) = 0;
    virtual void notifyNumberOfPlayers(int numberOfPlayers) = 0;
    virtual void notifyHand(string hand) = 0;
    virtual void notifyCoins(int coins) = 0;

};


#endif //SMALL_WORLD_OBSERVERINTERFACE_H
