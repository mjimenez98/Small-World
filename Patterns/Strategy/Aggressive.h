//
// Created by Miguel Jimenez on 3/30/18.
//
/*
 * An aggressive player who expands his/her empire and then hold onto everything he/she got until the
 * end of the game. That is expand to as many regions as quickly as he/she can, the player doesn’t fear
 * enemy races counter attacking and destroying his/her gains.
 */

#ifndef SMALL_WORLD_AGRESSIVE_H
#define SMALL_WORLD_AGRESSIVE_H

#include "../../Objects/Player/Player.h"

class Aggressive: public Player {

public:
    Aggressive():Player::Player(){};
    explicit Aggressive(Map* gameMap):Player::Player(gameMap){};

    void picks_race(vector<FantasyRaceBanner>& availableBanners) override;
    void conquer() override;
    void firstConquer() override;
    void redeploy() override;
    void playerTurn(vector<FantasyRaceBanner>& raceBanners) override;

};


#endif //SMALL_WORLD_AGRESSIVE_H
