//
// Created by Miguel Jimenez on 3/30/18.
//

#ifndef SMALL_WORLD_MODERATE_H
#define SMALL_WORLD_MODERATE_H

#include "../../Objects/Player/Player.h"

class Moderate: public Player {

public:
    Moderate():Player::Player(){};
    explicit Moderate(Map* gameMap):Player::Player(gameMap){};

    void picks_race(vector<FantasyRaceBanner>& availableBanners) override;
    void conquer() override;
    void scores() override;

};


#endif //SMALL_WORLD_MODERATE_H
