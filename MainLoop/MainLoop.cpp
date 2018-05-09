//
// Created by Jean-Loup on 2018-03-09.
//

#include "MainLoop.h"
#include "../Objects/Player/Player.h"
#include "../Patterns/Observer/Observer/Observer.h"

void MainLoop::playGame(vector<FantasyRaceBanner>& raceBanners) {

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

        cout << endl << "It is turn " <<turn << endl << endl;
        //gives each player a turn
        for(int j=1 ; j<=MainLoop::numberOfPlayers; ++j) {

            cout<<"Player "<<j<<":"<<endl;

            switch(j)
            {
                case 1: player1->playerTurn(raceBanners);break;
                case 2: player2->playerTurn(raceBanners);break;
                case 3: player3->playerTurn(raceBanners);break;
                case 4: player4->playerTurn(raceBanners);break;
                case 5: player5->playerTurn(raceBanners);break;
                default: break;

            }

        }
        ++turn;
    }
    declareWinner();
    cout<<"Game ends"<<endl;

}

void MainLoop::declareWinner() {

    Player winner;
    int winnerNum = -1;
    vector<Player> players;

    switch(numberOfPlayers) {

        case 2: {
            players.push_back(*player1);
            players.push_back(*player2);

            winner = *player1;
            winnerNum = 1;

            for (int j=0; j < 2; ++j) {

                if (players[j].getCoins() > winner.getCoins()) {
                    players[j] = winner;
                    winnerNum = j + 1;
                }

            }
            break;
        }

        case 3: {
            players.push_back(*player1);
            players.push_back(*player2);
            players.push_back(*player3);

            winner = *player1;
            winnerNum = 1;

            for (int j = 0; j < 3; ++j) {

                if (players[j].getCoins() > winner.getCoins()) {
                    players[j] = winner;
                    winnerNum = j + 1;
                }

            }
            break;
        }
        case 4: {
            players.push_back(*player1);
            players.push_back(*player2);
            players.push_back(*player3);
            players.push_back(*player4);

            winner = *player1;
            winnerNum = 1;

            for (int j = 0; j < 4; ++j) {

                if (players[j].getCoins() > winner.getCoins()) {
                    players[j] = winner;
                    winnerNum = j + 1;
                }

            }
            break;
        }
        case 5: {
            players.push_back(*player1);
            players.push_back(*player2);
            players.push_back(*player3);
            players.push_back(*player4);
            players.push_back(*player5);

            winner = *player1;
            winnerNum = 1;

            for (int j = 0; j < 5; ++j) {

                if (players[j].getCoins() > winner.getCoins()) {
                    players[j] = winner;
                    winnerNum = j + 1;
                }

            }
            break;
        }
        default: break;

    }

    for(int j =0; j<numberOfPlayers;++j)
        player1->getCoins();

    cout << "Player " << winnerNum << " wins" << endl;
}

void playFirstRound(Player* player, vector<FantasyRaceBanner>& raceBanners) {

    player->getObserver()->notifyPlayer(player->getPlayerID());
    player->picks_race(raceBanners);
    player->firstConquer();
    player->redeploy();
    player->scores();

}

// Constructors
MainLoop::MainLoop(Player *p1, Player *p2, vector<FantasyRaceBanner>& raceBanners) {

    player1 = p1;
    player2 = p2;
    numberOfPlayers=2;

    playFirstRound(player1, raceBanners);
    playFirstRound(player2, raceBanners);

}

MainLoop::MainLoop(Player *p1, Player *p2, Player *p3, vector<FantasyRaceBanner>& raceBanners) {

    player1 = p1;
    player2 = p2;
    player3 = p3;
    numberOfPlayers=3;

    playFirstRound(player1, raceBanners);
    playFirstRound(player2, raceBanners);
    playFirstRound(player3, raceBanners);

}

MainLoop::MainLoop(Player *p1, Player *p2, Player *p3, Player *p4, vector<FantasyRaceBanner>& raceBanners) {

    player1 = p1;
    player2 = p2;
    player3 = p3;
    player4 = p4;
    numberOfPlayers=4;

    playFirstRound(player1, raceBanners);
    playFirstRound(player2, raceBanners);
    playFirstRound(player3, raceBanners);
    playFirstRound(player4, raceBanners);

}

MainLoop::MainLoop(Player *p1, Player *p2, Player *p3, Player *p4, Player *p5, vector<FantasyRaceBanner>& raceBanners) {

    player1 = p1;
    player2 = p2;
    player3 = p3;
    player4 = p4;
    player5 = p5;
    numberOfPlayers=5;

    playFirstRound(player1, raceBanners);
    playFirstRound(player2, raceBanners);
    playFirstRound(player3, raceBanners);
    playFirstRound(player4, raceBanners);
    playFirstRound(player5, raceBanners);

}