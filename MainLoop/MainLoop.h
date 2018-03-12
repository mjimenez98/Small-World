//
// Created by Jean-Loup on 2018-03-09.
//

#ifndef SMALL_WORLD_MAINLOOP_H
#define SMALL_WORLD_MAINLOOP_H

#include <iostream>
#include "../Player/Player.h"


using namespace std;

class MainLoop {

public:
    MainLoop();
    MainLoop(Player* p1,Player* p2);
    MainLoop(Player* p1,Player* p2,Player * p3);
    MainLoop(Player* p1,Player* p2,Player * p3,Player * p4);
    MainLoop(Player* p1,Player* p2,Player * p3,Player * p4,Player*p5);
    void playGameTest();
    void playGame(vector<FantasyRaceBanner>& raceBanners);


private:
    int numberOfPlayers;
    int numberOfTurns ;
    Player * player1;
    Player * player2;
    Player * player3;
    Player * player4;
    Player * player5;
};


#endif //SMALL_WORLD_MAINLOOP_H