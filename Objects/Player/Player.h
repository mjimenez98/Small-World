//
// Created by Miguel Jimenez on 2/4/18.
//

#ifndef SMALL_WORLD_PLAYER_H
#define SMALL_WORLD_PLAYER_H

#include "PlayerBehavior.h"

#include <iostream>
#include <string>
#include <random>

using namespace std;

class Player: public PlayerBehavior {

public:
    // Constructors
    Player();
    explicit Player(Map* gameMap);
    Player(Map& gameMap, GameTurn& gameTurn);

    // Getters
    Dice getDice();
    Observer* getObserver();
    FantasyRaceBanner getRaceBanner();
    vector<VictoryCoin>* getCoins();
    int getTotalCoinsValue();
    int getNonEmptyRegionsConqueredInTurn();
    void selectObserver();

    // Setters
    void setNonEmptyRegionsConqueredInTurn(int newNonEmptyRegionsConqueredInTurn);
    void setObserver(Observer* newObserver);

    // Other functions
    string toString();
    void picks_race(vector<FantasyRaceBanner>& availableBanners) override;
    void firstConquer() override;
    void conquer() override;
    void redeploy() override;
    void scores() override;
    void readyTroops() override;
    void abandonRegion();
    void playerTurn(vector<FantasyRaceBanner>& raceBanners) override;
    Observer* obs;

    //Determines if player wants the option to choose an Observer
    bool observerSelection = true;

protected:
    Map* map;
    GameTurn* turn;
    Dice dice;
    FantasyRaceBanner raceBanner;
    vector<int> regions;
    vector<VictoryCoin> coins;
    static vector<Player*> players;
    static int playerIdTracker;
    int playerId;
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
