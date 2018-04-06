//
// Created by Miguel Jimenez on 3/30/18.
//
/*
 * A defensive player is constantly looking to dismantle the opponent(s) empire: wants a slow, well-defended advance.
 */


#ifndef SMALL_WORLD_DEFENSIVE_H
#define SMALL_WORLD_DEFENSIVE_H

#include "../../Objects/Player/Player.h"

class Defensive: public Player {

public:
    Defensive():Player::Player(){};
    explicit Defensive(Map* gameMap):Player::Player(gameMap){};

    void picks_race(vector<FantasyRaceBanner>& availableBanners) override;
    void conquer() override;
    void firstConquer() override;
    void redeploy() override;
    void playerTurn(vector<FantasyRaceBanner>& raceBanners) override;
    void readyTroops() override;

private:
    int gameTurn; //TEMP

};


#endif //SMALL_WORLD_DEFENSIVE_H
