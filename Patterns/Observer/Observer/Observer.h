//
// Created by Jean-Loup on 2018-03-20.
//

#ifndef SMALL_WORLD_OBSERVER_H
#define SMALL_WORLD_OBSERVER_H

#include "ObserverInterface.h"

using namespace std;

//concrete basic Observer
class Observer: public ObserverInterface {

public:
    void notifyAction(string action) override;
    void notifyPlayer(int playerNum) override;
    void notifyRegionsOwned(int regionsOwned) override;
    void notifyNumberOfPlayers(int numberOfPlayers) override;
    void notifyHand(string hand) override;
    void notifyCoins(int coins) override;


    //Current player
    static int playerNumber;
    static int numberOfPlayers;
    static int numberOfRegions;

    //number of regions owned by each player
    static int regions1;
    static int regions2;
    static int regions3;
    static int regions4;
    static int regions5;

    static vector<string> playerhands;
    static vector<int> playerCoins;

};

#endif //SMALL_WORLD_OBSERVER_H