//
// Created by Miguel Jimenez on 5/7/18.
//

#ifndef SMALL_WORLD_DECORATOR_H
#define SMALL_WORLD_DECORATOR_H

#include "../Observer/Observer.h"

#include <iostream>
#include <iomanip>

using namespace std;

class Decorator : public Observer {

public:
    explicit Decorator(Observer * tempObs);

    void notifyAction(string action) override;
    void notifyPlayer(int playerNum) override;
    void notifyRegionsOwned(int regionsOwned) override;
    void notifyNumberOfPlayers(int numberOfPlayers) override;
    void notifyHand(string handNumber) override;
    void notifyCoins(int coins) override;

protected:
    Observer * obs;

};


#endif //SMALL_WORLD_DECORATOR_H
