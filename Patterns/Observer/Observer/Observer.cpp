//
// Created by Jean-Loup on 2018-03-20.
//

#include "Observer.h"

#include <iostream>

//total number of player's playing
int Observer::numberOfPlayers;

int Observer::playerNumber;

//total number of regions
int Observer::numberOfRegions;

//number of regions owned y each player;
int Observer::regions1;
int Observer::regions2;
int Observer::regions3;
int Observer::regions4;
int Observer::regions5;

vector<string> Observer::playerhands;
vector<int> Observer::playerCoins;

//print player's current action
void Observer::notifyAction(string action)
{
    cout << "\nPlayer " << playerNumber << " " << action << endl;
}

//notifies Observer which player's turn it is
void Observer::notifyPlayer(int playerNum)
{
    playerNumber = playerNum;
}

//tell Observer number of players playing ,then  sets number of regions
void Observer::notifyNumberOfPlayers(int numberOfPlayers)
{
    numberOfPlayers = numberOfPlayers;
    if(numberOfPlayers==2) { numberOfRegions = 23;}
    else if(numberOfPlayers==3) { numberOfRegions = 30;}
    else if(numberOfPlayers==4) { numberOfRegions = 39;}
    else if(numberOfPlayers==5) { numberOfRegions = 48;}

}

//notify when the Observer when a player's region number changes
void Observer::notifyRegionsOwned(int regionsOwned)
{
    switch(playerNumber)
    {
        case 1: regions1 = regionsOwned;break;
        case 2: regions2 = regionsOwned;break;
        case 3: regions3 = regionsOwned;break;
        case 4: regions4 = regionsOwned;break;
        case 5: regions5 = regionsOwned;break;
        default: break;
    }
}

void Observer::notifyHand(string hand)
{
    playerhands.push_back(hand);
}

void Observer::notifyCoins(int coins)
{
    playerCoins.push_back(coins);
}