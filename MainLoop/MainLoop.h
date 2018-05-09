//
// Created by Jean-Loup on 2018-03-09.
//

#ifndef SMALL_WORLD_MAINLOOP_H
#define SMALL_WORLD_MAINLOOP_H

#include <iostream>
#include "../Objects/Player/Player.h"

using namespace std;

class MainLoop {

public:
    MainLoop(Player* p1,Player* p2, vector<FantasyRaceBanner>& raceBanners);
    MainLoop(Player* p1,Player* p2,Player * p3, vector<FantasyRaceBanner>& raceBanners);
    MainLoop(Player* p1,Player* p2,Player * p3,Player * p4, vector<FantasyRaceBanner>& raceBanners);
    MainLoop(Player* p1,Player* p2,Player * p3,Player * p4,Player*p5, vector<FantasyRaceBanner>& raceBanners);
    void playGame(vector<FantasyRaceBanner>& raceBanners);
    void declareWinner();

private:
    int numberOfPlayers;
    int numberOfTurns;
    Player * player1;
    Player * player2;
    Player * player3;
    Player * player4;
    Player * player5;

};


#endif //SMALL_WORLD_MAINLOOP_H