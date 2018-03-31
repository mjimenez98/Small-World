//
// Created by Miguel Jimenez on 3/30/18.
//

#ifndef SMALL_WORLD_RANDOM_H
#define SMALL_WORLD_RANDOM_H

#include "../../Objects/Player/Player.h"

class Random: public Player {

public:
    Random():Player::Player(){};
    explicit Random(Map* gameMap):Player::Player(gameMap){};

    void picks_race(vector<FantasyRaceBanner>& availableBanners) override;
    void conquer() override;
    void scores() override;

};


#endif //SMALL_WORLD_RANDOM_H
