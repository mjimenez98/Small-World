//
// Created by Miguel Jimenez on 3/30/18.
//

#ifndef SMALL_WORLD_DEFAULTPLAYER_H
#define SMALL_WORLD_DEFAULTPLAYER_H

#include "../Dice/Dice.h"
#include "../FantasyRaceBanner/FantasyRaceBanner.h"
#include "../GameTurn/GameTurn.h"
#include "../Map/Map.h"
#include "../VictoryCoin/VictoryCoin.h"
#include "../../Patterns/Observer/Observer/Observer.h"
#include "../GameTurn/GameTurn.h"
#include "../../Patterns/Observer/Observer/Observer.h"
#include "../../Patterns/Observer/Decorator/HandObserver/HandObserver.h"
#include "../../Patterns/Observer/Decorator/GraphObserver/GraphObserver.h"
#include "../../Patterns/Observer/Decorator/CoinObserver/CoinObserver.h"

class PlayerBehavior {

public:
    virtual void picks_race(vector<FantasyRaceBanner>& raceBanners) = 0;
    virtual void conquer() = 0;
    virtual void scores() = 0;
    virtual void firstConquer() = 0;
    virtual void redeploy() = 0;
    virtual void playerTurn(vector<FantasyRaceBanner>& raceBanners) = 0;
    virtual void readyTroops() = 0;

};


#endif //SMALL_WORLD_DEFAULTPLAYER_H
