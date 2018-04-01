//
// Created by Jean-Loup on 2018-03-09.
//

#include "MainLoop.h"
#include "../Player/Player.h"
#include "../Observer/Observer.h"


//real version of playGame
void  MainLoop::playGame(vector<FantasyRaceBanner>& raceBanners)
{

   int playerNum = numberOfPlayers;

    if(playerNum==2 || playerNum==3) {
        MainLoop::numberOfTurns = 10;
    }
    if(playerNum==4) {
        MainLoop::numberOfTurns = 9;
    }
    if(playerNum==5) {
        MainLoop::numberOfTurns = 8;
    }
    //current turn (first turn is done using firstConquer() )
    int turn = 2;

    //the number of turns left in the game
    while(turn<=numberOfTurns){
        cout<<"It is turn "<<turn<<endl;
        //gives each player a turn
        for(int j =1 ; j<= MainLoop::numberOfPlayers;++j) {
            cout<<"Player "<<j<<" :"<<endl;
            switch(j)
            {
                case 1: player1->playerTurn(raceBanners);break;
                case 2: player2->playerTurn(raceBanners);break;
                case 3: player3->playerTurn(raceBanners);break;
                case 4: player4->playerTurn(raceBanners);break;
                case 5: player5->playerTurn(raceBanners);break;

            }

        }
        ++turn;
    }
    cout<<"Game ends"<<endl;

}



//constructors
MainLoop::MainLoop(){};
MainLoop::MainLoop(Player *p1, Player *p2) {
    player1 = p1;
    player2 = p2;
    numberOfPlayers=2;
}

MainLoop::MainLoop(Player *p1, Player *p2, Player *p3) {
    player1 = p1;
    player2 = p2;
    player3 = p3;
    numberOfPlayers=3;
}

MainLoop::MainLoop(Player *p1, Player *p2, Player *p3, Player *p4) {
    player1 = p1;
    player2 = p2;
    player3 = p3;
    player4 = p4;
    numberOfPlayers=4;
}

MainLoop::MainLoop(Player *p1, Player *p2, Player *p3, Player *p4, Player *p5) {
    player1 = p1;
    player2 = p2;
    player3 = p3;
    player4 = p4;
    player5 = p5;
    numberOfPlayers=5;
}


