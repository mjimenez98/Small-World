//
// Created by Miguel Jimenez on 3/30/18.
//

#ifndef SMALL_WORLD_AGRESSIVE_H
#define SMALL_WORLD_AGRESSIVE_H

#include "../../Objects/Player/Player.h"

class Aggressive: public Player {

public:
    Aggressive():Player::Player(){};
    explicit Aggressive(Map* gameMap):Player::Player(gameMap){};

    void picks_race(vector<FantasyRaceBanner>& availableBanners) override;
    void conquer() override;
    void scores() override;

};


#endif //SMALL_WORLD_AGRESSIVE_H
