//
// Created by Miguel Jimenez on 3/30/18.
//
/*
 * A moderate player knows when to place the race in decline, which likely ends its hold on the
 * board, but paves the way for his/her control of another race to renew his/her conquests.
 * (e.g. unless the player's first pick is Ghouls, whose race ability allows him/her to control them as if
 * they were active even though they’re in decline and should go in decline on the second turn,
 * he/she would want to spend two or three turns with him/her first race)
 */

#ifndef SMALL_WORLD_MODERATE_H
#define SMALL_WORLD_MODERATE_H

#include "../../Objects/Player/Player.h"

class Moderate: public Player {

public:
    Moderate():Player::Player(){};
    explicit Moderate(Map* gameMap):Player::Player(gameMap){};

    void picks_race(vector<FantasyRaceBanner>& availableBanners) override;
    void conquer() override;
    void firstConquer() override;
    void redeploy() override;
    void playerTurn(vector<FantasyRaceBanner>& raceBanners) override;

private:
    int gameTurn; //TEMP

};


#endif //SMALL_WORLD_MODERATE_H
