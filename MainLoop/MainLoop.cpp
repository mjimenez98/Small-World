//
// Created by Jean-Loup on 2018-03-09.
//

#include "MainLoop.h"
#include "../Player/Player.h"

//only used for demo
void  MainLoop::playGameTest()
{
    int playerNum;
    do {
        cout << "How many players will be playing?(2-5)" << endl;
        cin >>playerNum;

        if(playerNum<2||playerNum>5)
            cout<<"Invalid number of players"<<endl;

    }while(playerNum<2||playerNum>5);

    MainLoop::numberOfPlayers = playerNum;

    if(playerNum==2 || playerNum==3) {
        MainLoop::numberOfTurns = 10;
    }
    if(playerNum==4) {
        MainLoop::numberOfTurns = 9;
    }
    if(playerNum==5) {
        MainLoop::numberOfTurns = 8;
    }
    //current turn
    int turn = 1;

    //the number of turns left in the game
    while(turn<=numberOfTurns){
        cout<<"It is turn "<<turn<<endl;
        //gives each player a turn
        for(int j =1 ; j<= MainLoop::numberOfPlayers;++j) {
            if (turn == 1)
            {
                cout<<"Player "<< j << " picks race\n"<<
                    "Player "<< j<< " conquers\n"<<
                    "Player "<< j<< " scores victory coins\n"<<endl;
            } else{
                cout<<"Player "<< j << " plays"<<endl;
            }

        }
        ++turn;
    }
    cout<<"Game ends"<<endl;

}
//real version of playGame
void  MainLoop::playGame()
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
    //current turn
    int turn = 2;

    //the number of turns left in the game
    while(turn<=numberOfTurns){
        cout<<"It is turn "<<turn<<endl;
        //gives each player a
        for(int j =1 ; j<= MainLoop::numberOfPlayers;++j) {
            cout<<"Player "<<j<<" :"<<endl;
            switch(j)
            {
                case 1: player1->playerTurn();break;
                case 2: player2->playerTurn();break;
                case 3: player3->playerTurn();break;
                case 4: player4->playerTurn();break;
                case 5: player5->playerTurn();break;

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


