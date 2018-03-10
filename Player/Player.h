//
// Created by Miguel Jimenez on 2/4/18.
//

#ifndef SMALL_WORLD_PLAYER_H
#define SMALL_WORLD_PLAYER_H

#include "../Dice/Dice.h"
#include "../FantasyRaceBanner/FantasyRaceBanner.h"
#include "../GameTurn/GameTurn.h"
#include "../Map/Map.h"
#include "../SummarySheet/SummarySheet.h"
#include "../VictoryCoin/VictoryCoin.h"

#include <iostream>
#include <string>

using namespace std;

class Player {

public:
    // Constructors
    Player();
    explicit Player(Map& gameMap);
    Player(Map& gameMap, GameTurn& gameTurn);

    // Getters
    Dice getDice();
    FantasyRaceBanner getRaceBanner();
    SummarySheet getSummarySheet();
    vector<VictoryCoin>* getCoins();
    int getTotalCoinsValue();
    int getNonEmptyRegionsConqueredInTurn();

    // Setters
    void setNonEmptyRegionsConqueredInTurn(int newNonEmptyRegionsConqueredInTurn);

    // Other functions
    string toString();
    bool hasSummarySheet();
    void picks_race(vector<FantasyRaceBanner>& availableBanners);
    void firstConquer(Map*map);
    void redeploy(Map*map);
    void scores();

private:
    Map* map;
    GameTurn* turn;
    Dice dice;
    FantasyRaceBanner raceBanner;
    vector<int> regions;
    SummarySheet summarySheet;
    vector<VictoryCoin> coins;

    int nonEmptyRegionsConqueredInTurn;

    int giveBadgeCoins();
    int giveRaceCoins();
    void distributeCoins(int toBeAwarded);
    vector<int> getRegionsWithType(char type);

};

#endif //SMALL_WORLD_PLAYER_H
