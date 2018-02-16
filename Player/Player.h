//
// Created by Miguel Jimenez on 2/4/18.
//

#ifndef SMALL_WORLD_PLAYER_H
#define SMALL_WORLD_PLAYER_H

#include "../Dice/Dice.h"
#include "../FantasyRaceBanner/FantasyRaceBanner.h"
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

    // Getters
    Dice getDice();
    FantasyRaceBanner getRaceBanner();
    SummarySheet getSummarySheet();
    //vector<VictoryCoin> getCoins();

    // Setters
    void setCoins(int newValue);

    // Other functions
    string toString();
    int totalCoinsValue();
    bool hasSummarySheet();
    void picks_race();
    void conquers();
    void scores();

private:
    Dice dice;
    FantasyRaceBanner raceBanner;
    vector<int> regions;
    SummarySheet summarySheet;
    //vector<VictoryCoin> coins;
    VictoryCoin coins;

};

#endif //SMALL_WORLD_PLAYER_H
