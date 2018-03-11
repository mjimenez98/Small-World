//
// Created by Jean-Loup on 2018-03-09.
//

#include "MainLoop.h"

void  MainLoop::playGame()
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


