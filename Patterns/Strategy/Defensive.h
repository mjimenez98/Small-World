//
// Created by Miguel Jimenez on 3/30/18.
//

#ifndef SMALL_WORLD_DEFENSIVE_H
#define SMALL_WORLD_DEFENSIVE_H

#include "../../Objects/Player/Player.h"

class Defensive: public Player {

public:
    Defensive():Player::Player(){};
    explicit Defensive(Map* gameMap):Player::Player(gameMap){};

    void picks_race(vector<FantasyRaceBanner>& availableBanners) override;
    void conquer() override;
    void scores() override;

};


#endif //SMALL_WORLD_DEFENSIVE_H
