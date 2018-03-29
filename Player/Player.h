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
    explicit Player(Map* gameMap);
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
    void firstConquer();
    void conquer();
    void redeploy();
    void scores();
    void readyTroops();
    void abandonRegion();
    void playerTurn(vector<FantasyRaceBanner>& raceBanners);

private:
    Map* map;
    GameTurn* turn;
    Dice dice;
    FantasyRaceBanner raceBanner;
    vector<int> regions;
    SummarySheet summarySheet;
    vector<VictoryCoin> coins;

    //TEMP
    bool selectNewRace;

    int nonEmptyRegionsConqueredInTurn;

    int giveBadgeCoins();
    int giveRaceCoins();
    int giveRaceCoins(string type);
    void distributeCoins(int toBeAwarded);
    void finalizeConquer(int regionSelection, int tokenSelection);
    void decline();
    vector<int> getRegionsWithType(char type);

};

#endif //SMALL_WORLD_PLAYER_H
